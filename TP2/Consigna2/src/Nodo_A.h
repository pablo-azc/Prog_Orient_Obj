
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


};

#endif // NODO_A_H
