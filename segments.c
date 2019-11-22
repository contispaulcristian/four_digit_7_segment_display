/*
* segments.c
*
* Created: 11/20/2018 9:31:10 PM
*  Author: conti
*/


#include "global.h"
#include <avr/io.h>
#include <util/delay.h>
#include "avrlibdefs.h"
#include "avrlibtypes.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "main.h"
#include "timer.h"
#include "segments.h"

/***************************************************************************************************************************************************/
void set_segment(char x){
	/****Hexadecimal***********************************************************Binary****/
	if ((x & 0x01) == 0x01) SEGMENTS_1_PORT|=(1<<SEGMENT_ONE_BIT);            // 0000 0001                     
	else SEGMENTS_1_PORT&=~(1<<SEGMENT_ONE_BIT);
	if ((x & 0x02) == 0x02) SEGMENTS_1_PORT|=(1<<SEGMENT_TWO_BIT);            // 0000 0010
	else SEGMENTS_1_PORT&=~(1<<SEGMENT_TWO_BIT);
	if ((x & 0x04) == 0x04) SEGMENTS_1_PORT|=(1<<DOT_BIT);                    // 0000 0100
	else SEGMENTS_1_PORT&=~(1<<DOT_BIT);
	if ((x & 0x08) == 0x08) SEGMENTS_1_PORT|=(1<<SEGMENT_FOUR_BIT);           // 0000 1000
	else SEGMENTS_1_PORT&=~(1<<SEGMENT_FOUR_BIT);
	if ((x & 0x10) == 0x10) SEGMENTS_1_PORT|=(1<<SEGMENT_FIVE_BIT);           // 0001 0000
	else SEGMENTS_1_PORT&=~(1<<SEGMENT_FIVE_BIT);
	if ((x & 0x20) == 0x20) SEGMENTS_1_PORT|=(1<<SEGMENT_SEVEN_BIT);          // 0010 0000
	else SEGMENTS_1_PORT&=~(1<<SEGMENT_SEVEN_BIT);
	if ((x & 0x40) == 0x40) SEGMENTS_2_PORT|=(1<<SEGMENT_TEN_BIT);            // 0100 0000
	else SEGMENTS_2_PORT&=~(1<<SEGMENT_TEN_BIT);
	if ((x & 0x80) == 0x80) SEGMENTS_2_PORT|=(1<<SEGMENT_ELEVEN_BIT);         // 1000 0000
    else SEGMENTS_2_PORT&=~(1<<SEGMENT_ELEVEN_BIT);}
/***************************************************************************************************************************************************/

void set_character(char x){
	switch(x){
		/*****************Hexadecimal****************************************Binary****/
		case 0:  set_segment(0xEF);break;                                   // 1110 1111 for character "0"
		case 1:  set_segment(0x2C);break;                                   // 0010 1100 for character "1"
		case 2:  set_segment(0xB7);break;                                   // 1011 0111 for character "2"
		case 3:  set_segment(0xBE);break;                                   // 1011 1110 for character "3"
		case 4:  set_segment(0x7C);break;                                   // 0111 1100 for character "4"
		case 5:  set_segment(0xDE);break;                                   // 1101 1110 for character "5"
		case 6:  set_segment(0xDF);break;                                   // 1101 1111 for character "6"
		case 7:  set_segment(0xAC);break;                                   // 1010 1100 for character "7"
		case 8:  set_segment(0xFF);break;                                   // 1111 1111 for character "8"
		case 9:  set_segment(0xFE);break;                                   // 1111 1110 for character "9"
		
	}
}
/***************************************************************************************************************************************************/
void set_digit(char x){
	switch(x){
		/**********************************************SET ALL COMMON CATHODE TO GROUND*************************************************************/
		case 0: GROUND_PORT|= (1<<DIGIT_4_BIT); GROUND_PORT|= (1<<DIGIT_1_BIT); GROUND_PORT|= (1<<DIGIT_2_BIT); GROUND_PORT|= (1<<DIGIT_3_BIT);break;
		/*******************************************************************************************************************************************/
		
		/**************************************************SET DIGIT 1 TO GROUND********************************************************************/
		case 1: GROUND_PORT&=~(1<<DIGIT_1_BIT);  GROUND_PORT|= (1<<DIGIT_4_BIT); GROUND_PORT|= (1<<DIGIT_2_BIT); GROUND_PORT|= (1<<DIGIT_3_BIT);break; 
		/*******************************************************************************************************************************************/  
		
		/**************************************************SET DIGIT 2 TO GROUND********************************************************************/
  		case 2: GROUND_PORT&=~(1<<DIGIT_2_BIT);  GROUND_PORT|= (1<<DIGIT_4_BIT); GROUND_PORT|= (1<<DIGIT_1_BIT); GROUND_PORT|= (1<<DIGIT_3_BIT);break;
		/*******************************************************************************************************************************************/
		
		/**************************************************SET DIGIT 3 TO GROUND********************************************************************/
		case 3: GROUND_PORT&=~(1<<DIGIT_3_BIT);  GROUND_PORT|= (1<<DIGIT_4_BIT); GROUND_PORT|= (1<<DIGIT_1_BIT); GROUND_PORT|= (1<<DIGIT_2_BIT);break;
		/*******************************************************************************************************************************************/
		
		/**************************************************SET DIGIT 4 TO GROUND********************************************************************/
		case 4: GROUND_PORT&=~(1<<DIGIT_4_BIT);  GROUND_PORT|= (1<<DIGIT_1_BIT); GROUND_PORT|= (1<<DIGIT_2_BIT); GROUND_PORT|= (1<<DIGIT_3_BIT);break;
		/*******************************************************************************************************************************************/
	}
}


