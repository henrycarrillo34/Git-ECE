#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "MAX31865/MAX31865.h"  //librería que hemos creado


uint16_t resistance =0x00;
uint16_t temperatura =0x00; 
int main(void)
{
	 DDRD = 0XFF;

	 //char s[10];
    /* Replace with your application code */
	_delay_ms(10);
    while (1) 
    {
		init_max31865 (0);
		check_MAX31865 (0);
		resistance = Read_MAX31865 (0,400);
		temperatura = calc_temp_pt100 (resistance);
		
    }
}

