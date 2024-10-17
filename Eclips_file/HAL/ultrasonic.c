/********************************************************
 * Module 	  	: Ultrasonic Sensor
 * File Name   	: ultrasonic.h
 * Description	: Source file for the  Ultrasonic Sensor driver
 * Author	  	: Marwan Elsayed
 * DATE		  	: 13-10-2024
 *********************************************************/

#include "ultrasonic.h"
#include "../MCAL/icu.h"
#include "../MCAL/gpio.h"
#include <util/delay.h>

#define PRESCALER		8

static volatile uint16 g_timer_ticks = 0;
static volatile uint8 g_edgeCount = 0;

void ULTRASONIC_edgeProcessing(void) {
  	if (g_edgeCount == 0) {
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
		g_edgeCount++;
	}

	else if (g_edgeCount == 1) {
		g_timer_ticks = ICU_getInputCaptureValue();
		//ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount = 0;
	}
}

/*
 * Definition:
 * Function to initialize the ultrasonic configuration
 */
void ULTRASONIC_init(void) {
	/* Setup Trigger pin as o/p pin */
	GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);

	/* Setup the ICU configurations */
	ICU_ConfigType configrations = { F_CPU_8, RAISING };
	ICU_init(&configrations);
	ICU_setCallBack(ULTRASONIC_edgeProcessing);
}

/*
 * Description :
 * Function to send a signal to trigger the ultrasonic sensor for sending it's wave
 * by sending a pulse for 10 us.
 *
 */
void ULTRASONIC_trigger(void) {
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(TRIGGER_DELAY);
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * Function to calculate the distance based on the ultrasonic reads
 */
uint16 ULTRASONIC_readDistance(void) {
	uint16 distance = 0;
	//uint16 time = 0;
	/* Trigger the ultasonic to send it's waves */
	ULTRASONIC_trigger();

	//time = (g_timer_ticks) / (F_CPU / PRESCALER);

	//distance = ((SOUND_SPEED_CM_S * time) / 2);

	distance =(float32) (g_timer_ticks / 117.6) ;

	return distance+1;
}

