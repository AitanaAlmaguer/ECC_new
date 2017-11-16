/*=============================================================================
 Name        : Initialization.h
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
=============================================================================*/
#ifndef __INITIALIZATION_H
#define __INITIALIZATION_H
typedef enum { false, true } bool;
//============================ Includes =======================================
#include "LPC11xx.h"
#include "app.h"
#include <cr_section_macros.h>
//=========================== Variables =======================================
extern bool BitValue;
//================== Function Prototypes ======================================
void Init_System(void);
void Configure_Ports_Out(void);
void Configure_Ports_In(void);
void SCL_High(void);
void SDA_High(void);
void SCL_Low(void);
void SDA_Low(void);

#endif
