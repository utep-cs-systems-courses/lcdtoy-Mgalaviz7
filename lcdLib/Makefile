all: libLcd.a lcddemo.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h 
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
hour_glass.o: hour_glass.c hour_glass.h lcddraw.h lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf *~ *#

lcddemo.elf: lcddemo.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

##shape.elf: hour_glass.o libLcd.a
##	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

shape.elf: practice_shape.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer


load: shape.elf #lcddemo.elf
	msp430loader.sh $^
