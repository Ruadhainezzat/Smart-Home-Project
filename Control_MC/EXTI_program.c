#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

/*Global pointer to function to hold the INT ISR address*/
static void (*EXTI_pvCallBackFunc[3])(void)={NULL};



void EXTI_voidINT0Init(void)
{
	/*1- Set the sense control configuration*/
#if EXTI_u8_INT0_SENSE == EXTI_u8_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_u8_INT0_SENSE == EXTI_u8_ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_u8_INT0_SENSE == EXTI_u8_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_u8_INT0_SENSE == EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong EXTI_u8_INT0_SENSE configuration option"

#endif

	/*1- Set the Initial state configuration*/
#if EXTI_u8_INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);

#elif EXTI_u8_INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);

#else
#error "Wrong EXTI_u8_INT0_INITIAL_STATE configuration option"

#endif

}
void EXTI_voidINT1Init(void)
{
	/*1- Set the sense control configuration*/
#if EXTI_u8_INT1_SENSE == EXTI_u8_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_u8_INT1_SENSE == EXTI_u8_ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_u8_INT1_SENSE == EXTI_u8_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_u8_INT1_SENSE == EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
#error "Wrong EXTI_u8_INT1_SENSE configuration option"

#endif

	/*1- Set the Initial state configuration*/
#if EXTI_u8_INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);

#elif EXTI_u8_INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);

#else
#error "Wrong EXTI_u8_INT0_INITIAL_STATE configuration option"

#endif
}
void EXTI_voidINT2Init(void)
{
	/*1- Set the sense control configuration*/
#if EXTI_u8_INT1_SENSE == EXTI_u8_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCSR_ISC2);

#elif EXTI_u8_INT1_SENSE == EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR,MCUCSR_ISC2);

#else
#error "Wrong EXTI_u8_INT1_SENSE configuration option"

#endif

	/*1- Set the Initial state configuration*/
#if EXTI_u8_INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);

#elif EXTI_u8_INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);

#else
#error "Wrong EXTI_u8_INT0_INITIAL_STATE configuration option"

#endif
}

u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNum, u8 Copy_u8Sense)
{
	u8 Local_u8ErrorSate = OK;

	switch(Copy_u8IntNum)
	{

	/*Set INT0 required Sense control*/
	case EXTI_u8_INT0:
		if(EXTI_u8_LOW_LEVEL == Copy_u8Sense)
		{
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		}
		else if (EXTI_u8_ON_CHANGE == Copy_u8Sense)
		{
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		}
		else if(EXTI_u8_FALLING_EDGE == Copy_u8Sense)
		{
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		}
		else if(EXTI_u8_RISING_EDGE == Copy_u8Sense)
		{
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		}
		else
		{
			Local_u8ErrorSate = NOK;
		}
		break;

		/*Set INT1 required Sense control*/
	case EXTI_u8_INT1:
		if(EXTI_u8_LOW_LEVEL == Copy_u8Sense)
		{
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
		}
		else if (EXTI_u8_ON_CHANGE == Copy_u8Sense)
		{
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
		}
		else if(EXTI_u8_FALLING_EDGE == Copy_u8Sense)
		{
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		}
		else if(EXTI_u8_RISING_EDGE == Copy_u8Sense)
		{
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		}
		else
		{
			Local_u8ErrorSate = NOK;
		}

		break;

		/*Set INT2 required Sense control*/
	case EXTI_u8_INT2:
		if(EXTI_u8_FALLING_EDGE == Copy_u8Sense)
		{
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
		}
		else if(EXTI_u8_RISING_EDGE == Copy_u8Sense)
		{
			SET_BIT(MCUCSR,MCUCSR_ISC2);
		}
		else
		{
			Local_u8ErrorSate = NOK;
		}

		break;
	default: Local_u8ErrorSate = NOK; break;
	}

	return Local_u8ErrorSate;
}

u8 EXTI_u8EnableInt(u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorSate = OK;

	switch(Copy_u8IntNum)
	{
	case EXTI_u8_INT0: SET_BIT(GICR,GICR_INT0); break;
	case EXTI_u8_INT1: SET_BIT(GICR,GICR_INT1); break;
	case EXTI_u8_INT2: SET_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorSate = NOK; break;
	}

	return Local_u8ErrorSate;
}
u8 EXTI_u8DisableInt(u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorSate = OK;
	switch(Copy_u8IntNum)
	{
	case EXTI_u8_INT0: CLR_BIT(GICR,GICR_INT0); break;
	case EXTI_u8_INT1: CLR_BIT(GICR,GICR_INT1); break;
	case EXTI_u8_INT2: CLR_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorSate = NOK; break;
	}
	return Local_u8ErrorSate;
}

/*************************************CallBack Function************************************************/
u8 EXTI_u8SetCallBack(void (*Copy_pvCallBack)(void),u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorState =OK;

	if(Copy_pvCallBack !=NULL)
	{
		EXTI_pvCallBackFunc[Copy_u8IntNum] =Copy_pvCallBack;
	}
	else
	{
		Local_u8ErrorState =NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*************************************************INT0*****************************************/
void __vector_1 (void) 		__attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pvCallBackFunc[EXTI_u8_INT0] != NULL)
	{
		/*Invoke the call back function*/
		EXTI_pvCallBackFunc[EXTI_u8_INT0]();
	}
	else
	{
		/*Do nothing*/
	}
}
/*************************************************INT1*****************************************/
void __vector_2 (void) 		__attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pvCallBackFunc[EXTI_u8_INT1] != NULL)
	{
		/*Invoke the call back function*/
		EXTI_pvCallBackFunc[EXTI_u8_INT1]();
	}
	else
	{
		/*Do nothing*/
	}
}
/*************************************************INT2*****************************************/
void __vector_3 (void) 		__attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvCallBackFunc[EXTI_u8_INT2] != NULL)
	{
		/*Invoke the call back function*/
		EXTI_pvCallBackFunc[EXTI_u8_INT2]();
	}
	else
	{
		/*Do nothing*/
	}
}








