

#include "CommunicationLinker.h"
#include "SPI_interface.h"


void Comm_Init(CommLinker_ControllerModes ControllerMode){

	if(ControllerMode == COMM_MASTER_MODE){
		SPI_voidInitialize(ControllerMode);
	}
	else if(ControllerMode == COMM_SLAVE_MODE){
		SPI_voidInitialize(ControllerMode);
	}
	else {
		/* No Action Required */
	}

}

u8 Comm_SendData(u8 data){
return SPI_u8Transiver(data);
}
