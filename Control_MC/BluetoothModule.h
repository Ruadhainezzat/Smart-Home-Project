

#ifndef BLUETOOTHMODULE_H_
#define BLUETOOTHMODULE_H_

#include "STD_TYPES.h"

void BluetoothModule_Init(void);
void BluetoothModule_SendData(u8 data);
u8 BluetoothModule_RecieveData(void);

#endif /* BLUETOOTHMODULE_H_ */
