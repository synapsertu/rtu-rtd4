# Synapse RTD-RTD4 Tool

 Dependancies :

```# apt-get install sqlite3 libsqlite3-dev libmodbus5 libmodbus-dev```

Compile as below or use 'make all'

```gcc log.c -o log -lsqlite3 -lmodbus -lm```

```
Synapse RTU-RTD4 Reader - v1.0

./rtu-rtd [-h|j|c] [-a] [-b] [-p] [-1] [-2] [-3] [-4] [-f] [-v] [-l] [-m] [-w] [-d]

Syntax :

-h = Human readable output (default)
-j = JSON readable output
-c = Comma delimited minimal output

-a = Set Modbus device address (1-255)  default=1
-b = Set serial baud rate (9600/14400/19200/38400/57600)  default=19200
-p = Set serial interface to use e.g. /dev/ttyS0  default=/dev/ttyUSB0

-1 = Set Channel 1 RTD Wire Mode register (2=2-Wire|3=3-Wire|4=4-Wire) - default=2-Wire
-2 = Set Channel 2 RTD Wire Mode register (2=2-Wire|3=3-Wire|4=4-Wire) - default=2-Wire
-3 = Set Channel 3 RTD Wire Mode register (2=2-Wire|3=3-Wire|4=4-Wire) - default=2-Wire
-4 = Set Channel 4 RTD Wire Mode register (2=2-Wire|3=3-Wire|4=4-Wire) - default=2-Wire

-f = All Channel 50Hz/60Hz Filter  (1=60Hz/2=50Hz)                     - default=60Hz
-v = Select number of readings for rolling average (1=4|2=8|3=16|4=32) - default=8 readings
-l = Enable Live Float Value Calculation  (1=Off|2=On)                 - default=Off

-m = Set value for RTU Baud Rate register (1=9600/2=14400/3=19200/4=38400/5=57600)

-w = Confirm writing configured setting registers to RTU NVRAM

-d = debug mode

Examples :
Read RTU, address 12, Baud 38400, output in JSON format   :  ./rtu-rtd -j -a 12 -b 38400 -p /dev/ttyS0
Reconfigure RTU rolling average to 16 readings            :  ./rtu-rtd -a 3 -v 3 -p /dev/ttyS0 -w

```
