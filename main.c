/*
* four_digit_7_segment_display.c
*
* Created: 11/19/2018 12:01:57 AM
* Author : conti
*/

#include "global.h"
#include <avr/io.h>
#include <util/delay.h>
#include "avrlibdefs.h"
#include "avrlibtypes.h"
#include "main.h"
#include "timer.h"
#include "segments.h"

int main(void){
	uint8_t s=0,m=0,h=0,zi=0;
/***************************************************************************************************************************************************/
	DDRD |= 0xC0;
	PORTD &= ~0xC0;
	DDRC |= 0x3F;
	PORTC &= ~0x3F;
/***************************************************************************************************************************************************/
	DDRB |= 0xFF;
	PORTB |= 0xFF;
/***************************************************************************************************************************************************/
	sei();
	timer_init();
	while(1){
		if(Start_timer_ON){
			s=0;m=0;h=0;zi=0;
			while(Start_timer_OF != TRUE){
				if(s>9){s=0;m++;}
				if(m>9){m=0;h++;}
				if(h>9){h=0;zi++;}
				if(zi>9){h=0;}
				while((timer_timeout(1) == 0)){set_digit(0);_delay_ms(1);set_digit(1);set_character(s);_delay_ms(1);
					set_digit(0);_delay_ms(1);set_digit(2);set_character(m);_delay_ms(1);
					set_digit(0);_delay_ms(1);set_digit(3);set_character(h);_delay_ms(1);
					set_digit(0);_delay_ms(1);set_digit(4);set_character(zi);_delay_ms(1);
				}timer_reset_tacts();
				s+=1;
			}
		}
		else {
			set_digit(0);_delay_ms(1);set_digit(1);set_character(0);_delay_ms(1);
			set_digit(0);_delay_ms(1);set_digit(2);set_character(0);_delay_ms(1);
			set_digit(0);_delay_ms(1);set_digit(3);set_character(0);_delay_ms(1);
			set_digit(0);_delay_ms(1);set_digit(4);set_character(0);_delay_ms(1);
		}
	}
}





