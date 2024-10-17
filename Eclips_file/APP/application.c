/*
 * application.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Marwan Elsayed
 */

#include "../HAL/led.h"
#include "../HAL/buzzer.h"
#include "../HAL/lcd.h"
#include "../HAL/ultrasonic.h"
#include <util/delay.h>
#include <avr/interrupt.h>

int main() {
	uint16 distance = ULTRASONIC_readDistance();

	LEDS_init(); /*Initializing leds*/
	BUZZER_init();
	LCD_init();
	ULTRASONIC_init();

	sei();

	LCD_displayStringRowColumn(LCD_FIRST_ROW, 1, "Distance=");

	for (;;) {
		distance = ULTRASONIC_readDistance();
		LCD_moveCursor(LCD_FIRST_ROW, 10);
		LCD_intgerToString(distance);

		if (distance > 100) {
			/* Do Noting */
		} else if (distance < 100 && distance > 10) {
			LCD_displayCharacter(' ');
		} else if (distance < 10) {
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(LCD_FIRST_ROW, 13);
		LCD_displayString("cm");

		if (distance <= 5) {
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			BUZZER_on();
			_delay_ms(200);
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			BUZZER_off();
			_delay_ms(200);

			LCD_displayStringRowColumn(LCD_SECOND_ROW, 6, "STOP");
		} else if (distance > 5 && distance <= 10) {
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);

			BUZZER_off();

			LCD_displayStringRowColumn(LCD_SECOND_ROW, 6, "                ");
		} else if (distance > 10 && distance <= 15) {
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);

			BUZZER_off();

			LCD_displayStringRowColumn(LCD_SECOND_ROW, 6, "                ");
		} else if (distance > 15 && distance <= 20) {
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

			BUZZER_off();

			LCD_displayStringRowColumn(LCD_SECOND_ROW, 6, "                ");
		} else if (distance > 20) {
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

			BUZZER_off();

			LCD_displayStringRowColumn(LCD_SECOND_ROW, 6, "                ");
		}
	}
}
