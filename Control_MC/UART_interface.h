#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "STD_TYPES.h"

void USART_voidInit (void);

void UART_SendString(char *str);

void USART_voidSendData(u8);

u8 USART_voidReceiveData(void);

#endif
