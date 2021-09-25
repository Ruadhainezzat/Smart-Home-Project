#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0   		*((volatile u8*)0x53)     /*timer*/
#define TCCR0_WGM00       	 	6
#define TCCR0_WGM01        		3

#define TCNT0  	 		*((volatile u8*)0x52)

#define TIMSK  			*((volatile u8*)0x59)
#define TIMSK_TOIE0         	0

/**********************************************************/

#define TCCR1A   		*((volatile u8*)0x4F)     /*timer*/
#define TCCR1A_WGM10        	0
#define TCCR1A_WGM11        	1
#define TCCR1A_COM1A0       	6
#define TCCR1A_COM1A1       	7

#define TCCR1B   		*((volatile u8*)0x4E)     /*timer*/
#define TCCR1B_WGM12        	3
#define TCCR1B_WGM13        	4
#define TCCR1B_CS10         	0
#define TCCR1B_CS11         	1
#define TCCR1B_CS12         	2

#define TCNT1H   		*((volatile u8*)0x4D)
#define TCNT1L   		*((volatile u8*)0x4C)
#define TCNT1    		*((volatile u16*)0x4C)

#define OCR1AH   		*((volatile u8*)0x4B)
#define OCR1AL   		*((volatile u8*)0x4A)
#define OCR1A    		*((volatile u16*)0x4A)

#define ICR1H   		*((volatile u8*)0x47)
#define ICR1L   		*((volatile u8*)0x46)
#define ICR1    		*((volatile u16*)0x46)

/**********************************************************/

#define TCCR1B   		*((volatile u8*)0x4E)   /*timer 1 channel B*/
#define TCCR1B_ICNC1        	7 				/*noise cancellation*/
#define TCCR1B_ICES1        	6
#define TCCR1B_WGM13        	4
#define TCCR1B_WGM12        	3
#define TCCR1B_CS12         	2
#define TCCR1B_CS11         	1
#define TCCR1B_CS10         	0

#endif
