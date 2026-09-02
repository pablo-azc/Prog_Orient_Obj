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
void Comunicacion_Arduino::iniciar(std::string port, int baud)
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
    tty.c_cflag &= ~PARENB;//Desactiva Paridad
    tty.c_cflag &= ~CSTOPB;//Desactiva 2 bits de parada
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;//8 bits de datos
    tty.c_cflag |= CREAD | CLOCAL; // Activar lectura e ignorar señales de control de módem

    // Desactivar modo canónico, eco de caracteres y señales
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); 

    // --- CONFIGURACIÓN DEL TIMEOUT ---
    tty.c_cc[VTIME] = 10; // Tiempo de espera en décimas de segundo (10 = 1 segundo)
    tty.c_cc[VMIN] = 0;   // Número mínimo de caracteres a leer antes de desbloquear

    // Vaciar buffers de entrada y salida
    tcflush(serial_port, TCIOFLUSH);

    // Aplicar configuración
    tcsetattr(serial_port, TCSANOW, &tty);

    sleep(5);

}

/// 
std::string Comunicacion_Arduino::leerSerial(std::string comando)
{
    //si hay un comando, lo escribe. Sino, no.
    if (comando != "")
    {
        Comunicacion_Arduino::escribirSerial(comando);
    }
    //espera por si se procesa una respuesta
    usleep(200000);
    char buffer[512];
    //devuelve lo que leyó
    int bytes_read = read(serial_port, buffer, sizeof(buffer));
    if (bytes_read > 0) {
        return std::string(buffer,bytes_read);
    }
    return "";
    
}


/// 
/// @param  texto 
void Comunicacion_Arduino::escribirSerial(std::string texto)
{
    write(serial_port,texto.c_str(),texto.length());
}


//Funcion añadida que convierte del baudrate variable a baudrate que acepta Termios
speed_t Comunicacion_Arduino::intToBaudRate(int baud) {
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




