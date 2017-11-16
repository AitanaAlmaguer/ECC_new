/*=============================================================================
 Name        : Measurements.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
 =============================================================================*/

//============================ Includes =======================================
#include "Measurements.h"
#include "Initialization.h"
#include "math.h"
//=========================== Variables =======================================
float fDewpoint;
unsigned char ucHumidity, ucTemperature;
//============================= Functions =====================================
/*****************************************************************************
 ** Function name:		Start_Sequence
 **
 ** Description:		Generate transmission start
 ** 			_____ 		________
 ** DATA: 		    |_______|
 **			       ___    ___
 ** SCK : 	    __|  |___|  |______
 **
 ** Parameters:			None
 ** Returned value:		None
 *****************************************************************************/
void Start_Sequence() {
	SCL_Low();
	SDA_High();
	SCL_High();
	SDA_Low();
	SCL_Low();
	SCL_High();
	SDA_High();
	SCL_Low();
}
/*****************************************************************************
 ** Function name:		Get_Temperature
 **
 ** Description:		Sends bit sequence to start Temperature measurement.
 ** 					This takes 320ms to complete. The uC must wait for
 ** 					the Data Ready signal before restarting SCL to readout
 ** 					the data.
 **
 ** Parameters:			Sensor_Nr
 ** Returned value:		fTemperature
 *****************************************************************************/
char get_temperature() {
	int i, u;
	unsigned char ucTemperature_MSB;
	/* Measure Temp command  0x03 */
	SCL_Low();
	SCL_Low();
	SCL_Low();
	SCL_High();
	SCL_High();
	for (i = 0; i < 320; i++);
	if (!BitValue) {					// Wait for Data Ready signal
		Configure_Ports_In();			// Change Port direction
		for (u = 0x80; u > 0; u /= 2) {	// Read Most Significant Byte
			SCL_High();
			if (BitValue) {
				ucTemperature_MSB = (ucTemperature_MSB | u);
			}
			SCL_Low();
		}
		SDA_Low();						// Pull down Data line
		SCL_High();						// Acknowledge transmission
		SCL_Low();
		SDA_High();						// Release Data line
	}
	return ucTemperature_MSB;

}
/*****************************************************************************
 ** Function name:		Get_Humidity
 **
 ** Description:		Sends bit sequence to start Humidity measurement.
 ** 					This takes 320ms to complete. The uC must wait for
 ** 					the Data Ready signal before restarting SCL to readout
 ** 					the data.
 **
 ** Parameters:			Sensor_Nr
 ** Returned value:		ucHumidity
 *****************************************************************************/
char get_humidity() {
	int i, u;
	unsigned char ucHumidity_MSB;
	/* Measure  command  0x05 */
	SCL_Low();
	SCL_Low();
	SCL_High();
	SCL_Low();
	SCL_High();
	for (i = 0; i < 320; i++);			// Wait 320ms => measurement complete
	if (!BitValue) {					// Wait for Data Ready signal
		Configure_Ports_In();			// Change Port direction
		for (u = 0x80; i > 0; i /= 2) {	// Read Bit
			SCL_High();
			if (BitValue) {
				ucHumidity_MSB = (ucHumidity_MSB | u);
			}
			SCL_Low();
		}
		SDA_Low();						// Pull down Data line
		SCL_High();						// Acknowledge transmission
		SCL_Low();
		SDA_High();						// Release Data line
	}
	return ucHumidity_MSB;
}
/*****************************************************************************
 ** Function name:		Get_Dewpoint
 **
 ** Description:		Derive Dew Point from humidity and temperature values
 **
 ** Parameters:			fTemperature, fHumidity
 ** Returned value:		fDewpoint
 *****************************************************************************/
float get_dewpoint(float fTemperature, float fHumidity) {
	float k;
	k = (log10(fHumidity) - 2) / 0.4343
			+ (17.62 * fTemperature) / (243.12 + fTemperature);
	fDewpoint = 243.12 * k / (17.62 - k);
	return fDewpoint;
}
/*****************************************************************************
 ** Function name:		Store_Data
 **
 ** Description:
 **
 ** Parameters:			None
 ** Returned value:		None
 *****************************************************************************/
void Store_Data(void) {

}
