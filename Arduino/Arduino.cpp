#include "Arduino.h"

#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
// Linux headers
#include <vector>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <cerrno> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
using namespace std;

string Dato;

int main(){
    struct termios tty{};

    int serialPort = open("/dev/ttyACM0", O_RDWR);
    if (serialPort < 0) {
        std::cout << "Error while opening device... " << "errno = " << errno << std::endl;
        perror("Something went wrong with open()");
        exit(1);
    }

    cfsetspeed(&tty, B9600);


    char readBuffer[254];


    for(int i=0; i<100; i++){
        int numBytes = int(read(serialPort, &readBuffer, sizeof(readBuffer)));


        if (numBytes < 0){
            printf("Error reading: %s", strerror(errno));
        }
        Dato = readBuffer;
        cout << "El dato es: "<<Dato<<endl;
    }

    close(serialPort);
    return 0;
}