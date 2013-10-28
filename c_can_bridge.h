#include <stdlib.h>
#include "canopenlib_linux_hw.h"

extern "C"
{

    /*
    * Scala callback when a message is received
    */
    typedef void (*msgReceived) (int port,
                                 long long id,
                                 int dlc,
                                 int flags,
                                 void *msg);
    //receive messages thread
    void *readMsgFunction (void *__port);

    //Initialize all the Library structures
    void initLibrary();

    //Open the specified Can port (defined  /dev/pcanX where X is a number 0 to 3)
    //and register the callback for msg received
    int openPort(int port, int bitrate, msgReceived function);
    //Close the secified Can port
    //and sto the receiving thread
    int closePort(int port);
    //Enable or disable the echo mode on the specified port
    int echoPort(int port, bool enable);
    //write message to bus
    int writeMsg (int port,
                  long long id,
                  int dlc,
                  int flags,
                  void *msg);
}
