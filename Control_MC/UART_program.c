#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_register.h"
#include "UART_config.h"
#include"UART_interface.h"

void USART_voidInit (void)
{
	/*select 8-bit data*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	UCSRC =0b10000110;


	/* 9600 bps*/
	UBRRL =51;


	/*receiver enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);

	/*transmit enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		USART_voidSendData(str[j]);
		j++;
	}
}

void USART_voidSendData(u8 Copy_u8Data)
{
	/*1-Wait until data register is empty*/
	while (GET_BIT(UCSRA, UCSRA_UDRE) == 0);

	/*2- Write the data to the UDR register*/
	UDR = Copy_u8Data;
}

u8 USART_voidReceiveData(void)
{
	/*1-Wait until new Data is received*/
	while (GET_BIT(UCSRA, UCSRA_RXC) == 0);

	/*2- Return the Received data*/
	return UDR;
}
