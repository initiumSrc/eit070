/*
 * main.c
 *
 *  Created on: 6 feb. 2017
 *      Author: dic14gsj
 */

/* Initial exercise to understand signed variables

char b;

int main() {
	b=9;
	while(1==1){
		if(b<10){
			b--;
		}
	}
}
*/

/* Understanding difference of unsigned and signed char Assignment 1

unsigned char b;

int main() {
	b = 9;
	while (1 == 1) {
		if (b < 10) {
			b--;
		}
	}
}
*/

/* Understanding the signed int Assignment 2

int b;

int main() {
	b = 9;
	while (1 == 1) {
		if (b < 10) {
			b--;
		}
	}
}
*/

/* Understanding the unsigned int Assignment 3

unsigned int b;

int main() {
	b = 9;
	while (1 == 1) {
		if (b < 10) {
			b--;
		}
	}
}
*/

/* Understanding arrays Assignment 4

char b[10];

int main() {
	int i;
	while ( 1 == 1) {
		for (i = 0; i < 10; i++)
			b[i] = i;
	}
}
*/

/* Understanding int arrays Assignment 5

int b[10];

int main() {
	int i;
	while (1 == 1) {
		for (i = 0; i < 10; i++)
			b[i] = i;
	}
}
*/

/* Understanding pointers Assignment 6

char *address;
char b;

int main() {
	b = 0;
	address = &b;
	*address = 5;
	while (1 == 1) {
	}
}
*/

/* Understanding pointers Assignment 7

char *address;
int b;

int main() {
	b = 0xFFFFFFF;
	address = (char *) &b + 3;
	*address += 0xF0;
	while (1 == 1) {
	}
}
*/

/* Understanding I/O registers Assignment 8

#include "address_mapping.h"

unsigned int state;
unsigned int counter;

int main() {
	*SWITCHES_CONTROL = 0xFFFF;
	*LED_CONTROL = 0x0;
	counter = 10;
	while (1 == 1) {
		while (counter >= 0) {
			state = *SWITCHES_DATA;
			*LED_DATA = counter;
			counter--;
		}
	}
}
*/

/* Understanding write only memory Assignment 9

#include "address_mapping.h"
unsigned int state;

int main() {
	*SWITCHES_CONTROL = 0xFFFF;
	*LED_CONTROL = 0x0;
	*LED_DATA = 10;
	while (1 == 1) {
		while (*LED_DATA >= 0) {
			state = *SWITCHES_DATA;
			*LED_DATA = *LED_DATA - 1;
		}
	}
}
*/

/* Understanding read only memory Assignment 10

#include "address_mapping.h"
unsigned int state;

int main() {
	*SWITCHES_CONTROL = 0xFFFF;
	*LED_CONTROL = 0x0;
	*SWITCHES_DATA = 10;
	while (1 == 1) {
		while (*LED_DATA >= 0) {
			state = *SWITCHES_DATA;
			*LED_DATA = *LED_DATA - 1;
		}
	}
}
*/

/* Rewriting input as output Assignment 11

#include "address_mapping.h"

int main() {
	*SWITCHES_CONTROL = 0xFFFF;
	*LED_CONTROL = 0x0;
	while (1 == 1) {
		//*LED_DATA = (*SWITCHES_DATA << 1);
		*LED_DATA = *SWITCHES_DATA;
	}
}
*/

#include "address_mapping.h"

unsigned int num_leds;
unsigned int shifter;

extern unsigned int test();

int main() {
	*SWITCHES_CONTROL = 0xFFFF;
	*LED_CONTROL = 0x0;

	unsigned int asd = test();

	while (1 == 1) {
		num_leds = 0;

		for(char i = 0; i < 16; i++){
			shifter = 1;

			if((*SWITCHES_DATA & (shifter << i)) != 0){
				num_leds = num_leds << 1;
				num_leds++;
			}
		}

		*LED_DATA = num_leds;
	}
}
