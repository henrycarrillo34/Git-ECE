#include <avr/io.h>
#include <util/delay.h>
#include "SPI/SPI.h"  //librería que hemos creado

uint8_t datoRecibido = 0x00;

int main(void)
{
    SPI_init();

    _delay_ms(10);
	
	SPI_slaveON(1);
	SPI_tx(0x01);
	datoRecibido = SPI_rx();
	SPI_tx(0x02);
	datoRecibido = SPI_rx();
	SPI_tx(0x03);
	datoRecibido = SPI_rx();
	SPI_tx(0x04);
	datoRecibido = SPI_rx();
	SPI_tx(0x05);
	datoRecibido = SPI_rx();
	
	
	
    while (1);
   
}

