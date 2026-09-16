
#ifndef NODO_A_H
#define NODO_A_H

#include "Mensaje.h"
#include <iostream>
#include <vector>


class Nodo_A
{
public:
  /// 
  /// @param  info 
  void RecibirMensaje(Mensaje info);


  /// 
  /// @return Mensaje
  Mensaje EnviarMensaje();

  ///Funcion para probar el funcionamiento de "EnviarMensaje"
  void setMemoria(std::string Parametro1, int Parametro2, double Parametro3, 
  float Parametro4, int indice);

  void MostrarTodo();


private:

  std::vector<Mensaje> Historial;
  std::string Parametro1;
  int Parametro2;
  double Parametro3;
  float Parametro4;
  int indice;

  int ID_Dispositivo_Esperado = 1470369;
  int ID_Usuario_Esperado = 14100;

};

#endif // NODO_A_H
