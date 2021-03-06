

#include "DIO_interface.h"
#include "ACTUATOR_interface.h"


static Actuator_ChannelConfig * ActuatorsChannels = NULL_PTR;


void Actuator_Init(Actuator_ConfigType * Actuator_ConfigTypePtr){
	/*
	 * Loop Counter
	 */
	u8 counter = 0;
	/*
	 * Point to the actuators array
	 */
	ActuatorsChannels = Actuator_ConfigTypePtr->Actuators;
	for (counter=0; counter < NUM_ACTUATORS_CONFIG; counter++){

		/* Set Actuator Channel to output */
		DIO_u8SetPinDirection(ActuatorsChannels->actuatorPort, ActuatorsChannels->actuatorChannel,DIO_u8_PIN_OUTPUT);
		ActuatorsChannels++;
	}
	ActuatorsChannels = Actuator_ConfigTypePtr->Actuators;
}

void Actuator_SetState(u8 Actuator_Number, Actuator_State State){
	/*
	 * Set Actuator Channel Value
	 */
	DIO_u8SetPinValue(ActuatorsChannels[Actuator_Number].actuatorPort, ActuatorsChannels[Actuator_Number].actuatorChannel, State);
}
