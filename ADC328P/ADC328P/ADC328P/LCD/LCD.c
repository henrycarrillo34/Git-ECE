#include "LCD.h"
#include <util/delay.h>

void Lcd_Port(char a)
{
	if(a & 1)
	LCDPORT|=(1<<D4);
	//D4 = 1;
	else
	LCDPORT&=~(1<<D4);
	//D4 = 0;

	if(a & 2)
	LCDPORT|=(1<<D5);
	//D5 = 1;
	else
	LCDPORT&=~(1<<D5);
	//D5 = 0;

	if(a & 4)
	LCDPORT|=(1<<D6);
	//D6 = 1;
	else
	LCDPORT&=~(1<<D6);
	//D6 = 0;

	if(a & 8)
	LCDPORT|=(1<<D7);
	//D7 = 1;
	else
	LCDPORT&=~(1<<D7);
	//D7 = 0;
}
void Lcd_Cmd(char a)
{
	LCDPORT&=~(1<<RS);
	//RS = 0;
	Lcd_Port(a);
	LCDPORT|=(1<<EN);
	//EN  = 1;
	_delay_ms(4);
	LCDPORT&=~(1<<EN);
	//EN  = 0;
}

void Lcd_Clear(void)
{
	Lcd_Cmd(0);
	Lcd_Cmd(1);
}


void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
		temp = 0x80 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
}

void Lcd_Init(void)
{
	Lcd_Port(0x00);
	_delay_ms(20);
	Lcd_Cmd(0x03);
	_delay_ms(5);
	Lcd_Cmd(0x03);
	_delay_ms(11);
	Lcd_Cmd(0x03);
	Lcd_Cmd(0x02);
	Lcd_Cmd(0x02);
	Lcd_Cmd(0x08);
	Lcd_Cmd(0x00);
	Lcd_Cmd(0x0C);
	Lcd_Cmd(0x00);
	Lcd_Cmd(0x06);
}

void Lcd_Write_Char(char a)
{
	char temp,y;
	temp = a & 0x0F;
	y = a & 0xF0;
	LCDPORT|=(1<<RS);
	//RS = 1;
	Lcd_Port(y>>4);
	LCDPORT|=(1<<EN);
	//EN = 1;
	_delay_us(40);
	LCDPORT&=~(1<<EN);
	//EN = 0;
	Lcd_Port(temp);
	LCDPORT|=(1<<EN);
	//EN = 1;
	_delay_us(40);
	LCDPORT&=~(1<<EN);
	//EN = 0;
}

void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right(void)
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x0C);
}

void Lcd_Shift_Left(void)
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x08);
}
