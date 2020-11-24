#ifndef communicationBLT_h
#define communicationBLT_h

#include "typedefsGripperNano.h"

void *receiveBluetoothMessages(void *arg);

int sendBluetoothMessage(char bufferToSend[1024]);

void setupBluetooth();

#endif
