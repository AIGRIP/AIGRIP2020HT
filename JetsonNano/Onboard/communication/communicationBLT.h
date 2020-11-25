#ifndef communicationBLT_h
#define communicationBLT_h

#include "typedefsGripperNano.h"

// The functionS is adapted to work in "communication.cpp".

// Receive function for bluetooth. Is recommended to use it on a thread.
void *receiveBluetoothMessages(void *arg);

// Sends bluetooth message.
int sendBluetoothMessage(char bufferToSend[1024]);

// Setup bluetooth with rfcomm.
void setupBluetooth();

// Close bluetooth connection.
void closeBluetooth();

#endif
