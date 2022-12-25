/*
 * i2c.cpp
 *
 * Created: 11/12/2022 09.34.39
 *  Author: fisikamodern
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.hpp"

//private method
void i2c::waitTWDRComplete(){
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}
void i2c::init(){
	//scl clock = 100k hz
	TWSR = 0;// To determine the SCL frequency
	TWBR = ((F_CPU/SCL_CLOCK)-16)/2;// To determine the SCL frequency
}
void i2c::start(){
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}
void i2c::address(uint8_t Address){
	TWDR=Address;
	i2c::waitTWDRComplete();
}
void i2c::stop(){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}


//public method
i2c::i2c(uint8_t Address){
	i2c::ADDRESS = Address;
	i2c::init();
	i2c::start();
	i2c::address(i2c::ADDRESS);
}
void i2c::write(uint8_t port){
	TWDR=(port);
	i2c::waitTWDRComplete();
}
uint8_t i2c::read(){
	i2c::start();
	i2c::address(i2c::ADDRESS);
	i2c::waitTWDRComplete();
	return TWDR;
}

