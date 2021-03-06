

#ifndef COMMUNICATIONLINKER_H_
#define COMMUNICATIONLINKER_H_
#include "STD_TYPES.h"

typedef enum{
	COMM_MASTER_MODE=1, COMM_SLAVE_MODE
}CommLinker_ControllerModes;

void Comm_Init(CommLinker_ControllerModes ControllerMode);
u8 Comm_SendData(u8 data);
#endif /* COMMUNICATIONLINKER_H_ */
