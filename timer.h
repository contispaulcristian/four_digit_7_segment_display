/*
 * timer.h
 *
 * Created: 11/21/2018 4:33:28 PM
 *  Author: conti
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_TACTS_PER_SECOND 61 //16MHz  ???

extern volatile uint32_t timer_tacts_passed;

/************************************************/
void timer_init(void);
/************************************************/
void timer_reset_tacts(void);
/************************************************/
char timer_timeout( uint32_t seconds );
/************************************************/
void timer_stop(void);
/************************************************/
#endif /* TIMER_H_ */