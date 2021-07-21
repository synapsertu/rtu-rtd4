all: rtu

rtu: 
	gcc rtu-rtd.c -o rtu-rtd -lmodbus -lm

clean:
	rm -rf *.o rtu-rtd
