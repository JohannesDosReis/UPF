/*
 * lcd_display.c
 *
 *  Created on: Oct 27, 2020
 *      Author: johannes
 */

#include "lcd_display.h"

// Custom characters
unsigned char character1[8] = {0x02, 0x04, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00}; /* Value for á */
unsigned char character2[8] = {0x02, 0x04, 0x0E, 0x11, 0x1F, 0x10, 0x0E, 0x00}; /* Value for é */
unsigned char character3[8] = {0x00, 0x0F, 0x10, 0x10, 0x0F, 0x02, 0x0E, 0x00}; /* Value for ç */
unsigned char character4[8] = {0x0D, 0x12, 0x06, 0x01, 0x0F, 0x11, 0x0F, 0x00}; /* Value for ã */
unsigned char character5[8] = {0x0D, 0x12, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00}; /* Value for õ */

/**
 * @brief Tempo para dar o pulso
 *
 * @retval None
 */
void lcd_time() {
    // High-to-Low pulse on Enable pin to latch data
    HAL_GPIO_WritePin(LCD_PORT_CTRL, LCD_EN, 1); // => E = 1
    HAL_Delay(5);
    HAL_GPIO_WritePin(LCD_PORT_CTRL, LCD_EN, 0); // => E = 0
}

/**
 * @brief Initialize of the LCD display
 * Initialize in 4-bit mode, cursor off, shift cursor to right and clear the LCD screen
 *
 * @retval None
 */
void lcd_init() {
    HAL_Delay(15); /* 15ms,16x2 LCD Power on delay */
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK, 0);

    // uses 4 bits
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & 0x20, 1);
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (~0x20), 0);
    lcd_time();

    lcd_cmd(0x28); /* uses 2 line and initialize 5*7 matrix of LCD */
    lcd_cmd(0x0c); /* display on cursor off */
    lcd_cmd(0x06); /* increment cursor (shift cursor to right) */
    lcd_cmd(0x01); /* clear display screen */
}

/**
 * @brief Clear the LCD screen
 *
 * @retval None
 */
void lcd_clear() { lcd_cmd(0x01); /* clear display screen */ }

/**
 * @brief Send a command to the LCD
 *
 * @param cmd The command to be sent to the LCD
 * @retval None
 */
void lcd_cmd(char cmd) {
    HAL_GPIO_WritePin(LCD_PORT_CTRL, LCD_RS, 0); /* Command Register is selected */

    // Send data to PORT as a command for LCD
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & cmd, 1);
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (~cmd), 0);
    lcd_time();

    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (cmd << 4), 1);
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (~(cmd << 4)), 0);
    lcd_time();
}

/**
 * @brief Send data to LCD
 *
 * @param data The data to be sent to the LCD
 * @retval None
 */
void lcd_char(uint32_t data) {
    if ((data >> 8) == 0xC3) {
        switch (data & 0xFF) {
            case 0xA1: data = 0; break;
            case 0xA9: data = 1; break;
            case 0xA7: data = 2; break;
            case 0xA3: data = 3; break;
            case 0xB5: data = 4; break;
            default: break;
        }
    }

    HAL_GPIO_WritePin(LCD_PORT_CTRL, LCD_RS, 1); /* Data Register is selected */

    /* Send data to LCD */
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (data), 1);
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (~data), 0);
    lcd_time();

    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (data << 4), 1);
    HAL_GPIO_WritePin(LCD_PORT_DATA, LCD_D_BIT_MASK & (~(data << 4)), 0);
    lcd_time();
}

/**
 * @brief Send a string of data to the LCD
 *
 * @param msg The string to be sent to the LCD
 * @retval None
 */
void lcd_string(const char *msg) {
    while ((*msg) != 0) {
        if (*msg == 0xC3) {
            switch (*(++msg)) {
                case 0xA1: lcd_char(0); break;
                case 0xA9: lcd_char(1); break;
                case 0xA7: lcd_char(2); break;
                case 0xA3: lcd_char(3); break;
                case 0xB5: lcd_char(4); break;
                default: continue;
            }
        } else {
            lcd_char(*msg);
        }
        msg++;
    }
}

/**
 * @brief Send a string of data to the LCD on a specified position
 *
 * @param pos The position on the LCD where the string should be displayed
 * @param msg
 * @retval None
 */
void lcd_string_pos(char pos, const char *msg) {
    lcd_cmd(pos);
    lcd_string(msg);
}

/**
 * @brief Set a custom character on the LCD
 *
 * @param loc The location of the character should be set [0 - 8]
 * @param msg The character to set
 * @retval None
 */
void lcd_custom_char(unsigned char loc, unsigned char *msg) {
    unsigned char i;
    if (loc < 8) {
        lcd_cmd(0x40 +
                (loc * 8)); /* Command 0x40 and onwards forces the device to point CGRAM address */
        for (i = 0; i < 8; i++) /* Write 8 byte for generation of 1 character */
            lcd_char(msg[i]);
    }
}

/**
 * @brief Load the default custom characters
 *
 * @retval None
 */
void lcd_default_custom_char() {
    lcd_custom_char(0, character1); /* Write custom character to CGRAM 0x00 memory location */
    lcd_custom_char(1, character2); /* Write custom character to CGRAM 0x01 memory location */
    lcd_custom_char(2, character3); /* Write custom character to CGRAM 0x02 memory location */
    lcd_custom_char(3, character4); /* Write custom character to CGRAM 0x03 memory location */
    lcd_custom_char(4, character5); /* Write custom character to CGRAM 0x04 memory location */
}
