/*******************************************************************************
* Module 	  : Ultrasonic Sensor
* File Name   : ultrasonic.h
* Description : Header file for the Ultrasonic Sensor driver
* Author	  : Marwan Elsayed
* DATE		  : 13-10-2024
*******************************************************************************/

#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

#include "../LIB/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TRIGGER_PORT_ID			PORTD_ID
#define TRIGGER_PIN_ID			PIN7_ID

#define ECHO_PORT_ID			PORTD_ID
#define ECHO_PIN_ID				PIN6_ID

#define SOUND_SPEED_CM_S		34000
#define TRIGGER_DELAY			10

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Definition:
 * Function to initialize the ultrasonic configuration
 */
void ULTRASONIC_init(void);

/*
 * Description :
 * Function to send a signal to triger the ultrasonic sensor for sending it's wave
 * by sending a pulse for 10 us.
 */
void ULTRASONIC_triger(void);

/*
 * Description :
 * Function to calculate the distance based on the ultrasonic reads
 */
uint16 ULTRASONIC_readDistance(void);

void ULTRASONIC_edgeProcessing(void);
#endif /* HAL_ULTRASONIC_H_ */
