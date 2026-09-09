
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
  float Parametro4, int ID, int indice);

  void MostrarTodo();


private:


  std::vector<Mensaje> Historial;
  std::string Parametro1;
  int Parametro2;
  double Parametro3;
  float Parametro4;
  int ID = 1470369;
  int indice;

};

#endif // NODO_A_H
