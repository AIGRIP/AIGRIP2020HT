#ifndef communicationBLT_h
#define communicationBLT_h


void receiveBluetoothMessages(void *arg);

int sendBluetoothMessage(char bufferToSend[1024]);

void setupBluetooth();

#endif