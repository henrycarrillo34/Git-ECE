/*
 * MAX31865.h
 *
 * Created: 16/07/2020 4:25:p. m.
 *  Author: Lenovo
 */ 


#ifndef MAX31865_H_
#define MAX31865_H_
#include <avr/io.h>

#define SET_SPI_MOSI_OUTPUT    DDRB |=  (1<<PINB3)
#define SET_SPI_SCK_OUTPUT    DDRB |=  (1<<PINB5)
#define SET_SPI_SS_OUTPUT    DDRB |=  (1<<PINB2)
#define SET_SPI_MISO_INPUT    DDRB &=~ (1<<PINB4)

#define SET_MAX1_CS_OUTPUT    DDRB |=  (1<<PINB0)
#define SET_MAX1_DR_INPUT    DDRB &=~ (1<<PINB1)//PA0


#define SET_SPI_MOSI_HIGH    PORTB |=  (1<<PINB3)
#define SET_SPI_SCK_HIGH    PORTB |=  (1<<PINB5)
#define SET_SPI_SS_HIGH      PORTB |=  (1<<PINB2)
#define ENABLE_PULLUP_SPI_MISO  PORTB |=  (1<<PINB4)

#define SET_MAX1_CS_LOW      PORTB &=~  (1<<PINB2)
#define SET_MAX1_CS_HIGH    PORTB |=  (1<<PINB2)



#define READ_CONFIG            0x00
#define WRITE_CONFIG          0x80
#define READ_RTD_MSB          0x01
#define READ_RTD_LSB          0x02

#define READ_HIGH_FAULT_THRESHOLD_MSB  0x03
#define READ_HIGH_FAULT_THRESHOLD_LSB  0x04
#define READ_LOW_FAULT_THRESHOLD_MSB  0x05
#define READ_LOW_FAULT_THRESHOLD_LSB  0x06

#define WRITE_HIGH_FAULT_THRESHOLD_MSB  0x83
#define WRITE_HIGH_FAULT_THRESHOLD_LSB  0x84
#define WRITE_LOW_FAULT_THRESHOLD_MSB  0x85
#define WRITE_LOW_FAULT_THRESHOLD_LSB  0x86

#define READ_ERROR_STATE        0x07
#define DUMMYBYTE            0xFF




int8_t check_MAX31865(int8_t channel);

void init_max31865(int channel);
int16_t Read_MAX31865(int channel,int16_t referenz);
int16_t calc_temp_pt100(int16_t resistance);





#endif /* MAX31865_H_ */