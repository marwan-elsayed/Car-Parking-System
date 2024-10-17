/******************************************************************************
 * Module     : LED
 * File Name  : led.h
 * Description: Header file for the LED driver
 * Author	  : Marwan Elsayed
 * DATE		  : 8-10-2024
 ******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "../LIB/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* define the LED conection in hardware : postive or negative logic*/
#define NEGATIVE_LOGIC			0
#define POSITIVE_LOGIC			1
#define LEDS_CONNECTION			POSITIVE_LOGIC

#define RED_LED_PORT_ID			PORTC_ID
#define RED_LED_PIN_ID			PIN0_ID
#define GREEN_LED_PORT_ID		PORTC_ID
#define GREEN_LED_PIN_ID		PIN1_ID
#define BLUE_LED_PORT_ID		PORTC_ID
#define BLUE_LED_PIN_ID			PIN2_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum {
	RED_LED, GREEN_LED, BLUE_LED
} LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Definition:
 * Initializes all Leds' pins direction.
 * Turn off all the Leds
 */
void LEDS_init(void);

/*
 * Definition:
 * Turns on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Definition:
 * Turns off the specified LED.
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
