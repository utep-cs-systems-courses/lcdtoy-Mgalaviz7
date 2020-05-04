#include <msp430.h>
#include <stdlib.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_transition_assembly.h"
#include "lcdutils.h"
#include "lcddraw.h"

//#include "hour_glass.h"

int larger_flag = 0;
char speed = 125;

void draw_hour_glass ()
{

  int x,y;
  int x_axis = 65 ,  y_axis = 80;
  int hour_glass_size = 20;
  char time[1];
  char sec,min,time_flag,SWITCH_FLAG =0;
  
  time[0]='0';
  time[1]='0';
  // Outline of HourGlass
    for( y = 0; y <= hour_glass_size+5; y++)
      {
	for(x=0; x<y+8; x++)
	  { 
	    drawPixel(x+x_axis, y+y_axis-1, COLOR_BLACK); 
	    drawPixel(-x+x_axis-1, y+y_axis-1, COLOR_BLACK);
	    drawPixel(x+x_axis, -y+y_axis+1, COLOR_BLACK);//RED's OPPOSITE
	    drawPixel(-x+x_axis-1, -y+y_axis+1, COLOR_BLACK);//WHITE's OPPOSITE
	  }
      } 
    // Inside of HourGlass 
    for( y = 0; y <= hour_glass_size; y++)
      { 
	for(x=0; x<y; x++)
	  { 
	    drawPixel(x+x_axis, y+y_axis-1, COLOR_VIOLET);
	    drawPixel(-x+x_axis-1, y+y_axis-1, COLOR_VIOLET); 
	    drawPixel(x+x_axis, -y+y_axis+1, COLOR_VIOLET);//RED's OPPOSITE
	    drawPixel(-x+x_axis-1, -y+y_axis+1, COLOR_VIOLET);//WHITE's OPPOSITE
	  }
      }

  while (larger_flag)
    {
      drawString5x7(18,83,time,COLOR_GREEN,COLOR_BLUE);           
      if (hour_glass_size <= 50)
	{
	  hour_glass_size += 1;
	  time[1]='0'+sec;
	  time[0]='0'+min;
	  sec = sec +1;
	  if (sec == 10)
	    {
	      sec = 0;
	      min +=1; 
	    }
	} 
      // Outline of HourGlass
      for( y = 0; y <= hour_glass_size+5; y++)
	{
	  for(x=0; x<y+8; x++)
	    { 
	      drawPixel(x+x_axis, y+y_axis-1, COLOR_BLACK); 
	      drawPixel(-x+x_axis-1, y+y_axis-1, COLOR_BLACK);
	      drawPixel(x+x_axis, -y+y_axis+1, COLOR_BLACK);//RED's OPPOSITE
	      drawPixel(-x+x_axis-1, -y+y_axis+1, COLOR_BLACK);//WHITE's OPPOSITE
	    }
	} 
      // Inside of HourGlass 
      for ( y = 0; y <= hour_glass_size; y++)
	{ 
	  for (x=0; x<y; x++)
	    { 
	      drawPixel(x+x_axis, y+y_axis-1, COLOR_RED);
	      drawPixel(-x+x_axis-1, y+y_axis-1, COLOR_VIOLET); 
	      drawPixel(x+x_axis, -y+y_axis+1, COLOR_GREEN);//RED's OPPOSITE
	      drawPixel(-x+x_axis-1, -y+y_axis+1, COLOR_YELLOW);//WHITE's OPPOSITE
	    }
	}
    }//end of while loop
  
}


/*
  This method is always toggled and is used to keep the current state
  of the state machine. Each state changes due to the time a button is
  pushed and remains in that state till another button is pushed.
*/
void
states_transition()
{
  // states();    
  
  char state = CURRENT_STATE;
  
  switch (state)
    {
      /*STATE_0
	While in STATE_0 it will turn off everything. 
      */
    case 0:
      both_leds_off();
      draw_hour_glass();
      state = 0;
      break;      
      /* STATE_1
	 While in STATE_1 it will call the method count_to_3 
	 which will blink the leds in a numerical fashion.
      */
    case 1:
      green_led_on();
      high_note();
      draw_hour_glass();
      larger_flag=1;
      state = 1;
      break;
      
      /* STATE_2
	 While in STATE_2 it will set the dim led flag to true 
	 and will dim the lights as it counts to 3.
      */
    case 2:
      //      dim_flag = 1;
      //count_to_3();
      //state = 2;
      break;
      
      /* STATE_3
	 While in STATE_3 it will increase the speed at which 
	 leds a blinked an restarts the speed and processes once it reaches 
	 the fastes speed possible.
      */ 
    case 3:
      //      speed -= 1;
      //if (speed < 1)
      //	{
      //  speed = 125;
      //}
      //count_to_3();
      //state = 3;
      break;
      
      /* STATE_4
	 While in STATE_4 it will call the method little lamb 
	 which will play the melody.
      */
    case 4:
      //little_lamb();
      red_led_on();
      low_note();
      state = 4;
      break;
    }
}
