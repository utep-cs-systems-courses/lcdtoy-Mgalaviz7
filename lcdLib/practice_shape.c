#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"


int main(){
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  //  p2sw_init(15);
  or_sr(0x8);
  
  clearScreen(COLOR_BLUE);

 int x,y; 
 int x_axis = 65 ,  y_axis = 80; 
 int hour_glass_size = 20; 
 char time[1]; 
 char sec,min,time_flag,SWITCH_FLAG =0;
  
  time[0]='0';
  time[1]='0';
  drawString5x7(8,75, "TIMER:", COLOR_GREEN, COLOR_BLUE);
  
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
}//end of main

void hour_glass ()
{

  int x,y;
  int x_axis = 65 ,  y_axis = 80;
  int hour_glass_size = 20;
  char time[1];
  char sec,min,time_flag,SWITCH_FLAG =0;
  
  time[0]='0';
  time[1]='0';

  while (SWITCH_FLAG)
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
