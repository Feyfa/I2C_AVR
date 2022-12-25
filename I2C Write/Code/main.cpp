/*
 * I2C(WRITE) PCF8574 ATMEGA8A (C++).cpp
 *
 * Created: 25/12/2022 09.03.58
 * Author : fisikamodern
 */ 

// ADDRRES PCF8574
// A2|A1|A0|READ   |WRITE
// 0 |0 |0 |65/0x41|64/0x40
// 0 |0 |1 |67/0x43|66/0x42
// 0 |1 |0 |69/0x45|68/0x44
// 0 |1 |1 |71/0x47|70/0x46
// 1 |0 |0 |73/0x49|72/0x48
// 1 |0 |1 |75/0x4B|74/0x4A
// 1 |1 |0 |77/0x4D|76/0x4C
// 1 |1 |1 |79/0x4F|78/0x4E

#include <avr/io.h>
#include <util/delay.h>
#include "i2c.hpp"
#define F_CPU 8000000

int main(void)
{
	i2c i2c1 = i2c(64);//constructor to write the decimal address 64 to pcf8574 , 64 meaning as write
	
	while(1)
	{
		i2c1.write(1<<0);//write data (1<<0) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<1);//write data (1<<1) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<2);//write data (1<<2) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<3);//write data (1<<3) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<4);//write data (1<<4) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<5);//write data (1<<5) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<6);//write data (1<<6) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
		i2c1.write(1<<7);//write data (1<<7) to pcf8674
		_delay_ms(300);//pause 300 milliseconds
	}
}

