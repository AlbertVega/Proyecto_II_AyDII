
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

char Dato;
vector<char> Datos;

char readData(){
    struct termios tty{};
    int serialPort = open("/dev/ttyACM0", O_RDWR);

    cfsetspeed(&tty, B9600);

    if (serialPort < 0) {
        -1;
    }
    char buffer;
    int n = read(serialPort, &buffer, sizeof(char));

    close(serialPort);
    return buffer;
}

int main(){
    for (int i=0; i<2;i++){
        Dato = readData();
        Datos.push_back(Dato);
    }

    for(int j=0; j<Datos.size(); j++){
        cout<<Datos[j];
    }
}