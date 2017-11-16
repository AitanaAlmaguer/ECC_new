/*=============================================================================
 Name        : APP.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
 =============================================================================*/
//============================ Defines ========================================
#define INIT 0
#define TEMPERATURE 1
#define HUMIDITY 2
#define STORE 3
#define IDLE 4
//============================ Includes =======================================
#ifdef __USE_CMSIS
#include "LPC11xx.h"
#include "app.h"
#include "Timer.h"
#include "Initialization.h"
#include "Measurements.h"
#include <cr_section_macros.h>
#include <math.h>
#endif
//============================ Variables ======================================
int iState = 0, iFinish = 0, iTemOrHR;

int main(void) {

	Init_System();
	Configure_Ports_Out();
	while (1) {
		if (ms_since_reset >= 11) {	// After Power-Up the sensor needs 11ms to
									// get to sleep state, no commands must be
									// sent before that time
			switch (iState) {

			case INIT:
				Start_Sequence();
				iState = TEMPERATURE;
				break;

			case TEMPERATURE:
				get_temperature();
				iTemOrHR = 1;
				iState = STORE;
				break;

			case HUMIDITY:
				get_humidity();
				iTemOrHR = 0;
				iFinish = 1;
				iState = STORE;
				break;

			case STORE:
				Store_Data();
				if (iFinish) {
					iState = INIT;
					iFinish = 0;
				} else {
					if (iTemOrHR) {
						iState = HUMIDITY;
					} else {
						iState = TEMPERATURE;
					}
				}
				break;

			case IDLE:
				__WFI();
				break;
			}

		}
		while (!main_go) {
			__WFI();
		}
		main_go = 0;
	}

	return 0;
}

