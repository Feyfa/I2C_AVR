/*
 * i2c.h
 *
 * Created: 11/12/2022 09.34.29
 *  Author: fisikamodern
 */ 


#ifndef I2C_H_
#define I2C_H_

#define SCL_CLOCK 100000

class i2c{
	private:
		uint8_t ADDRESS;
		void waitTWDRComplete();
		void init();
		void start();
		void address(uint8_t Address);
		void stop();
	public:	
		i2c(uint8_t Address); //for init
		void write(uint8_t port);
		uint8_t read();
		
};



#endif /* I2C_H_ */