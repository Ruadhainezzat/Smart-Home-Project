#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

#define DIO_u8_PORTA        0
#define DIO_u8_PORTB        1
#define DIO_u8_PORTC        2
#define DIO_u8_PORTD        3

#define DIO_u8_PIN0         0
#define DIO_u8_PIN1         1
#define DIO_u8_PIN2         2
#define DIO_u8_PIN3         3
#define DIO_u8_PIN4         4
#define DIO_u8_PIN5         5
#define DIO_u8_PIN6         6
#define DIO_u8_PIN7         7

#define DIO_u8_PIN_OUTPUT   1
#define DIO_u8_PIN_INPUT    0

#define DIO_u8_PIN_HIGH     1
#define DIO_u8_PIN_LOW      0

#define DIO_u8_PORT_HIGH    0xff
#define DIO_u8_PORT_LOW     0

#define DIO_u8_PORT_OUTPUT  0xff
#define DIO_u8_PORT_INPUT   0


u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);

u8 DIO_u8TogglePinVlaue(u8 Copy_u8Port, u8 Copy_u8PinNum);

#endif
