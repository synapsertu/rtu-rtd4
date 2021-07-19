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
		
		int numRegisters;				//  Total number of registers enabled to scan fr
		int ChanMode[8];				//  Per-channell mode, this gives the channell setting or mode e.g.ADC this is the resolution setting for Digin this the channell mode 
		int regAddress[MAX_DATAPOINTS]; //  addess minus the 40000 multiier, total  max registers per device              	
		float value[MAX_DATAPOINTS];	// 	decoded (and then scaled) value for the register	
		
		
		
*/	

			

void displayDigInValues(int deviceId, int displayType)
{
	int regId;
	const char *chMode[4];
				chMode[0] = "Level";
				chMode[1] = "Level";
				chMode[2] = "Pulse";
				chMode[3] = "PWM";


	// initialise these to zero or else we'll get nonsense readings shown if the channell/register 
	// is not enabled in the config.
	// You could initialise this to NaN or some other recognisable value to indicate "No reading available" 
	int channellLvl[9]={0};      // Values from index position 1 onwards
    int channellCount[9]={0};
    int channellPWM[9]={0};
    int channellPWMAvg[9]={0};
	int channellPWMMax[9]={0};
	int channellPWMMin[9]={0};
	

	for(regId=1 ; regId<(dataSource[deviceId].numRegisters+1) ; regId++)
	{	
		// Deals with channell 1 value registers
		if ( dataSource[deviceId].regAddress[regId] == 1  ) { channellLvl[1]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 9  ) { channellCount[1] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 25 ) { channellPWM[1]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 41 ) { channellPWMAvg[1]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 57 ) { channellPWMMax[1]=dataSource[deviceId].value[regId]; }	  // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 73 ) { channellPWMMin[1]=dataSource[deviceId].value[regId]; }    // PWM Min Peek


		// Deals with channell 2 value registers
		if ( dataSource[deviceId].regAddress[regId] == 2  ) { channellLvl[2]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 11 ) { channellCount[2] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 27 ) { channellPWM[2]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 43 ) { channellPWMAvg[2]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 59 ) { channellPWMMax[2]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 75 ) { channellPWMMin[2]=dataSource[deviceId].value[regId]; }    // PWM Min Peek
		
		// Deals with channell 3 value registers
		if ( dataSource[deviceId].regAddress[regId] == 3  ) { channellLvl[3]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 13 ) { channellCount[3] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 29 ) { channellPWM[3]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 45 ) { channellPWMAvg[3]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 61 ) { channellPWMMax[3]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 77 ) { channellPWMMin[3]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with channell 4 value registers
		if ( dataSource[deviceId].regAddress[regId] == 4  ) { channellLvl[4]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 15 ) { channellCount[4] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 31 ) { channellPWM[4]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 47 ) { channellPWMAvg[4]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 63 ) { channellPWMMax[4]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 79 ) { channellPWMMin[4]=dataSource[deviceId].value[regId]; }    // PWM Min Peek
		
		// Deals with channell 5 value registers
		if ( dataSource[deviceId].regAddress[regId] == 5  ) { channellLvl[5]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 17 ) { channellCount[5] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 33 ) { channellPWM[5]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 49 ) { channellPWMAvg[5]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 65 ) { channellPWMMax[5]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 81 ) { channellPWMMin[5]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with channell 6 value registers
		if ( dataSource[deviceId].regAddress[regId] == 6  ) { channellLvl[6]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 19 ) { channellCount[6] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 35 ) { channellPWM[6]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 51 ) { channellPWMAvg[6]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 67 ) { channellPWMMax[6]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 83 ) { channellPWMMin[6]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with channell 7 value registers
		if ( dataSource[deviceId].regAddress[regId] == 7  ) { channellLvl[7]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 21 ) { channellCount[7] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 37 ) { channellPWM[7]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 53 ) { channellPWMAvg[7]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 69 ) { channellPWMMax[7]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 85 ) { channellPWMMin[7]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with channell 8 value registers
		if ( dataSource[deviceId].regAddress[regId] == 8  ) { channellLvl[8]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 23 ) { channellCount[8] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 39 ) { channellPWM[8]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 55 ) { channellPWMAvg[8]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 71 ) { channellPWMMax[8]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 87 ) { channellPWMMin[8]=dataSource[deviceId].value[regId]; }    // PWM Min Peek
	} 
	
	
	
	// present the output in the format desired by the command line option
	if (displayType == HUMANREAD)
	{			
		printf("_____| DI8 Modbus Address %i |______________________________________________________________________\n", dataSource[deviceId].modbusId);
		printf("Ch\tMode\tLevel\tCount\t\tPWM\t\tMin Pk\t\tAvg\t\tMax Pk\n");

       
        // see https://eecs.wsu.edu/~cs150/reading/printf.htm for futher information on printf formating 


        for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{		
            printf("1\t%s\t", chMode[dataSource[deviceId].ChanMode[chanNo]]);

            if (dataSource[deviceId].ChanMode[chanNo]  < 2 )      // Level 
                printf("%-8i%-16s%-16s%-16s%-16s%-16s",channellLvl[chanNo],"-","-","-","-","-"); 
            else if (dataSource[deviceId].ChanMode[chanNo] == 2 )  // Pulse Count
                printf("%-8s%-16i%-16s%-16s%-16s%-16s","-", channellCount[chanNo],"-","-","-","-"); 
            else if (dataSource[deviceId].ChanMode[chanNo] == 3 )  // PWM
                printf("%-8s%-16s%-16i%-16i%-16i%-16i","-","-",channellPWM[chanNo],channellPWMMin[chanNo],channellPWMAvg[chanNo],channellPWMMax[chanNo]); 

            printf("\n");
        }
        printf("\n");

	}	


	if (displayType == JSONREAD)
	{				
		printf ("      \"name\":\"RTU-DI8\",\n");
		printf ("      \"type\": %i,\n",dataSource[deviceId].deviceType);
		printf ("      \"deviceId\":\"%i\",\n",deviceId);
		printf ("      \"modbusId\":\"%i\",\n",dataSource[deviceId].modbusId);	        
		printf ("      \"channells\": 8,\n");

		for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{				
			printf ("      \"channell %i\": {\n",chanNo);
			printf ("         \"mode\": %i,\n",dataSource[deviceId].ChanMode[chanNo]);
            if (dataSource[deviceId].ChanMode[chanNo]  < 2 )                 
                printf ("         \"Level\": %i\n",channellLvl[chanNo]);
            else if (dataSource[deviceId].ChanMode[chanNo] == 2 )
                printf ("         \"Pulse Count\": %i\n",channellCount[chanNo]);
            else if (dataSource[deviceId].ChanMode[chanNo] == 3 ) 
            {
			    printf ("         \"PWM Live\": %i,\n",channellPWM[chanNo]);
			    printf ("         \"PWM min\": %i,\n",channellPWMMin[chanNo]);
			    printf ("         \"PWM avg\": %i,\n",channellPWMAvg[chanNo]);
			    printf ("         \"PWM max\": %i\n",channellPWMMax[chanNo]);
            }

			if (chanNo <8) { printf ("      },\n"); } else  { printf ("      }\n"); }			
		}
				
	}


	if (displayType == CPUREAD)
	{		

		//deviceId,deviceType,modbusId,ChansTotal,ChanMode[1], channellLvl[1], channellCount[1], channellPWM[1], channellPWMMin[1], channellPWMAvg[1], channellPWMMax[1]....ChansTotal,ChanMode[8], channellLvl[8], channellCount[8], channellPWM[8], channellPWMMin[8], channellPWMAvg[8], channellPWMMax[8] 
		printf("%i,%i,%i,8,",deviceId,dataSource[deviceId].deviceType,dataSource[deviceId].modbusId);
        
        for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{				
		        printf ("%i,", dataSource[deviceId].ChanMode[chanNo]);
                printf ("%i,%i,%i,%i,%i", channellLvl[chanNo], channellCount[chanNo], channellPWM[chanNo], channellPWMMin[chanNo], channellPWMAvg[chanNo], channellPWMMax[chanNo] );
                
		}
        printf(";\n");
	}

}


int reconfigureRTU(int deviceId, int modbusBaudSetting, int chanModeSetting[], int pwmAverageSetting, int debouncePeriod)
{  

	int rc;	
	int regId;
	
	const char *chMode[5];
				chMode[0] = "Logic Level";
				chMode[1] = "Logic Level";
				chMode[2] = "Pulse Counter";
				chMode[3] = "PWM Measurement";


	const char *pwmAvg[4];
				pwmAvg[0] = "8 Readings";
				pwmAvg[1] = "4 Readings";
				pwmAvg[2] = "8 Readings";


	const char *rtuBaud[5];
				rtuBaud[0] = "19200";
				rtuBaud[1] = "9600";
				rtuBaud[2] = "14400";
				rtuBaud[3] = "38400";
				rtuBaud[4] = "57600";



	uint16_t tableRegisters[1]; // 1 element array for use with modbus write command 

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	printf("Processing Config Changes...\n");	

	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	   modbus_set_slave( mb, dataSource[deviceId].modbusId );


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_close(mb); 
		modbus_free(mb);
		return -1;
	}


	// Due to the way modbus registers start at 1 and not 0, 64 = register address 65
	for (int i=1 ; i<9 ; i++)
	{
		 
		if (chanModeSetting[i] >0)  
		{  
			printf("Changing Chan %i mode to %s...\n",i,chMode[ chanModeSetting[i] ]);
			tableRegisters[0]=chanModeSetting[i];
			rc = modbus_write_registers(mb, (103+i) ,  1, tableRegisters);
			if (rc == -1)
			{
				printf("Modbus request Fail : Device Address [%i] Start Address [%i] For [1] Registers \n",deviceId,(103+i) );
				modbus_close(mb);
				modbus_free(mb);
				exit(1);
			}			
		}
	}

	if (pwmAverageSetting>0)	
	{	
		printf("Changing PWM Averaging to %s...\n",pwmAvg[pwmAverageSetting]);
		tableRegisters[0]=pwmAverageSetting;
		rc = modbus_write_registers(mb, 120,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [120] For [1] Registers \n",deviceId);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}			
	}

	if (debouncePeriod>0)	
	{	
		printf("Changing Pulse Count Debounce Setting %imS...\n", debouncePeriod);
		tableRegisters[0]=debouncePeriod;
		rc = modbus_write_registers(mb, 121,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [121] For [1] Registers \n",deviceId);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}			
	}

	if (modbusBaudSetting>0)	
	{	
		printf("Changing RTU Baud Rate to %s...\n",rtuBaud[modbusBaudSetting]);		
		tableRegisters[0]=modbusBaudSetting;
		rc = modbus_write_registers(mb, 122,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [123] For [1] Registers \n",deviceId);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}	
	}

    

	printf("Writing Config Register...\n");	
	tableRegisters[0]=255;
	rc = modbus_write_registers(mb, 123,  1, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [123] For [1] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	

	return 0;

}


int getChanConfig(modbus_t *mb, int deviceId)
{
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	int rc;	

	// Get DI8 specific channel config registers
	rc = modbus_read_registers(mb, 104, 8, mbdata_UI16);		
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [104] For [8] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	

	dataSource[deviceId].ChanMode[1] = mbdata_UI16[0];
	dataSource[deviceId].ChanMode[2] = mbdata_UI16[1];
	dataSource[deviceId].ChanMode[3] = mbdata_UI16[2];
	dataSource[deviceId].ChanMode[4] = mbdata_UI16[3];
	dataSource[deviceId].ChanMode[5] = mbdata_UI16[4];
	dataSource[deviceId].ChanMode[6] = mbdata_UI16[5];
	dataSource[deviceId].ChanMode[7] = mbdata_UI16[6];
	dataSource[deviceId].ChanMode[8] = mbdata_UI16[7];

	return 0;
}

