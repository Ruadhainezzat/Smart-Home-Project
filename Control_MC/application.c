/******************************************************************************
 * Module: Application
 *
 * File Name: application.c
 *
 * Description:  This file contains the source program for control MC
 *
 * Author: Rowan Ezzat
 *
 *******************************************************************************/

#include "CommunicationLinker.h"
#include "BluetoothModule.h"
#include "STD_TYPES.h"

void main(void) {
	/*
	 * Local variable to store the upcoming data
	 */
	u8 data = 0;

	/*
	 * Init Port Module
	 */
	PORT_voidInit();

	/*
	 * Init the bluetooth module
	 */
	BluetoothModule_Init();

	/*
	 * Init the CommunicationLinker Module as Master MC
	 */
	Comm_Init(COMM_MASTER_MODE);

	while (1) {

		/*
		 * Recieve the data from the bluetooth module via USART
		 */
		data = BluetoothModule_RecieveData();
		/*
		 * Send the data to the sink MC via InterCommunication Link
		 */
		data = Comm_SendData(data);

	}
}
