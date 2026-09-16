
#ifndef NODO_B_H
#define NODO_B_H

#include <iostream>
#include <vector>
#include "Mensaje.h"


class Nodo_B
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
  float Parametro4, int indice, int ID_Dispositivo,int ID_Usuario);

  //Sobrecarga que No sobreescribe la ID
  void setMemoria(std::string Parametro1, int Parametro2, double Parametro3, 
  float Parametro4, int indice);

  void MostrarTodo();


private:


  std::vector<Mensaje> Historial;
  std::string Parametro1;
  int Parametro2;
  double Parametro3;
  float Parametro4;
  int ID_Dispositivo = 1470369;
  int ID_Usuario = 14100;
  int indice;


};

#endif // NODO_B_H
