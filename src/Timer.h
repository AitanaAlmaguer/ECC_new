/*=============================================================================
 Name        : Timer.h
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
=============================================================================*/
#ifndef __TIMER_H
#define __TIMER_H
//============================ Includes =======================================
#include "LPC11xx.h"
#include "app.h"
#include <cr_section_macros.h>
//============================ Variables ======================================
extern int8_t main_go;
extern int8_t started;
extern volatile uint32_t ms_since_reset;
extern uint32_t LED;
extern uint32_t flag;
//================== Function Prototypes ======================================
void timerInit();

#endif
