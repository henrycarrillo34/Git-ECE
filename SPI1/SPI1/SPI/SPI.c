 #include "SPI.h"
 
//SPI ATMEGA32A

//funcion que inicializa
void SPI_init()
{
	/*	Pines de la interface de comunicación
		PB5: MOSI (SALIDA)
		PB6: MISO (ENTRADA)
		PB7: CLK  (SALIDA)
	*/
	DDRB |=  (1<<DDB5)|(1<<DDB7);  
	DDRB &=~ (1<<DDB6);

	/*	Pin de control para esclavo (SS)
		PB4: Esclavo 
	*/
	DDRB |= (1<<DDB4); // SALIDA
	PORTB |= (1<<PORTB4); // EN ALTO para que el esclavo se puede comunicar al inicio

	/*	Orden de salida de los datos 
		DORD = 0, El bit más significativo (MSB) es enviado primero, tmb es por default
		DORD = 1, El bit menos significativo (LSB) es enviado primero
	*/
	SPCR &=~ (1<<DORD); //MSB

	/*  Configuración de polaridad y fase (Modo de comunicación)
		 CPOL |  CPHA  |                           MODO	
		------|--------|---------------------------------------------------------------
		  0	  |   0    |  Clock inactivo en bajo, detección de bits en flanco de subida
		  0	  |   1    |  Clock inactivo en bajo, detección de bits en flanco de bajada
		  1	  |   0    |  Clock inactivo en alto, detección de bits en flanco de bajada
		  1	  |   1    |  Clock inactivo en alto, detección de bits en flanco de subida			
	*/
	SPCR &=~ (1<<CPOL); //por defecto es 0 
	SPCR &=~ (1<<CPHA); //por defecto es 0  

	/*	Pre-escalador  (Divisor de Frecuencia) (la frecuencia que se van a comunicar)
		SPI2X | SPR1 | SPR0 | Pre-escalador
		------|------|------|----------------
		0     | 0	 |	0	|	4
		0	  | 0	 |	1	|	16
		0	  | 1	 |	0	|	64
		0	  | 1	 |	1	|	128
		1	  | 0	 |	0	|	2
		1	  | 0	 |	1	|	8
		1	  | 1	 |	0	|	32
		1	  | 1	 |	1	|	64
		
		F_CPU=16MHz -> F_SPI= F_CPU/16= 1MHz		 
	*/
	SPCR |=  (1<<SPR0);
	SPCR &=~ (1<<SPR1);
	SPSR &=~ (1<<SPI2X);

	/*	Modo de funcionamiento 
		MSTR = 0, SPI como esclavo
		MSTR = 1; SPI como maestro
	*/
	SPCR |= (1<<MSTR);

	/* Activar SPI 
		SPE = 0, SPI desactivado
		SPE = |, SPI activado
	*/
	SPCR |= (1<<SPE);
}
//función de prender el esclavo
void SPI_slaveON(uint8_t slave)
{
	switch (slave)
	{
		case 1:
		PORTB &=~ (1<<PORTB4); // (salida en 0)
		//recordar q cuando es 0 el esclavo se puede comunicar con maestr
		break;
	}
}
//FUNCION DE APAGAR EL ESCLAVO
void SPI_slaveOFF(uint8_t slave)
{
	switch (slave)
	{
		case 1:
		PORTB |= (1<<PORTB4); //SALIDA EN 1 
		//recordar q cuando es 1 el esclavo NO se puede comunicar con maestr
		break;
	
	}
}
//FUNCIÓN PARA TRANSMITIR
void SPI_tx(uint8_t data)
{
	/* Cargar dato al registro */
	SPDR = data;
	/* Esperar a que la transmisión se realice */
	while(!(SPSR & (1<<SPIF)));
	// dentro del while ( spif es 1, es decir que ya termino y sale del bucle)
}
//FUNCION PARA RECIBIR
uint8_t SPI_rx()
{
	/* Esperar a la recepción del dato */
	while(!(SPSR & (1<<SPIF)));   //cuando salga del while es decir que el registro ya está lleno y podemos leerlo
	/* Retorna el dato recibido */
	return SPDR;
}