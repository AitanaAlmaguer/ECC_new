/*=============================================================================
 Name        : Initialization.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
 =============================================================================*/
//============================ Includes =======================================
#include "Initialization.h"
//=========================== Variables =======================================
bool BitValue;
/*****************************************************************************
 ** Function name:		Init_System
 **
 ** Description:		Initialize uC Ports and Timer
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void Init_System() {
	SystemInit();
	SystemCoreClockUpdate();
	timerInit();
	GPIOInit();
}
/*****************************************************************************
 ** Function name:		Configure_Ports_Out
 **
 ** Description:		Set Ports as Outputs for I2C Emulation
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void Configure_Ports_Out() {
	GPIOSetDir(PORT1, 0, 1);	// SDA0
	GPIOSetDir(PORT1, 1, 1); 	// SCL0
	GPIOSetDir(PORT1, 2, 1);	// SDA1
	GPIOSetDir(PORT1, 3, 1);	// SCL1
	GPIOSetDir(PORT1, 4, 1);	// SDA2
	GPIOSetDir(PORT1, 5, 1);	// SCL2
	GPIOSetDir(PORT1, 6, 1);	// SDA3
	GPIOSetDir(PORT1, 8, 1);	// SCL3
}
/*****************************************************************************
 ** Function name:		Configure_Ports_In
 **
 ** Description:		Set Ports as Inputs for I2C Emulation
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void Configure_Ports_In() {
	GPIOSetDir(PORT1, 0, 0);	// SDA0
	GPIOSetDir(PORT1, 2, 0);	// SDA1
	GPIOSetDir(PORT1, 4, 0);	// SDA2
	GPIOSetDir(PORT1, 6, 0);	// SDA3
}
/*****************************************************************************
 ** Function name:		SCL_LOW
 **
 ** Description:		Set SCL Ports low
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void SCL_Low(void) {
	BitValue = 0;
	GPIOSetValue(PORT1, 1, BitValue);
	GPIOSetValue(PORT1, 3, BitValue);
	GPIOSetValue(PORT1, 5, BitValue);
	GPIOSetValue(PORT1, 8, BitValue);
}
/*****************************************************************************
 ** Function name:		SDA_LOW
 **
 ** Description:		Set SDA Ports low
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void SDA_Low(void) {
	BitValue = 0;
	GPIOSetValue(PORT1, 0, BitValue);
	GPIOSetValue(PORT1, 2, BitValue);
	GPIOSetValue(PORT1, 4, BitValue);
	GPIOSetValue(PORT1, 6, BitValue);
}
/*****************************************************************************
 ** Function name:		SCL_HIGH
 **
 ** Description:		Set SCL Ports high
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void SCL_High(void) {
	BitValue = 1;
	GPIOSetValue(PORT1, 1, BitValue);
	GPIOSetValue(PORT1, 3, BitValue);
	GPIOSetValue(PORT1, 5, BitValue);
	GPIOSetValue(PORT1, 8, BitValue);
}
/*****************************************************************************
 ** Function name:		SDA_HIGH
 **
 ** Description:		Set SDA Ports high
 **
 ** Parameters:			None
 ** Returned Value:		None
 *****************************************************************************/
void SDA_High(void) {
	BitValue = 1;
	GPIOSetValue(PORT1, 0, BitValue);
	GPIOSetValue(PORT1, 2, BitValue);
	GPIOSetValue(PORT1, 4, BitValue);
	GPIOSetValue(PORT1, 6, BitValue);
}

