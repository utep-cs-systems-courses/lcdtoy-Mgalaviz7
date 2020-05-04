#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT6    //p1.6
#define LED_GREEN BIT0  //p1.0

#define LEDS (BIT0 | BIT6)

void led_init();

void led_update();

void green_led_on();

void green_led_off();

void red_led_on();

void red_led_off();

void both_leds_on();

void both_leds_off();

#endif //include
