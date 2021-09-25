#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=OK;

	if((Copy_u8Pin > DIO_u8_PIN7) || (Copy_u8Direction > DIO_u8_PIN_OUTPUT))
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		if(Copy_u8Direction == DIO_u8_PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8_PORTA: CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8_PORTB: CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8_PORTC: CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8_PORTD: CLR_BIT(DDRD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK;             break;
			}
		}
		else if (Copy_u8Direction == DIO_u8_PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8_PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8_PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8_PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8_PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK;             break;
			}
		}
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Port)
	{
	case DIO_u8_PORTA: DDRA=Copy_u8Direction; break;
	case DIO_u8_PORTB: DDRB=Copy_u8Direction; break;
	case DIO_u8_PORTC: DDRC=Copy_u8Direction; break;
	case DIO_u8_PORTD: DDRD=Copy_u8Direction; break;
	default: Local_u8ErrorState=NOK;         break;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=OK;
	if((Copy_u8Pin > DIO_u8_PIN7))
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		if(Copy_u8Value == DIO_u8_PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8_PORTA: CLR_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8_PORTB: CLR_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8_PORTC: CLR_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8_PORTD: CLR_BIT(PORTD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK;              break;
			}
		}
		else if (Copy_u8Value == DIO_u8_PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8_PORTA: SET_BIT(PORTA,Copy_u8Pin); break;
			case DIO_u8_PORTB: SET_BIT(PORTB,Copy_u8Pin); break;
			case DIO_u8_PORTC: SET_BIT(PORTC,Copy_u8Pin); break;
			case DIO_u8_PORTD: SET_BIT(PORTD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK;              break;
			}
		}
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Port)
	{
	case DIO_u8_PORTA: PORTA=Copy_u8Value; break;
	case DIO_u8_PORTB: PORTB=Copy_u8Value; break;
	case DIO_u8_PORTC: PORTC=Copy_u8Value; break;
	case DIO_u8_PORTD: PORTD=Copy_u8Value; break;
	default: Local_u8ErrorState=NOK;          break;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pu8Value == NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else if((Copy_u8Pin > DIO_u8_PIN7))
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		switch(Copy_u8Port)
		{
		case DIO_u8_PORTA: *Copy_pu8Value=GET_BIT(PINA,Copy_u8Pin); break;
		case DIO_u8_PORTB: *Copy_pu8Value=GET_BIT(PINB,Copy_u8Pin); break;
		case DIO_u8_PORTC: *Copy_pu8Value=GET_BIT(PINC,Copy_u8Pin); break;
		case DIO_u8_PORTD: *Copy_pu8Value=GET_BIT(PIND,Copy_u8Pin); break;
		default: Local_u8ErrorState=NOK;                           break;
		}
	}

	return Local_u8ErrorState;
}

u8 DIO_u8TogglePinVlaue(u8 Copy_u8Port, u8 Copy_u8PinNum)
{
	u8 Local_u8ErrorState = OK;
	if (Copy_u8PinNum > DIO_u8_PIN7)
	{
		Local_u8ErrorState = NOK;
	}
	else
	{
		switch (Copy_u8Port)
		{
		case DIO_u8_PORTA:
			TOGGLE_BIT(PORTA, Copy_u8PinNum);
			break;
		case DIO_u8_PORTB:
			TOGGLE_BIT(PORTB, Copy_u8PinNum);
			break;
		case DIO_u8_PORTC:
			TOGGLE_BIT(PORTC, Copy_u8PinNum);
			break;
		case DIO_u8_PORTD:
			TOGGLE_BIT(PORTD, Copy_u8PinNum);
			break;
		default:
			Local_u8ErrorState = NOK;
			break;
		}
	}

	return Local_u8ErrorState;
}
