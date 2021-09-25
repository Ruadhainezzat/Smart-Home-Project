
#include "STD_TYPES.h"
#include "ACTUATOR_config.h"
#ifndef ACTUATOR_INTERFACE_H_
#define ACTUATOR_INTERFACE_H_

#define NULL_PTR          ((void *)0)

typedef enum{
	ACTUATOR_OFF, ACTUATOR_ON
}Actuator_State;

typedef struct{
	u8 actuatorPort;
	u8 actuatorChannel;
}Actuator_ChannelConfig;

typedef struct{
	Actuator_ChannelConfig Actuators[NUM_ACTUATORS_CONFIG];
}Actuator_ConfigType;



void Actuator_Init(Actuator_ConfigType * Actuator_ConfigTypePtr);
void Actuator_SetState(u8 Actuator_Number, Actuator_State State);
#endif /* ACTUATOR_INTERFACE_H_ */
