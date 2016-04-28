/*
 * lcd_display.c - used to init the lcd and helper functions for writing data to the lcd
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */
/* GrLib Includes */
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"

/* Graphic library context */
Graphics_Context g_sContext;

//init lcd and leds
void init_lcd()
{
    //set up clocks for lcd
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);

}
//write what ever buffer is passed to this function to lcd
void write_lcd()
{
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                    "Project 4",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);

}
/* reverse:  reverse string s in place taken from KR C book*/
void reverse(int8_t s[], int length) {
    int i, j;
    char c;

    for (i = 0, j = length-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
//converts int to string and places in buffer taken from KR C book
void itoa(int n, int8_t s[]) {
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
}
//helper function to convert averages from adc and dataset to a string to display on lcd
void combine_ints_to_string(int x, int y, int z, int n, int8_t s[]) {

 int8_t x_buff[5] = "    ";
 itoa(x,x_buff);
 int8_t y_buff[5] = "    ";
 itoa(y,y_buff);
 int8_t z_buff[5] = "    ";
 itoa(z,z_buff);


 int index = 0;

 for(index = 0; index < 5; index++) {

   if(x_buff[index] != '\0') {
     s[index] = x_buff[index];
   } else {
     s[index] = ' ';
   }
 }
 for(index = 0; index < 5; index++) {

   if(y_buff[index] != '\0') {
     s[index+5] = y_buff[index];
   } else {
     s[index+5] = ' ';
   }
 }
 for(index = 0; index < 5; index++) {

   s[index+10] = z_buff[index];
 }
}
//converts string to int
int string_to_int(int8_t s[]) {

  int final = 0;

  int index = 3;

  int place = 1;
  while(s[index] == ' ') {
      index--;
  }

  while(index >= 0) {

      if( s[index] == '-') {

        final = 0 - final;
        break;
      }
      final = final + (s[index] - 48 ) * place;

      place = place * 10;  
      index--;
  }
  return final;
}
void backlight_on() {

  Graphics_clearDisplay(&g_sContext);
  P2OUT |= BIT6;//turn on red rgb
}
void backlight_off() {
  P2OUT &= ~BIT6;//turn off red rgb
}
