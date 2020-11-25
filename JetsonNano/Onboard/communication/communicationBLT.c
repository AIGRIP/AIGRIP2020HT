

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#include <pthread.h>
#include <mqueue.h>

#include "communicationBLT.h"


// Global bluetooth variables.
int client;
int bluetoothSocketNano;

void *receiveBluetoothMessages(void *arg)
{
    /*
    * Get into an infinit while loop to receive I2C Messages.
    * Is recommended to call this function with a thread.
    */
    int bytes_read;
    char receiveBuffer[1024] = { 0 };

    // String commands to compare.
    char *StrMatch;

    // Connect to message queue.
    int mainMessageBuffer;
    mqd_t messageQueueMain;
    messageQueueMain = mq_open(messageMainQueueName, O_RDWR);
    
    if( messageQueueMain == (mqd_t) -1){
		printf("Failed to connect to main message queue from bluetooth.\n");
	}

    while(1)
    {
        // Set all character to 0.
        memset(receiveBuffer, 0, sizeof(receiveBuffer));
        // Read bluetooth data from the client.
        bytes_read = read(client, receiveBuffer, sizeof(receiveBuffer));

        // Check if an message was received.
        if( bytes_read > 0 ) {
            printf("Received message: %s", receiveBuffer);
            fflush(stdout);

            // Send event type to message main queue
            // Check the type of message.
            StrMatch = strstr(receiveBuffer,"Stop");
            if( StrMatch != NULL )
            {
                printf("Received stop command in BLT.\n");
                mainMessageBuffer = 7;
                if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                {
                    printf("Failed to send MQ. \n");
                }
            }else{
                StrMatch = strstr(receiveBuffer,"Start");
                if( StrMatch != NULL ){
                    printf("Received start command in BLT.\n");
                    mainMessageBuffer = 6;
                    if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                    {
                        printf("Failed to send MQ.\n");
                    }
                }
            }
        }

        // Let it sleep.
        usleep(10000);
    }
}

int sendBluetoothMessage(char bufferToSend[1024])
{
    /*
    * Send bluetooth messages.
    * On success it returns 0, on failure it return 1.
    */

    // Indicates how many byte that was sent.
    int bytes_sent;

    // Get the length of the string.
    int stringLength;
    stringLength =strlen(bufferToSend);

    // Write bluetooth message.
    bytes_sent = write(client, bufferToSend, stringLength);

    // Check if it was sent successfully.
    if( bytes_sent > 0 ) {
        printf("Sent: %s", bufferToSend);
        return 0;
    }
    else
    {
        // If it failed to send bluetooth messages, the client is propably disconnected.
        // So it sends a reconnect command.
        printf("Failed to send message.\n");

        // State 8 is to reconnect.
        int mainMessageBuffer = 8;

        // Open message queue, send message and close queue.
        mqd_t messageQueueMain;
        messageQueueMain = mq_open(messageMainQueueName, O_RDWR);
        mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1);
        mq_close(messageQueueMain);
        return 1;
    }
}

void setupBluetooth()
{
    /*
    * Setup the connection to a bluetooth device via rfcomm. 
    */

    // Allocate size for local address and remot address.
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
    
    // Allocate size to print device address. 
    char printAddress[1024] = { 0 };

    // Define socket variable.
    socklen_t opt = sizeof(rem_addr);

    // allocate socket
    bluetoothSocketNano = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // bind socket to port 1 of the first available 
    // local bluetooth adapter
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY; //"F8:1F:32:35:83:D9";
    loc_addr.rc_channel = (uint8_t) 1;
    bind(bluetoothSocketNano, (struct sockaddr *)&loc_addr, sizeof(loc_addr));

    // put socket into listening mode
    listen(bluetoothSocketNano, 1);

    // accept one connection
    client = accept(bluetoothSocketNano, (struct sockaddr *)&rem_addr, &opt);

    // Convert address to string.
    ba2str( &rem_addr.rc_bdaddr, printAddress );
    // Print address of connected device.
    fprintf(stderr, "accepted connection from %s\n", printAddress);

}

void closeBluetooth()
{
    //Close the bluetooth connection

    // Remove client
    close(client);

    // Close socket.
    close(bluetoothSocketNano);
}
