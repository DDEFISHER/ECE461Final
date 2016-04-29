/*
 * lcd_display.h
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */

#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_

void init_lcd();
void write_lcd(int8_t s[]);
void reverse(char s[], int length);
void itoa(int n, char s[]);
void combine_ints_to_string(int x, int y, int z, int n, int8_t s[]);
int string_to_int(int8_t s[]);
void backlight_off();
void backlight_on();
void show_steps();
void menu1();
void menu2();
void menu3();
void menu4();
void set_goal_menu1();
void view_activity_menu();
void write_buff_to_lcd(int8_t buff[]);
void view_goal_menu();

#endif /* LCD_DISPLAY_H_ */
