/*
 * lcd_display.h
 *
 *  Created on: Oct 27, 2020
 *      Author: johannes
 */

#ifndef INC_LCD_DISPLAY_H_
#define INC_LCD_DISPLAY_H_

#define LCD_RS GPIO_PIN_0
#define LCD_EN GPIO_PIN_1
#define LCD_PORT_DATA GPIOA
#define LCD_PORT_CTRL GPIOB
#define LCD_D_BIT_MASK 0xF0

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>

void lcd_init();

void lcd_clear();

void lcd_cmd(char);

void lcd_char(uint32_t);

void lcd_string(const char *);

void lcd_string_pos(char, const char *);

void lcd_custom_char(unsigned char, unsigned char *);

void lcd_time();

void lcd_default_custom_char();

#endif /* INC_LCD_DISPLAY_H_ */
