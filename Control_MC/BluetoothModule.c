

#include "UART_interface.h"
#include "BluetoothModule.h"


void BluetoothModule_Init(void){
	USART_voidInit();
}

void BluetoothModule_SendData(u8 data){

USART_voidSendData(data);
}

u8 BluetoothModule_RecieveData(void){
return USART_voidReceiveData();
}
