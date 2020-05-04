# makefile
COMMON_OBJECTS =
CPU 	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -Os -I ../h 
LDFLAGS	       = -L/opt/ti/msp430_gcc/include -L../lib

#switch the complier (for the internal make rules)
CC	       = msp430-elf-gcc
AS	       = msp430-elf-as
AR             = msp430-elf-ar



all: lab3.elf

#additional rules for files
lab3.elf: ${COMMON_OBJECTS}  lab3.o stateMachines.o switches.o buzzer.o led.o p2_interrupt_handler.o state_transition_assembly.o ../lib/libTimer.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd


load: lab3.elf
	msp430loader.sh $^
clean:
	rm -f *.o *.elf *~ *#
