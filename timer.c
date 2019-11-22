/*
 * timer.c
 *
 * Created: 11/21/2018 4:32:54 PM
 *  Author: conti
 */ 

#include "global.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "avrlibdefs.h"
#include "avrlibtypes.h"
#include "main.h"
#include "timer.h"
#include "segments.h"

volatile uint32_t timer_tacts_passed;
/****************************************************************************************************************************/
void timer_init()
{
	timer_tacts_passed = 0;
	TCCR0B	|= (1 << CS02) | (1 << CS00);   //prescaler 1024
	TIFR0	|= ( 1<<TOV0 );
	TIMSK0	|= ( 1<<TOIE0 );
}
/****************************************************************************************************************************/
ISR(TIMER0_OVF_vect)
{
	timer_tacts_passed++;
	if (timer_tacts_passed == UINT32_MAX)
	{
		timer_tacts_passed = 0;
	}
}
/****************************************************************************************************************************/
void timer_reset_tacts()
{
	timer_tacts_passed = 0;
}
/****************************************************************************************************************************/
char timer_timeout( uint32_t seconds )
{
	if( (float)timer_tacts_passed / (float)TIMER_TACTS_PER_SECOND >= (float)seconds ) return 1;
	
	return 0;
}
/****************************************************************************************************************************/
void timer_stop()
{
	TCNT0 = 0x00;
	TIMSK0 &= ~(1 << TOIE0);
}
/****************************************************************************************************************************/