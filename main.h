/*
 * main.h
 *
 * Created: 11/22/2018 5:11:49 PM
 *  Author: conti
 */ 


#ifndef MAIN_H_
#define MAIN_H_
/********************************************************************************************************************************/
#define Start_timer_DDR                    DDRD
#define Start_timer_PORT                   PORTD
#define Start_timer_PIN                    PIND
/********************************************************************************************************************************/
#define Start_timer_BIT                    DDD4
/********************************************************************************************************************************/
#define	Start_timer_SETUP()	Start_timer_DDR &= ~( 1 << Start_timer_BIT ); Start_timer_PORT |= ( 1 << Start_timer_BIT );
#define	Start_timer_ON			((Start_timer_PIN & ( 1 << Start_timer_BIT )) != 0)
#define	Start_timer_OF			((Start_timer_PIN & ( 1 << Start_timer_BIT )) == 0)
/********************************************************************************************************************************/

#endif /* MAIN_H_ */