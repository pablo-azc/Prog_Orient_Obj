
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


};

#endif // NODO_B_H
