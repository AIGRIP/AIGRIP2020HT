

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#include <pthread.h>
#include <mqueue.h>

#include "communicationBLT.h"

int client;

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
        memset(receiveBuffer, 0, sizeof(receiveBuffer));
        // read data from the client
        bytes_read = read(client, receiveBuffer, sizeof(receiveBuffer));
        if( bytes_read > 0 ) {
            printf("Received message: %s", receiveBuffer);
            fflush(stdout);

            // Send event type to message main queue

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
        printf("Failed to send message.\n");
        return 1;
    }
}

void setupBluetooth()
{
    // Allocate size for local address and remot address.
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
    
    // Allocate size to print device address. 
    char printAddress[1024] = { 0 };

    // Define socket variable.
    int s;
    socklen_t opt = sizeof(rem_addr);

    // allocate socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // bind socket to port 1 of the first available 
    // local bluetooth adapter
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY; //"F8:1F:32:35:83:D9";
    loc_addr.rc_channel = (uint8_t) 1;
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));

    // put socket into listening mode
    listen(s, 1);

    // accept one connection
    client = accept(s, (struct sockaddr *)&rem_addr, &opt);

    // Convert address to string.
    ba2str( &rem_addr.rc_bdaddr, printAddress );
    // Print address of connected device.
    fprintf(stderr, "accepted connection from %s\n", printAddress);

}



/*

int main(int argc, char **argv)
{
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
    
    char sendBuffer[1024] = { 0 };

    int s, bytes_read, threadCommander;
    socklen_t opt = sizeof(rem_addr);

    // allocate socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // bind socket to port 1 of the first available 
    // local bluetooth adapter
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY; //"F8:1F:32:35:83:D9";
    loc_addr.rc_channel = (uint8_t) 1;
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));

    // put socket into listening mode
    listen(s, 1);

    // accept one connection
    client = accept(s, (struct sockaddr *)&rem_addr, &opt);

    ba2str( &rem_addr.rc_bdaddr, sendBuffer );
    fprintf(stderr, "accepted connection from %s\n", sendBuffer);

    pthread_attr_t attr;
    pthread_t thread_id;
    threadCommander = 0;

    pthread_attr_init(&attr);
    pthread_create(&thread_id, &attr,(void*) &receiveBluetoothMessages, (void*)&threadCommander);

    char *StrMatch;
    int stringLength;

    while(1)
    {


        memset(sendBuffer, 0, sizeof(sendBuffer));

        fgets(sendBuffer,1024,stdin);

        stringLength =strlen(sendBuffer);

        StrMatch = strchr(sendBuffer,0);
        //*StrMatch = '\n';

        StrMatch = strstr(sendBuffer,"quit");

        if(StrMatch == NULL)
        {
            bytes_read = write(client, sendBuffer, stringLength);
            if( bytes_read > 0 ) {
                printf("Sent: %s", sendBuffer);
            }else{
                printf("Failed to send message.\n");
            }
        }else{
            break;
        }


    }

    threadCommander = 1;

    pthread_cancel(thread_id);
    //pthread_join(thread_id,NULL)

    // close connection
    close(client);
    close(s);
    return 0;
}

*/
