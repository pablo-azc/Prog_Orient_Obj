
#ifndef COMUNICACION_ARDUINO_H
#define COMUNICACION_ARDUINO_H

#include <string>
#include <vector>
#include <fcntl.h>   // Controles de archivos (O_RDWR)
#include <termios.h> // Control de terminales y velocidades serie
#include <unistd.h>  // write(), read(), close(), sleep()


class Comunicacion_Arduino
{
public:
  /// 
  /// @param  texto 
  void escribirSerial(std::string texto);



  /// 
  /// @param comando 
  std::string leerSerial(std::string comando = ""); //añadida la opcion de mandar un comando antes de leer


  /// 
  /// @param  puerto 
  /// @param  baudrate 
  void iniciar(std::string puerto = "/dev/ttyUSB0", int baudrate = 19200);

private:
  // Private attributes  

  speed_t intToBaudRate(int baud);//necesario para poder tener baudrate variable


  int baudrate;
  int serial_port;//Añadido para permitir la comunicacion serie
  struct termios tty;
  std::string puerto;

};

#endif // COMUNICACION_ARDUINO_H
