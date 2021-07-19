all: rtu

rtu: 
	gcc rtu-rtd.c -o rtu-rtd -lsqlite3 -lmodbus -lm 

clean:
	rm -rf *.o rtu-rtd
