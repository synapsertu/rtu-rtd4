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

void decodeRtuUnits()
{
	// Run through each enabled device
	for(int deviceId=1 ; deviceId<(config.dsTotal+1) ; deviceId++)
	{	
		// process and module type specific post-modbus read scaling/decoding steps
		switch (dataSource[deviceId].deviceType)
		{			
			default:
			case RTU_AI8: // [1] -  RTU-AI8
					// Nothing to do 
					break;
			case RTU_DI8: // [2] -  RTU-DI8
					// Nothing to do 
					break;
			case RTU_RTD4: // [3] -  RTU-DI8
					decodeRTD(deviceId);
					break;		
			case RTU_DO8:  // [4] -  RTU-DO8
					// Nothing to do 
					break;
			case RTU_AO4:  // [5] -  RTU-AO4
					// Nothing to do 
					break;						
					
		}	// Switch on device type
	} // loop on available devices
} // function