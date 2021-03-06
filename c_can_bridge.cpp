#include "c_can_bridge.h"
//only for testing purposes
//#include <stdio.h>

msgReceived callbacks[MAX_CAN_INTERFACES];

pthread_t threads[MAX_CAN_INTERFACES];

int res;

void initLibrary() {
    canPortLibraryInit();
}

int openPort(int port, int bitrate, msgReceived function) {

        res = CANOPEN_ERROR;

        res = canPortOpen(port);
        if (res!=CANOPEN_OK)
            return res;

        res = canPortBitrateSet( port, bitrate );
        if (res!=CANOPEN_OK)
            return res;

        res = canPortGoBusOn(port);
        if (res!=CANOPEN_OK)
            return res;

        callbacks[port] = function;

        long tmp_port = (long)port;
        long *__port = (long *) malloc(sizeof(long));
        __port = (long*)tmp_port;
        res = pthread_create(&threads[port], NULL, readMsgFunction, (void*)__port);
        if (res!=CANOPEN_OK)
            return res;

        return CANOPEN_OK;
}

int closePort(int port) {

        res = CANOPEN_ERROR;

        res = pthread_cancel(threads[port]);
        //if (res!=CANOPEN_OK)
        //    return res;

        res = canPortGoBusOff(port);
        //if (res!=CANOPEN_OK)
        //    return res;

        res = canPortClose(port);
        //if (res!=CANOPEN_OK)
        //    return res;

        canSinglePortReset(port);

        return res;
}

int echoPort(int port, bool enable) {
        return canPortEcho(port, enable );
}

int writeMsg (    int port,
                  long long id,
                  int dlc,
                  int flags,
                  void *msg
                  ) {
        return canPortWrite (port,
                            id,
                            msg,
                            (unsigned int)dlc,
                            (unsigned int)flags);
}

long msg_id;
char msg_content[8];
unsigned int msg_size;
unsigned int msg_flags;
int read_port;

void *readMsgFunction (void *__port) {
    /*int*/ read_port = (long) __port;
    //int ret;
    while(1)
    {
        /*
        long msg_id;
        char msg_content[8];
        unsigned int msg_size;
        unsigned int msg_flags;
        */
        res =
        canPortRead(    read_port,
                        &msg_id,
                        (void*)msg_content,
                        &msg_size,
                        &msg_flags);

        if (res == CANOPEN_OK) {
            (*callbacks[read_port])( read_port,
                                msg_id,
                                (int)msg_size,
                                (int)msg_flags,
                                msg_content);
        }
  }
  return NULL;
}


