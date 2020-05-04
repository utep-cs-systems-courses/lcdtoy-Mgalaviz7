#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "lcdutils.h"
#include "lcddraw.h"

/*
  This is the main method where everything is inizalized
  and is ready for interuptes from switches.
 */
int
main(void)
{
  configureClocks(); /* Initialize Clock */

  lcd_init();

  clearScreen(COLOR_BLUE);
  
  switches_init(); /* Initialize Switches */

  buzzer_init(); /* Initialize Buzzer*/

  led_init(); /* Initialize Leds */

  enableWDTInterrupts(); /* Initialize Interrupts */

  or_sr(0x18);
}
 
