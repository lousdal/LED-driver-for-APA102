/*
 * Day15 LED assignment.cpp
 *
 * Created: 02-11-2020 09:26:22
 * Author : olaur
 */ 

#define F_CPU 16000000UL

#include <util/delay.h>
#include "FlagImg.h"
#include "LousdalLED.h"

int main(void)
{
	LEDframe LED = LEDframe();
	
	LED.width = 8;
	LED.height = 8;
	
	LED.brightness = 1;			// from 1 to 31
	LED.initializeFrame();
	int delay_speed = 100;
	
    while (1) 
    {
		LED.showImg(&myIMG[0][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[1][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[2][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[3][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[4][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[5][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[6][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[7][0]);
		_delay_ms(delay_speed);
		LED.showImg(&myIMG[8][0]);
		_delay_ms(delay_speed);
    }
}