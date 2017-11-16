/*=============================================================================
 Name        : Measurements.h
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
=============================================================================*/
#ifndef __MEASUREMENTS_H
#define __MEASUREMENTS_H
//============================ Includes =======================================
#include "LPC11xx.h"
#include "app.h"
#include <cr_section_macros.h>
//=========================== Variables =======================================
extern float fDewpoint;
extern unsigned char ucHumidity, ucTemperature;
//================== Function Prototypes ======================================
char get_temperature(void);
char get_humidity(void);
float get_dewpoint(float, float);
void Start_Sequence(void);
void Store_Data(void);

#endif
