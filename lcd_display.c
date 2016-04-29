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
                                     "Deactivate <-    ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activate         ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Set goal         ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activity level   ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     40,
                                     OPAQUE_TEXT);
}
void menu2()
{
    backlight_on();
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     "Deactivate       ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activate <-      ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Set goal         ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activity level   ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     40,
                                     OPAQUE_TEXT);
}
void menu3()
{
    backlight_on();
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     "Deactivate       ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activate         ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Set goal <-      ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activity level   ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     40,
                                     OPAQUE_TEXT);
}
void menu4()
{
    backlight_on();
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     "Deactivate       ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activate         ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Set goal         ",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Activity level <-",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     40,
                                     OPAQUE_TEXT);
}
void set_goal_menu1() {
    backlight_on();
    int8_t buffer[15] = "               ";
    sprintf(buffer, "%d", goal_steps);
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     "Set goal",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     buffer,
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
}
void view_activity_menu() {
    backlight_on();
    int8_t buffer1[15] = "               ";
    sprintf(buffer1, "%d", goal_steps);
    Graphics_clearDisplay(&g_sContext);
    int8_t buffer2[15] = "               ";
    sprintf(buffer2, "%d", steps_taken);
    int8_t buffer3[15] = "               ";
    sprintf(buffer3, "%d", (steps_taken*100)/goal_steps);
    Graphics_drawStringCentered(&g_sContext,
                                     "Step activity",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "taken / goal",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     buffer2,
                                     AUTO_STRING_LENGTH,
                                     24,
                                     40,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "/",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     40,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     buffer1,
                                     AUTO_STRING_LENGTH,
                                     94,
                                     40,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "percent",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     60,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     buffer3,
                                     AUTO_STRING_LENGTH,
                                     64,
                                     70,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "Exit <-",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     80,
                                     OPAQUE_TEXT);

}
void view_goal_menu() {
    backlight_on();
    int8_t buffer1[15] = "               ";
    sprintf(buffer1, "%d", goal_steps);
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                     "Goal met",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     10,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     buffer1,
                                     AUTO_STRING_LENGTH,
                                     64,
                                     20,
                                     OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext,
                                     "steps taken",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     30,
                                     OPAQUE_TEXT);
    TA0CCR0 = 410*3;                // Change PWM period to 3 times duty cycle
    TA0CCR4 = TA0CCR0 / 2;
    Delay(60);
    TA0CCR0 = 1;                // Change PWM period to 1 for no sound
    Delay(50);
    backlight_off();
}
