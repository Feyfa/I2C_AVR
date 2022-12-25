/*
 * I2C(READ) PCF8574 ATMEGA8A (C++).cpp
 *
 * Created: 25/12/2022 09.36.11
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
	DDRD = 0XFF;//set DDRD as output
	i2c i2c1 = i2c(65);//constructor to write the decimal address 65 to pcf8574 , 65 meaning as read
    
	while (1) 
    {
		PORTD = i2c1.read();//i2c1 reading results are entered into PORTD
    }
}

