/*
        The MIT License (MIT)

        Copyright (c) 2021 Andrew O'Connell

        Permission is hereby granted, free of charge, to any person obtaining a copy
        of this software and associated documentation files (the "Software"), to deal
        in the Software without restriction, including without limitation the rights
        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
        copies of the Software, and to permit persons to whom the Software is
        furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included in all
        copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
        IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
        OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
        SOFTWARE.
		
	   Equations from pages 2 & 4 here :
       http://www.analog.com/media/en/technical-documentation/application-notes/AN709_0.pdf  
*/

void displayRtdValues(int deviceId, int displayType)
{
	// initialise these to zero or else we'll get nonsense readings
	// shown if the chan/register is not enabled in the config.
	// You could initialise this to NaN or some other recognisable value to indicate "No reading available"
	float chanLve[9] = {0.0};
	float chanMax[9] = {0.0};
	float chanMin[9] = {0.0};
	float chanAvg[9] = {0.0};

	int regId;

	for (regId = 1; regId < (dataSource[deviceId].numRegisters + 1); regId++)
	{
		// Deals with chan 1 value registers
		if (dataSource[deviceId].regAddress[regId] == 1) 	{ chanLve[1] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 9)	{ chanAvg[1] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 17)	{ chanMax[1] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 25)	{ chanMin[1] = dataSource[deviceId].value[regId]; }

		// Deals with chan 2 value registers
		if (dataSource[deviceId].regAddress[regId] == 3)	{ chanLve[2] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 11)	{ chanAvg[2] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 19)	{ chanMax[2] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 27)	{ chanMin[2] = dataSource[deviceId].value[regId]; }

		// Deals with chan 3 value registers
		if (dataSource[deviceId].regAddress[regId] == 5)	{ chanLve[3] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 13)	{ chanAvg[3] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 21)	{ chanMax[3] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 29)	{ chanMin[3] = dataSource[deviceId].value[regId]; }

		// Deals with chan 4 value registers
		if (dataSource[deviceId].regAddress[regId] == 7)	{ chanLve[4] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 15)	{ chanAvg[4] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 23)	{ chanMax[4] = dataSource[deviceId].value[regId]; }
		if (dataSource[deviceId].regAddress[regId] == 31)	{ chanMin[4] = dataSource[deviceId].value[regId]; }
	}

	// present the output in the format desired by the command line option
	if (displayType == HUMANREAD)
	{

		printf("_____| RTD4 Modbus Address %i |______________________________________________________________________\n", dataSource[deviceId].modbusId);
		printf("Ch\t\t\tLive\t\tMin\t\tAvg\t\tMax\n");
		printf("1\t\t\t%f\t%f\t%f\t%f\n", chanLve[1], chanMin[1], chanAvg[1], chanMax[1]);
		printf("2\t\t\t%f\t%f\t%f\t%f\n", chanLve[2], chanMin[2], chanAvg[2], chanMax[2]);
		printf("3\t\t\t%f\t%f\t%f\t%f\n", chanLve[3], chanMin[3], chanAvg[3], chanMax[3]);
		printf("4\t\t\t%f\t%f\t%f\t%f\n", chanLve[4], chanMin[4], chanAvg[4], chanMax[4]);
		printf("\n\n");
	}

	if (displayType == JSONREAD)
	{
		printf("      \"name\":\"RTU-RTD4\",\n");
		printf("      \"type\": %i,\n", dataSource[deviceId].deviceType);
		printf("      \"deviceId\":\"%i\",\n", deviceId);
		printf("      \"modbusId\":\"%i\",\n", dataSource[deviceId].modbusId);
		printf("      \"channels\": 4,\n");

		for (int chanNo = 1; chanNo < 5; chanNo++)
		{
			printf("      \"channel %i\": {\n", chanNo);
			printf("         \"live\": %f,\n", chanLve[chanNo]);
			printf("         \"min\": %f,\n", chanMin[chanNo]);
			printf("         \"avg\": %f,\n", chanAvg[chanNo]);
			printf("         \"max\": %f\n", chanMax[chanNo]);
			if (chanNo < 4)
			{
				printf("      },\n");
			}
			else
			{
				printf("      }\n");
			}
		}
	}

	if (displayType == CPUREAD)
	{

		//deviceId,deviceType,modbusId,chanLve[1],chanMin[1],chanAvg[1],chanMax[1].....chanLve[4],chanMin[4],chanAvg[4],chanMax[4]
		printf("%i,%i,%i,4,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f;\n",
			   deviceId, dataSource[deviceId].deviceType, dataSource[deviceId].modbusId,
			   chanLve[1], chanMin[1], chanAvg[1], chanMax[1],
			   chanLve[2], chanMin[2], chanAvg[2], chanMax[2],
			   chanLve[3], chanMin[3], chanAvg[3], chanMax[3],
			   chanLve[4], chanMin[4], chanAvg[4], chanMax[4]);
	}
}

float decodeRtdModbusReading(int modbusReading)
{
	const float RTD_A = 3.9083e-3;
	const float RTD_B = -5.775e-7;
	const float RTDnominal = 1000;	// PT1000
	const float refResistor = 4000; // PT1000

	float Z1, Z2, Z3, Z4, Rt, temp;

	Rt = modbusReading;
	Rt /= 32768;
	Rt *= refResistor;

	Z1 = -RTD_A;
	Z2 = RTD_A * RTD_A - (4 * RTD_B);
	Z3 = (4 * RTD_B) / RTDnominal;
	Z4 = 2 * RTD_B;

	temp = Z2 + (Z3 * Rt);
	temp = (sqrt(temp) + Z1) / Z4;

	// if temperature is >0degC then return calculated value
	if (temp >= 0)
		return temp;

	// else re-calculate more accurate value for sub zero temperatures using alternate fifth order polynomial expression
	Rt /= RTDnominal;

	Rt *= 100; // normalize to 100 ohm regardless of PT100/1000 type

	float rpoly = Rt;

	temp = -242.02;
	temp += 2.2228 * rpoly;
	rpoly *= Rt; // square
	temp += 2.5859e-3 * rpoly;
	rpoly *= Rt; // ^3
	temp -= 4.8260e-6 * rpoly;
	rpoly *= Rt; // ^4
	temp -= 2.8183e-8 * rpoly;
	rpoly *= Rt; // ^5
	temp += 1.5243e-10 * rpoly;

	// returns reading where temp <0degC
	return temp;
}

void decodeRTD(int deviceId)
{

	int regId;

	// Work our way through the list and diretly amend the values stored in
	// dataSource[deviceId].value[x]
	for (regId = 1; regId < (dataSource[deviceId].numRegisters + 1); regId++)
	{
			
		dataSource[deviceId].value[regId] = decodeRtdModbusReading((int)dataSource[deviceId].value[regId]);
		
	}
}

int reconfigureRTU(int deviceId, int modbusBaudSetting, int chanModeSetting[], int rtdAverageSetting, int chan50HzFiter, int LiveTempEnable)
{

	int rc;
	int regId;

	const char *filterMode[2];
	filterMode[0] = "60Hhz Filter Enabled";
	filterMode[1] = "50Hhz Filter Enabled";

	const char *LiveMode[2];
	LiveMode[0] = "Calculated Floats Enabled";
	LiveMode[1] = "Raw RTD Values Enabled";

	const char *avgMode[5];
	avgMode[1] = "4 Readings";
	avgMode[2] = "8 Readings";
	avgMode[3] = "16 Readings";
	avgMode[4] = "32 Readings";

	const char *rtdMode[5];
	rtdMode[0] = "2-Wire Mode";
	rtdMode[2] = "2-Wire Mode";
	rtdMode[3] = "3-Wire Mode";
	rtdMode[4] = "3-Wire Mode";

	const char *rtuBaud[6];
	rtuBaud[0] = "19200";
	rtuBaud[1] = "9600";
	rtuBaud[2] = "14400";
	rtuBaud[3] = "19200";
	rtuBaud[4] = "38400";
	rtuBaud[5] = "57600";

	uint16_t tableRegisters[1]; // 1 element array for use with modbus write command

	// modbus device handle
	modbus_t *mb;

	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30];

	printf("Processing Config Changes...\n");

	mb = modbus_new_rtu(dataSource[deviceId].interface,
						dataSource[deviceId].baudRate,
						dataSource[deviceId].parity[0],
						dataSource[deviceId].dataBits,
						dataSource[deviceId].stopBit);

	modbus_set_slave(mb, dataSource[deviceId].modbusId);

	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.
	// This could be useful if we've a latent RF-Link
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5 * 1000000));
	modbus_set_byte_timeout(mb, 5, (5 * 1000000));

	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	modbus_flush(mb);

	// check we can connect (not sure if this is relevant on serial modbus)
	if (modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId,
			   dataSource[deviceId].interface);
	   
		modbus_flush(mb);			   
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}
	
	modbus_flush(mb);

	//  50Hz/60Hz Filter  (1=60Hz/2=50Hz)
	if (chan50HzFiter > 0)
	{
		printf("Changing Mains filter mode to : %s\n", filterMode[(chan50HzFiter - 1)]);
		// Per-channel 50/60Hz Filter setting
		for (int i = 0; i < 4; i++)
		{
			tableRegisters[0] = (chan50HzFiter - 1);
			// remember that we need to -1 from the table in the PDF as modbus registers index from 0 
			rc = modbus_write_registers(mb, (36 + i), 1, tableRegisters);
			if (rc == -1)
			{
				printf("Modbus request Fail : Device Address [%i] Start Address [%i] For [1] Registers \n", deviceId, (36 + i));				
				modbus_flush(mb);
				modbus_close(mb);
				modbus_free(mb);
				exit(1);
			}
		}
	}

	// 2/3/4wire mode per-channel setting
	for (int i = 0; i < 4; i++)
	{

		if (chanModeSetting[i] > 0)
		{
			printf("Changing Chan %i mode to %s -- !! Change RTU Push On Link Configuration !!\n", i, rtdMode[chanModeSetting[i]]);
			tableRegisters[0] = chanModeSetting[i];
			// remember that we need to -1 from the table in the PDF as modbus registers index from 0 
			rc = modbus_write_registers(mb, (40 + i), 1, tableRegisters);
			if (rc == -1)
			{
				printf("Modbus request Fail : Device Address [%i] Start Address [%i] For [1] Registers \n", deviceId, (40 + i));
				
				modbus_flush(mb);
				modbus_close(mb);
				modbus_free(mb);
				exit(1);
			}
		}
	}

	// Select number of readings for rolling average (1=4|2=8|3=16|4=32)
	if (rtdAverageSetting > 0)
	{
		printf("Changing RTD  Averaging to : %s\n", avgMode[rtdAverageSetting]);
		tableRegisters[0] = rtdAverageSetting;
		// remember that we need to -1 from the table in the PDF as modbus registers index from 0 
		rc = modbus_write_registers(mb, 44, 1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [45] For [1] Registers \n", deviceId);
			
			modbus_flush(mb);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}
	}

	if (LiveTempEnable > 0)
	{
		printf("Changing  Raw/Calc Readings setting to : %s\n", LiveMode[(LiveTempEnable - 1)]);		
		tableRegisters[0] = (LiveTempEnable - 1);
		rc = modbus_write_registers(mb, 45, 1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [46] For [1] Registers \n", deviceId);
			
			modbus_flush(mb);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}
	}

	if (modbusBaudSetting > 0)
	{
		printf("Changing RTU Baud Rate to %s...\n", rtuBaud[modbusBaudSetting]);
		tableRegisters[0] = modbusBaudSetting;
		rc = modbus_write_registers(mb, 46, 1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [47] For [1] Registers \n", deviceId);
			modbus_flush(mb);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}
	}

	printf("Writing Config Register...\n");
	tableRegisters[0] = 255;
	rc = modbus_write_registers(mb, 47, 1, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [48] For [1] Registers \n", deviceId);
		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}

	return 0;
}

int getChanConfig(modbus_t *mb, int deviceId)
{

	// Nothing to do for RTU-RTD4
	return 0;
}


// Uses modbus_write_registers (FC16) to reset min readings to max value so current reading is always below it
int resetMinReadings(int deviceId) 
{  

	int rc;	
	int regId;


	// write 2147483647 to the min register to force a re-set of the counter
	uint16_t tableRegisters[8] = {32767,65535,32767,65535,32767,65535,32767,65535};


	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// you can use EITHER seconds OR microseconds, using BOTH will cause the command to be ignored.	
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, 0);
	modbus_set_byte_timeout(mb, 5, 0);

	modbus_flush(mb);

	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}
	
	modbus_flush(mb);
	
	printf("Resetting Min Counters...\r\n");
	// remember that we need to -1 from the table in the PDF as modbus registers index from 0 
	rc = modbus_write_registers(mb, 24,  16, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [25] For [8] Registers \n",deviceId);
		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}			

	modbus_flush(mb);
	modbus_close(mb);
	modbus_free(mb);	
	
	exit(0);

}


// Uses modbus_write_registers (FC16) to reset max readings to 0 so current values always exceeds it
int resetMaxReadings(int deviceId) 
{  

	int rc;	
	int regId;


	uint16_t tableRegisters[8] = {0,0,0,0,0,0,0,0}; 

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, 0);
	modbus_set_byte_timeout(mb, 5, 0);

	modbus_flush(mb);
	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}

	modbus_flush(mb);
	
	printf("Resetting Max Counters...\n\r");
	// remember that modbus registers index from 0 so address 40001 = 0th register
	rc = modbus_write_registers(mb, 16,  16, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [16] For [8] Registers \n",deviceId);

		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}			

	modbus_flush(mb);
	modbus_close(mb);
	modbus_free(mb);
	exit(0);
}
