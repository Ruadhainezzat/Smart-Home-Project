#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_register.h"

static void (*TIMER_pvCallBackFunc)(void) = NULL;

u32 volatile Counter=0;

u32 volatile FirstTime=0;
u32 volatile SecondTime=0;
u32 volatile ThirdTime=0;

u8 volatile Flag=0; //to indicate how many times we entered external interrupt

void Timer0_voidInit(void)
{
	/*normal mode setting*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);

	/*<pre>-load setting*/
	TCNT0= TIMER0_u8_PRELOAD;

	/*overflow interrupt enable*/
	SET_BIT(TIMSK, TIMSK_TOIE0);

	/*<pre>-scaler division*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIMER0_u8_PRESCALER;
}

void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
	TCCR0= Copy_u8PreloadValue;
}

u8 Timer0_u8ovSetCallback(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState =OK;
	if(Copy_pvCallBackFunc !=NULL)
	{
		TIMER_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState =NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_11 (void)  __attribute__((signal));
void __vector_11 (void)
{
	if(TIMER_pvCallBackFunc != NULL)
	{
		TIMER_pvCallBackFunc();
	}
	else
	{
		//Do Nothing
	}
}

void Timer1_voidInit(void)
{

	/*Clear OC1A/OC1B on compare match, set
	OC1A/OC1B at TOP*/
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);

	/*Fast PWM*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);


	/*<pre>-scaler  CLk/8*/
	/*CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);*/

	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= TIMER0_u8_PRESCALER;

	/*Set top value*/
	ICR1=65000;
}

void Timer1_voidInitNormalMode(void)
{

	/*Normal Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);


	/*<pre>-scaler  CLk/8*/
	/*CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);*/

	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= TIMER0_u8_PRESCALER;
}

void Timer1_voidSetCompareValue(u16 Copy_u8CompareValue)
{
	OCR1A= Copy_u8CompareValue;
}

/**********************************************************/

/*timer1 overflow*/
void __vector_9 (void)  __attribute__((signal));
void __vector_9 (void)
{
	/*determine how many time the ICR1 overflow*/
	Counter ++;
}

/*timer1 input capture unit*/
/*void __vector_6 (void)  __attribute__((signal));
void __vector_6 (void)
{
if (Flag == 0)  //first time to enter interrupt
{
	FirstTime=ICR1;   //first raising edge
	Counter=0;         // set falling edge
}

}*/


