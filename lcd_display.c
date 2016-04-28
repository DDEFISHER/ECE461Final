/*
 * lcd_display.c - used to init the lcd and helper functions for writing data to the lcd
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */
/* GrLib Includes */
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"
#include "lcd_display.h"
#include <stdio.h>

/* Graphic library context */
Graphics_Context g_sContext;

int8_t step_string[15] = "               ";
extern int goal_steps;
extern int steps_taken;

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
void write_buff_to_lcd(int8_t buff[])
{
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     buff,
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);

}
void show_steps() {

    sprintf(step_string, "%d", steps_taken);
    Graphics_drawStringCentered(&g_sContext,
                                "                ",
                                AUTO_STRING_LENGTH,
                                64,
                                40,
                                OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                step_string,
                                AUTO_STRING_LENGTH,
                                64,
                                40,
                                OPAQUE_TEXT);
}
void backlight_on() {

  Graphics_clearDisplay(&g_sContext);
  P2OUT |= BIT6;//turn on red rgb
}
void backlight_off() {
  P2OUT &= ~BIT6;//turn off red rgb
}
void menu1()
{
    backlight_on();
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     "Deactivate",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activate",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Set goal",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "View activity level",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     40,
                                     OPAQUE_TEXT);
}
