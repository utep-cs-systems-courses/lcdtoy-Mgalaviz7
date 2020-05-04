#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"

/*
  This method is awating for a switch to be pressed 
  if there is one the method calls switch_interrupt_handler
  in switches.c to update the state.
*/
void
__interrupt_vec(PORT2_VECTOR) Port_2()
{
  if (P2IFG & SWITCHES)
    {
      P2IFG &= ~SWITCHES;
      switch_interrupt_handler();
    }
}
/*
  This method is costently being run and controls the 
  speed at which the lights blink in the state machien
  as well keep the current state until interrupted by a button.
*/
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static char blink_count =0;  
  if (++blink_count == speed)
    {
      states_transition();    
      blink_count=0;
    }
}
