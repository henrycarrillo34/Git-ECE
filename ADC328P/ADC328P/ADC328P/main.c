#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "LCD/LCD.h"
#include "MAX31865/MAX31865.h"


uint8_t datoRecibido = 0x00;
uint16_t data =0x00;
uint16_t resistance =0x00;
uint16_t temperatura =0x00;
int main(void)
{   DDRC = 0XFF;
	Lcd_Init();
	Lcd_Clear();
	//char s[10];
	//int y = 23;
	//sprintf(s,"%u", y);
	//Lcd_Set_Cursor(2,5);
	//Lcd_Write_String(s);
	_delay_ms(2000);
	while (1)
	{
		init_max31865 (0);
		check_MAX31865 (0);
		resistance = Read_MAX31865 (0,400);
		temperatura = calc_temp_pt100 (resistance);
		Lcd_Set_Cursor(1,1);
		
		Lcd_Write_String(temperatura);
	}


	_delay_ms(1000);
	
}