/*
 * Day15 LED assignment.cpp
 *
 * Created: 02-11-2020 09:26:22
 * Author : olaur
 */ 

#define F_CPU 16000000UL

#include <util/delay.h>
#include "Img.h"
#include "LousdalLED.h"

int main(void)
{
	_delay_ms(100);
	LEDframe LED = LEDframe();	// creates an instance of LEDframe
	
	LED.width = 8;	// setting the with of the panel
	LED.height = 8;	// setting the height of the panel
	
	LED.brightness = 1;	// can set brightness from 1 to 31
	LED.initializeFrame();	// initializes the frame
	_delay_ms(100);
	
    while (1) 
    {
		LED.showImg(&myIMG[0][0]); // shows the image with the given address in the array
		_delay_ms(1000);
		LED.showImg(&myIMG[3][0]);
		_delay_ms(1000);	
 		LED.showImg(&myIMG[1][0]);
		_delay_ms(1000);
// 		LED.showImg(&myIMG[4][0]);
// 		_delay_ms(1000);
// 		LED.showImg(&myIMG[5][0]);
// 		_delay_ms(1000);
// 		LED.showImg(&myIMG[6][0]);
// 		_delay_ms(1000);
// 		LED.showImg(&myIMG[7][0]);
// 		_delay_ms(1000);
// 		LED.showImg(&myIMG[8][0]);
// 		_delay_ms(1000);
	}
}