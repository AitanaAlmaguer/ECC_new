/*=============================================================================
 Name        : Timer.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description :
=============================================================================*/
//============================ Includes =======================================
#include "Timer.h"
//=========================== Variables =======================================
int8_t main_go = 1; // execute main only when needed
int8_t started = 1; // execute main only when needed
volatile uint32_t ms_since_reset = 0;
static uint32_t main_counter;
/*****************************************************************************
** Function name:		TIMER16_0_IRQHandler
**
** Description:			Set to fire every 1ms
**
** Parameters:			None
** Returned value:		None
*****************************************************************************/
void TIMER16_0_IRQHandler(void)
{
	LPC_TMR16B0->IR = 1;			/* clear interrupt flag */
	ms_since_reset++;
    if (started){
		// give the main loop a go every "period" ms
		main_counter++;
		if (((main_counter % 100)) == 0)
		{
			main_go = 1;
		}
    }

}


void timerInit(){
	/* Timer16B0 */
		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);		/* Enable clock for 16-bit counter/timer 0 */
		LPC_TMR16B0->MCR = 3;						/* Interrupt and Reset on MR0 */
		LPC_TMR16B0->MR0 = SystemCoreClock/1000;	/* Interrupt and Reset on MR0 */
	    NVIC_EnableIRQ(TIMER_16_0_IRQn);			/* Enable the Timer0 Interrupt */
	    LPC_TMR16B0->TCR = 1;						/* Enable Timer0 */
		LPC_TMR16B0->IR = 1;						/* clear interrupt flag */
}
