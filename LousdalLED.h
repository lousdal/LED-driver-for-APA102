/*
 * LousdalLED.h
 *
 * Created: 03-11-2020 11:34:43
 *  Author: olaur
 */ 


#ifndef LOUSDALLED_H_
#define LOUSDALLED_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define DDR_SPI	   DDRB
#define DD_SS      PINB2
#define DD_MOSI    PINB3
#define DD_MISO    PINB4		// I don't use this one
#define DD_SCK     PINB5

class LEDframe
{
	public:
	char width;
	char height;
	char brightness;
	void initializeFrame(void);
	void transmitByte(unsigned char cData);
	void transmitRGB(unsigned char R, unsigned char G, unsigned char B);
	void showImg(unsigned char *img);
	private:
	char nrLED;
	void startFrame(void);  
	void endFrame(void);		
};


#endif /* LOUSDALLED_H_ */