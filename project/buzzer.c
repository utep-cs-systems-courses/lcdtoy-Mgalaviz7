#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

/* Frequencies for Notes */
#define _A 1760 
#define _G 3135
#define _F 2793
#define _C 2093
#define _D 1174
#define _E 1318

void
buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;

  P2DIR = BIT6;
}

void
buzzer_set_period(short cycles)
{
  TA0CCR0 = cycles;
  TA0CCR1 = cycles >> 5;
}
/*
  This method plays a high-ish pitched note
*/
void
high_note()
{
  buzzer_set_period(_C); //_C
  note_duration(1);
  buzzer_set_period(0);
  note_duration(1);
}
/*
  This method plays a low-ish pitched note
*/
void
low_note()
{
  buzzer_set_period(_F); //_F
  note_duration(1);
  buzzer_set_period(0);
  note_duration(1);
}

/*
  This method is essentialy the length of how long the buzzer should
  sound for a specfic frequencey at a time. The parameter rest is the length 
  at which the length will be played at. Side note the lengths of the notes 
  are not percies.
 */
void
note_duration(int rest){

  switch (rest)
    {
      //half note~
      case 1:
	__delay_cycles(16000000/2);
      break;

      //quater note~
      case 2:
	__delay_cycles(16000000/8);
      break;

      //whole note~
      case 3:
	__delay_cycles(16000000/1);
      break;

      //last Note~
      case 4:
	__delay_cycles(17000000);
      break;
  }
}
