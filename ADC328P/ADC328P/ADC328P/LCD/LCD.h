/*
 * LCD.h
 *
 * Created: 16/07/2020 4:25:p. m.
 *  Author: Lenovo
 */ 

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>

#define LCDPORT PORTC
#define RS PORTC5
#define EN PORTC4
#define D4 PORTC3
#define D5 PORTC2
#define D6 PORTC1
#define D7 PORTC0


void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear(void);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init(void);
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right(void);
void Lcd_Shift_Left(void);





#endif /* LCD_H_ */