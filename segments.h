/*
* segments.h
*
* Created: 11/25/2018 7:21:12 PM
*  Author: conti
*/


#ifndef SEGMENTS_H_
#define SEGMENTS_H_
/***********************FOUR DIGIT 7 SEGMENT DISPLAY SH5461AS*************************/
/*******************************ANODE FOR EACH SEGMENT********************************/
/*************************************************************************************/
#define SEGMENTS_1_PORT		                PORTC
#define SEGMENTS_2_PORT                     PORTD
/*************************************************************************************/
/*                                                                  ||||||           */
#define SEGMENT_ONE_PORT	   		        PORTC    /*            ||    ||          */
#define	SEGMENT_ONE_DDR				        DDRC     /*             ||||||           */
#define SEGMENT_ONE_PIN		         		PINC     /*            11    ||          */
#define SEGMENT_ONE_BIT	         			DDC0     /*             1|||||           */

/*************************************************************************************/
/*                                                                  ||||||           */
#define SEGMENT_TWO_PORT			        PORTC    /*            ||    ||          */
#define	SEGMENT_THO_DDR				        DDRC     /*             ||||||           */
#define SEGMENT_TWO_PIN				        PINC     /*            ||    ||          */
#define SEGMENT_TWO_BIT				        DDC1     /*             111111           */

/*************************************************************************************/
/*                                                                  ||||||           */
#define /*SEGMENT_THREE_PORT*/DOT_PORT      PORTC    /*            ||    ||          */
#define	/*SEGMENT_THREE_PORT*/DOT_DDR		DDRC     /*             ||||||           */
#define /*SEGMENT_THREE_PORT*/DOT_PIN       PINC     /*            ||    ||          */
#define /*SEGMENT_THREE_PORT*/DOT_BIT	    DDC2     /*             ||||||  *DOT     */

/*************************************************************************************/
/*                                                                  ||||||           */
#define SEGMENT_FOUR_PORT		    	    PORTC    /*            ||    ||          */
#define	SEGMENT_FOUR_DDR				    DDRC     /*             ||||||           */
#define SEGMENT_FOUR_PIN				    PINC     /*            ||    11          */
#define SEGMENT_FOUR_BIT	     			DDC3     /*             |||||1           */

/*************************************************************************************/
/*                                                                   ||||||          */
#define SEGMENT_FIVE_PORT		            PORTC    /*             ||    ||         */
#define	SEGMENT_FIVE_DDR			        DDRC     /*              111111          */
#define SEGMENT_FIVE_PIN			        PINC     /*             ||    ||         */
#define SEGMENT_FIVE_BIT			        DDC4     /*              ||||||          */

/*************************************************************************************/
/*                                                                  |||||1           */
#define SEGMENT_SEVEN_PORT	     		    PORTC    /*            ||    11          */
#define	SEGMENT_SEVEN_DDR	    			DDRC     /*             ||||||           */
#define SEGMENT_SEVEN_PIN	    			PINC     /*            ||    ||          */
#define SEGMENT_SEVEN_BIT		    		DDC5     /*             ||||||           */

/*************************************************************************************/
/*                                                                  1|||||           */
#define SEGMENT_TEN_PORT			        PORTD    /*            11    ||          */
#define	SEGMENT_TEN_DDR				        DDRD     /*             ||||||           */
#define SEGMENT_TEN_PIN				        PIND     /*            ||    ||          */
#define SEGMENT_TEN_BIT				        DDD6     /*             ||||||           */

/*************************************************************************************/
/*                                                                  111111           */
#define SEGMENT_ELEVEN_PORT			        PORTD    /*            ||    ||          */
#define	SEGMENT_ELEVEN_DDR				    DDRD     /*             ||||||           */
#define SEGMENT_ELEVEN_PIN		    		PIND     /*            ||    ||          */
#define SEGMENT_ELEVEN_BIT	    			DDD7     /*             ||||||           */

/*************************************************************************************/
/*************************************************************************************/


/*************************GROUND FOR EACH DIGIT(COMMON CATHODE)******************************/
/********************************************************************************************/
#define GROUND_PORT		                    PORTB
/********************************************************************************************/
#define DIGIT_1_PORT	        		    PORTB                                     ////
#define	DIGIT_1_DDR	        			    DDRB     /*| |DIGIT4| |DIGIT3| |DIGIT2| |DIGIT1|*/
#define DIGIT_1_PIN	         			    PINB                                      ////
#define DIGIT_1_BIT		        		    DDB1

/********************************************************************************************/
#define DIGIT_2_PORT			            PORTB                            ////
#define	DIGIT_2_DDR				            DDRB     /*| |DIGIT4| |DIGIT3| |DIGIT2| |DIGIT1|*/
#define DIGIT_2_PIN				            PINB                             ////
#define DIGIT_2_BIT				            DDB2

/********************************************************************************************/
#define DIGIT_3_PORT			            PORTB                   ////
#define	DIGIT_3_DDR				            DDRB     /*| |DIGIT4| |DIGIT3| |DIGIT2| |DIGIT1|*/
#define DIGIT_3_PIN				            PINB                    ////
#define DIGIT_3_BIT	         			    DDB3

/********************************************************************************************/
#define DIGIT_4_PORT			            PORTB          ////
#define	DIGIT_4_DDR		         		    DDRB     /*| |DIGIT4| |DIGIT3| |DIGIT2| |DIGIT1|*/
#define DIGIT_4_PIN		         		    PINB           ////
#define DIGIT_4_BIT	         			    DDB4

/********************************************************************************************/
/********************************************************************************************/

void set_digit(char x);
void set_character(char x);
void set_segment(char x);

#endif /* SEGMENTS_H_ */