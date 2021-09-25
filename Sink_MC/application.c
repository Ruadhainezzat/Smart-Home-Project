/******************************************************************************
 * Module: Application
 *
 * File Name: application.c
 *
 * Description:  This file contains the source program for sink MC
 *
 * Author: Rowan Ezzat
 *
 *******************************************************************************/

#include "CommunicationLinker.h"
#include "DIO_interface.h"
#include "ACTUATOR_interface.h"
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
	 * Init the CommunicationLinker Module as Slave MC
	 */
	Comm_Init(COMM_SLAVE_MODE);

	/*
	 * Set Actuator Config Struct
	 */
	Actuator_ConfigType ActuatorsChannels = {
	DIO_u8_PORTA, DIO_u8_PIN6,
	DIO_u8_PORTA, DIO_u8_PIN7 };

	/*
	 * Init Actuator Module
	 */
	Actuator_Init(&ActuatorsChannels);

	/*
	 * Main Program
	 */
	while (1) {
		/*
		 * Receive the data from CONTROL MC
		 */
		data = Comm_SendData(0x55);
		/*
		 * Take action according to the upcoming data
		 *
		 * '0' -> Actuator(0) -> OFF
		 *     -> Actuator(1) -> OFF
		 *
		 * '1' -> Actuator(0) -> ON
		 *     -> Actuator(1) -> OFF
		 *
		 * '2' -> Actuator(0) -> OFF
		 *     -> Actuator(1) -> ON
		 *
		 * '3' -> Actuator(0) -> ON
		 *     -> Actuator(1) -> ON
		 */
		if (data == '0') {
			Actuator_SetState(0, ACTUATOR_OFF);
			Actuator_SetState(1, ACTUATOR_OFF);
		} else if (data == '1') {
			Actuator_SetState(0, ACTUATOR_ON);
			Actuator_SetState(1, ACTUATOR_OFF);
		} else if (data == '2') {
			Actuator_SetState(0, ACTUATOR_OFF);
			Actuator_SetState(1, ACTUATOR_ON);
		} else if (data == '3') {
			Actuator_SetState(0, ACTUATOR_ON);
			Actuator_SetState(1, ACTUATOR_ON);
		} else {
			/* No Action Required */
		}
	}
}
