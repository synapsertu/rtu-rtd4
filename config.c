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
*/
int readConfig()
{	
	int deviceId=1; // there's only one device configured in this tool
	int regId;
    
	//***************************************************************
	//********************** CONFIG *********************************
	//***************************************************************
	
	config.dsTotal=1; // there's only one device configured in this tool	

	//***************************************************************
	//********************** DATA SOURCES ***************************
	//***************************************************************	

   	dataSource[deviceId].deviceType  = RTU_RTD4;

    // These values will be overwrtten by cmd line options
	dataSource[deviceId].modbusId = 1;
	dataSource[deviceId].baudRate = 19200;
	dataSource[deviceId].dataBits = 8;		
	dataSource[deviceId].stopBit  = 1;
	dataSource[deviceId].timeout  = 5;
	strcpy(dataSource[deviceId].parity,"None");
	strcpy(dataSource[deviceId].interface, "/dev/ttyUSB0");
	
	
	dataSource[deviceId].ChanMode[1] = 0;  // 
	dataSource[deviceId].ChanMode[2] = 0; 
	dataSource[deviceId].ChanMode[3] = 0; 
	dataSource[deviceId].ChanMode[4] = 0; 
	dataSource[deviceId].ChanMode[5] = 0; 
	dataSource[deviceId].ChanMode[6] = 0; 
	dataSource[deviceId].ChanMode[7] = 0; 
	dataSource[deviceId].ChanMode[8] = 0; 

	
	// this MUST equal the total number of registered configured 
	dataSource[deviceId].numRegisters=16;


	//***************************************************************
	//********************** DATA POINTS ****************************
	//***************************************************************
	
	dataSource[deviceId].regAddress[1]  =9  ;	dataSource[deviceId].regType[1]	 =1  ;		// Channel 1 Live Raw Reading  
	dataSource[deviceId].regAddress[2]  =10 ;	dataSource[deviceId].regType[2]	 =1  ;		// Channel 2 Live Raw Reading 
	dataSource[deviceId].regAddress[3]  =11 ;	dataSource[deviceId].regType[3]	 =1  ;		// Channel 3 Live Raw Reading 
	dataSource[deviceId].regAddress[4]  =12 ;	dataSource[deviceId].regType[4]	 =1  ;		// Channel 4 Live Raw Reading 

	dataSource[deviceId].regAddress[5]  =13  ;	dataSource[deviceId].regType[5]	 =1  ;		// Channel 1 Average Reading 
	dataSource[deviceId].regAddress[6]  =14  ;	dataSource[deviceId].regType[6]	 =1  ;		// Channel 2 Average Reading 
	dataSource[deviceId].regAddress[7]  =15  ;	dataSource[deviceId].regType[7]	 =1  ;		// Channel 3 Average Reading 
	dataSource[deviceId].regAddress[8]  =16  ;	dataSource[deviceId].regType[8]	 =1  ;		// Channel 4 Average Reading 

	dataSource[deviceId].regAddress[9]  =17  ;	dataSource[deviceId].regType[9]	 =1  ;		// Channel 1 Peek Maximum
	dataSource[deviceId].regAddress[10] =18  ;	dataSource[deviceId].regType[10] =1  ;		// Channel 2 Peek Maximum 
	dataSource[deviceId].regAddress[11] =19  ;	dataSource[deviceId].regType[11] =1  ;		// Channel 3 Peek Maximum 
	dataSource[deviceId].regAddress[12] =20  ;	dataSource[deviceId].regType[12] =1  ;		// Channel 4 Peek Maximum 

	dataSource[deviceId].regAddress[13] =21  ;	dataSource[deviceId].regType[13] =1  ;		// Channel 1 Peek Minimum 
	dataSource[deviceId].regAddress[14] =22  ;	dataSource[deviceId].regType[14] =1  ;		// Channel 2 Peek Minimum 
	dataSource[deviceId].regAddress[15] =23  ;	dataSource[deviceId].regType[15] =1  ;		// Channel 3 Peek Minimum
	dataSource[deviceId].regAddress[16] =24  ;	dataSource[deviceId].regType[16] =1  ;		// Channel 4 Peek Minimum	

}

void printConfig()
{
	int deviceId;
	int regId;
	
	printf("--------- Config Imported ----------\n\n");
	
	for(deviceId=1 ; deviceId<(config.dsTotal+1) ; deviceId++)
	{	
	
		printf("dataSource [%i] deviceType  = [%i]  \n", deviceId, dataSource[deviceId].deviceType);
		printf("dataSource [%i] modbusId    = [%i]  \n", deviceId, dataSource[deviceId].modbusId);
		printf("dataSource [%i] interface   = [%s]  \n", deviceId, dataSource[deviceId].interface);
		printf("dataSource [%i] baudRate    = [%i]  \n", deviceId, dataSource[deviceId].baudRate);
		printf("dataSource [%i] dataBits    = [%i]  \n", deviceId, dataSource[deviceId].dataBits);
		printf("dataSource [%i] parity      = [%s]  \n", deviceId, dataSource[deviceId].parity);	
		printf("dataSource [%i] stopBit     = [%i]  \n", deviceId, dataSource[deviceId].stopBit);
		printf("dataSource [%i] timeout     = [%i]  \n", deviceId, dataSource[deviceId].timeout);
		printf("dataSource [%i] DataPoints  = [%i] \n",  deviceId, dataSource[deviceId].numRegisters);
		printf("dataSource [%i] Chan 1 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[1]);
		printf("dataSource [%i] Chan 2 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[2]);
		printf("dataSource [%i] Chan 3 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[3]);
		printf("dataSource [%i] Chan 4 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[4]);
		printf("dataSource [%i] Chan 5 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[5]);
		printf("dataSource [%i] Chan 6 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[6]);
		printf("dataSource [%i] Chan 7 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[7]);
		printf("dataSource [%i] Chan 8 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[8]);
		
		for(regId=1 ; regId<(dataSource[deviceId].numRegisters+1) ; regId++)
		{	
			printf("[%i]\tregAddress  = [%i]  regType     = [%i]    ",regId, dataSource[deviceId].regAddress[regId],dataSource[deviceId].regType[regId]);
			printf("\n");
		}		
	}

	printf("\n");
	printf("------------------------------------\n");
	printf("\n");	
}