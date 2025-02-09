/*
 * LousdalLED.cpp
 *
 * Created: 03-11-2020 11:40:51
 *  Author: olaur
 */ 

#include "LousdalLED.h"

void LEDframe::initializeFrame(void)
{
	/* Set MOSI(MasterInSerialOut) and SCK(SerialClock) output, all others input */
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS); // Important to set the SS as an output otherwise you will get noise on the SS (input)
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	nrLED = height*width;
}

void LEDframe::startFrame(void)		// in datasheet startframe is started by sending 32 bits of 0
{	
	transmitByte(0);   // transmit byte to slave
	transmitByte(0);
	transmitByte(0);
	transmitByte(0);
}

void LEDframe::endFrame(void)		// in datasheet endframe is ended by sending 32 bits of 1
{
	transmitByte(255);	// transmit byte to slave
	transmitByte(255);
	transmitByte(255);
	transmitByte(255);
}

void LEDframe::transmitByte(unsigned char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
		;
}

void LEDframe::transmitRGB(unsigned char R, unsigned char G, unsigned char B)
{
	transmitByte(224+brightness);	// Sets the brightness
	transmitByte(R);					
	transmitByte(G);
	transmitByte(B);
}

void LEDframe::showImg(unsigned char *img)
{
	startFrame();
	unsigned char *imgpointer = img;
	for (int i = 0; i < nrLED; i++)
	{
		transmitRGB(*imgpointer++, *imgpointer++, *imgpointer++);
	}
	endFrame();
}