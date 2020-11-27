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
#define DD_MISO    PINB4
#define DD_SCK     PINB5

/// This class lets you display images on a APA102 panel The images made in Img.h is made for 8x8 panels
class LEDframe	
{
	public:
	/// setting the width of the panel
	char width;
	/// setting the height of the panel
	char height;
	/// setting the brightness of the panel (lowest 1 - highest 31)
	char brightness;
	/// initializes the frame
	void initializeFrame(void);
	/// transmits bytes to the LED panel
	void transmitByte(unsigned char cData); 
	/// transmits the brightness and the bytes of red and green and blue
	void transmitRGB(unsigned char R, unsigned char G, unsigned char B); 
	/// displays the image from the Img(h that you point to. Remember to point to the start address of the image
	void showImg(unsigned char *img); 
	private:
	char nrLED;
	void startFrame(void);  
	void endFrame(void);		
};


#endif /* LOUSDALLED_H_ */