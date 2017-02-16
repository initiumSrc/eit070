/*
 * main.c
 *
 *  Created on: 14 feb. 2017
 *      Author: dic14gsj
 */

/* Assignment 1. Identifying segment representation in memory
unsigned int *LED_1;
unsigned int value;
int i;

int main() {
	LED_1 = (unsigned int *) 0x44A00000;
	while (1 == 1) {
		value = 1;
		for (i = 1; i < 32; i++) {
			*LED_1 = value;
			value = value << 1;
		}
	}
}
*/

/* Assignment 3. Verify displayDigit
#include "displays.h"
unsigned char i;
int main() {
	while (1 == 1) {
		for (i = 0; i < 10; i++)
			displayDigitAtIndex(i % 8, i);
	}
}
*/

/* Assignment 5,6,7. Design number printing and clearing.
#include "displays.h"
int main() {
	while (1 == 1) {
		displayNumber(123456789);
		displayNumber(12345678);
		displayNumber(821);
		resetDisplayAtIndex(5);
		resetDisplays();
	}
}
*/

/* Assignment 8. Display number at an index
#include "displays.h"
int main() {
	while (1 == 1) {
		resetDisplays();
		displayNumberAtIndex(3, 821);
	}
}
*/

/* Assignment 9. Identify buttons in memory index.
#include "buttons.h"
unsigned int state;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;
	while (1 == 1) {
		state = *BUTTONS_DATA;
	}
}
*/

/* Assignment 11. Breh you need more state changes in your life
#include "buttons.h"
#include "displays.h"
unsigned int counter;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;
	counter = 0;
	while (1 == 1) {
		resetDisplays();
		displayNumber(counter);
		while (*BUTTONS_DATA == 0); // keep reading the data register
		if (*BUTTONS_DATA == UP)
			counter++;
		if (*BUTTONS_DATA == DOWN)
			counter--;
	}
}
*/

/* Assignment 12. State changes are cool but you shuld have that bouncing thing looked at by a proffesional
#include "buttons.h"
#include "displays.h"
unsigned int counter;
unsigned int buttons_state;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;
	counter = 0;
	while (1 == 1) {
		resetDisplays();
		displayNumber(counter);
		while (*BUTTONS_DATA == 0); // keep reading the data register
		buttons_state = *BUTTONS_DATA;
		if (buttons_state == UP)
			counter++;
		if (buttons_state == DOWN)
			counter--;
		while (*BUTTONS_DATA == buttons_state);
	}
}
*/

/* Assignemnt 13. The anti-bounce is weak in this one
#include "buttons.h"
#include "displays.h"
unsigned int counter;
unsigned int buttons_state;
unsigned int i;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;
	counter = 0;
	while (1 == 1) {
		resetDisplays();
		displayNumber(counter);
		while (*BUTTONS_DATA == 0)
			;
		for (i = 0; i < 20000; i++)
			;
		buttons_state = *BUTTONS_DATA;
		if (buttons_state == UP)
			counter++;
		if (buttons_state == DOWN)
			counter--;
		while (*BUTTONS_DATA == buttons_state)
			;
		for (i = 0; i < 20000; i++)
			;
	}
}
*/

/* Assignment 14. FILTER ALL THE THINGS
#include "buttons.h"
#include "displays.h"
unsigned int counter;
unsigned int buttons_state;
unsigned int previous_state;
unsigned int change;
unsigned int i;

int main() {

	*BUTTONS_CONTROL = 0xFFFFFFFF;
	counter = 0;
	buttons_state = 0;
	previous_state = 0;
	while (1 == 1) {
		resetDisplays();
		displayNumber(counter);
		while(*BUTTONS_DATA == buttons_state);
		for (i = 0; i < 20000; ++i);
		previous_state = buttons_state;
		buttons_state = *BUTTONS_DATA;

		change = buttons_state ^ previous_state;

		if(((change & UP) == UP) && ((buttons_state & UP) == UP)){
			counter++;
		}
		if(((change & DOWN) == DOWN) && ((buttons_state & DOWN) == DOWN)){
			counter--;
		}


//		while (*BUTTONS_DATA == 0);
//		for (i = 0; i < 20000; i++);
//		buttons_state = *BUTTONS_DATA;
//		if ((previous_state & UP) != (buttons_state & UP))
//			counter++;
//		if ((previous_state & DOWN) != (buttons_state & DOWN))
//			counter--;
//		while (*BUTTONS_DATA == buttons_state);
//		previous_state = *BUTTONS_DATA;
//		for (i = 0; i < 20000; i++);
	}
}
*/

/* Assignment 15. Added count constraints
#include "buttons.h"
#include "displays.h"

#define MAX_DISPLAY_NUM 99999999

unsigned int counter;
unsigned int buttons_state;
unsigned int i;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;
	counter = 0;
	while (1 == 1) {
		resetDisplays();
		displayNumber(counter);
		while (*BUTTONS_DATA == 0);
		for (i = 0; i < 20000; i++);
		buttons_state = *BUTTONS_DATA;
		if ((buttons_state & UP) == UP)
			if(counter < MAX_DISPLAY_NUM)
			counter++;
		if ((buttons_state & DOWN) == DOWN)
			if (counter > 0)
				counter--;
		while (*BUTTONS_DATA == buttons_state)
			;
		for (i = 0; i < 20000; i++)
			;
	}
}
*/

/* Assignment 16. Faster response gives a snappier UX
#include "buttons.h"
#include "displays.h"

#define MAX_DISPLAY_NUM 99999999

unsigned int counter;
unsigned int buttons_state;
unsigned int i;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;
	counter = 0;
	resetDisplays();
	displayNumber(counter);
	while (1 == 1) {
		while (*BUTTONS_DATA == 0);
		for (i = 0; i < 20000; i++);
		buttons_state = *BUTTONS_DATA;
		if ((buttons_state & UP) == UP)
			if(counter < MAX_DISPLAY_NUM)
			counter++;
		if ((buttons_state & DOWN) == DOWN)
			if (counter > 0)
				counter--;
		resetDisplays();
		displayNumber(counter);
		while (*BUTTONS_DATA == buttons_state);
		for (i = 0; i < 20000; i++);
	}
}
*/

#include "buttons.h"
#include "displays.h"

#define MAX_DISPLAY_NUM 99999999

unsigned int counter;
unsigned char index;
unsigned int buttons_state;
unsigned int previous_state;
unsigned int change;
unsigned int i;

int main() {
	*BUTTONS_CONTROL = 0xFFFFFFFF;

	counter = 0;
	index = 0;
	buttons_state=0;
	previous_state=0;

	resetDisplays();
	displayNumber(counter);

	while (1 == 1) {
		resetDisplays();
		displayNumberAtIndex(index, counter);

		while (*BUTTONS_DATA == buttons_state);
		for (i = 0; i < 20000; i++);
		previous_state = buttons_state;
		buttons_state = *BUTTONS_DATA;

		change = buttons_state ^ previous_state;

		if (((change & UP) == UP) && ((buttons_state & UP) == UP)) {
			if(index > 0){
				int kvot = 10;
				for(int i = 0; i < index-1; i++){
					kvot *= 10;
				}
				if(counter < MAX_DISPLAY_NUM/kvot) {
					counter++;
				}
			} else if (counter < MAX_DISPLAY_NUM)
				counter++;
		}

		if (((change & DOWN) == DOWN) && ((buttons_state & DOWN) == DOWN))
			if (counter > 0)
				counter--;

		if (((change & MIDDLE) == MIDDLE) && ((buttons_state & MIDDLE) == MIDDLE)) {
			index = 0;
			counter = 0;
		}

		if (((change & LEFT) == LEFT) && ((buttons_state & LEFT) == LEFT))
			if (index+numberOfDigits(counter)-1 < 7)
				index++;

		if (((change & RIGHT) == RIGHT) && ((buttons_state & RIGHT) == RIGHT))
			if (index > 0)
				index--;
	}
}
