#include "Comunicacion_Arduino.h"
#include <string>
#include <iostream>
#include <fcntl.h>   // Controles de archivos (O_RDWR)
#include <termios.h> // Control de terminales y velocidades serie
#include <unistd.h>  // write(), read(), close(), sleep()
//#include <cstring>

// Methods


// Accessor methods



// Other methods


/// 
/// @param  puerto 
/// @param  baudrate 
Comunicacion_Arduino::Comunicacion_Arduino(std::string port = "/dev/ttyUSB0", int baud = 19200)
{
    puerto=port;
    baudrate=baud;
    serial_port = open(puerto.c_str(), O_RDWR | O_NOCTTY); 
    //.c_str() lo convierte a puntero de caracteres

    if (serial_port < 0) {
        std::cout << "Error al abrir el puerto. Verifica permisos o la ruta." << std::endl;
    }

    if (tcgetattr(serial_port, &tty) != 0) {
        std::cerr << "Error al obtener atributos del puerto." << std::endl;
        close(serial_port);
    }

    cfsetispeed(&tty, intToBaudRate(baudrate)); // Velocidad de entrada
    cfsetospeed(&tty, intToBaudRate(baudrate)); // Velocidad de salida

    // Configuración 8N1 (8 bits de datos, sin paridad, 1 bit de parada)
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag |= CREAD | CLOCAL; // Activar lectura e ignorar señales de control de módem

    // Aplicar configuración
    tcsetattr(serial_port, TCSANOW, &tty);

}

/// 
void Comunicacion_Arduino::leerSerial(std::string comando)
{
}


/// 
/// @param  texto 
void Comunicacion_Arduino::escribirSerial(std::string texto)
{
}


//Funcion añadida que convierte del baudrate variable a baudrate que acepta Termios
speed_t intToBaudRate(int baud) {
    switch (baud) {
        case 2400:   return B2400;
        case 4800:   return B4800;
        case 9600:   return B9600;
        case 19200:  return B19200;
        case 38400:  return B38400;
        case 57600:  return B57600;
        case 115200: return B115200;
        default:     return B9600; // Baudrate por defecto si no coincide ninguno
    }
}




