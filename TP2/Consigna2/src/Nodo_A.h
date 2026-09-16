
#ifndef NODO_A_H
#define NODO_A_H

#include "Nodo.h"
#include "Mensaje.h"
#include <iostream>
#include <vector>


class Nodo_A : public Nodo
{
public:
  /// 
  /// @param  info 
  void RecibirMensaje(Mensaje info);
  //Idea de esta funcion: Recibe el mensaje, extrae los parametros que necesita, y los
  //guarda en la memoria


  /// 
  /// @return Mensaje
  Mensaje EnviarMensaje();
  //Idea de la funcion: Envia los parametros que considera necesario enviar desde su memoria

  ///Funcion para probar el funcionamiento de "EnviarMensaje"
  void setMemoria(std::string Parametro1, int Parametro2, double Parametro3, 
  float Parametro4, int indice);
  //idea de la funcion: es un set de todos los parametros necesarios


private:
  std::string Parametro1;
  int Parametro2;
  double Parametro3;
  float Parametro4;
  int indice;

  int ID_Dispositivo_Esperado = 1470369;
  int ID_Usuario_Esperado = 14100;

};

#endif // NODO_A_H
