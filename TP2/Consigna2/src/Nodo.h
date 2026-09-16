#ifndef NODO_H
#define NODO_H

#include "Mensaje.h"
#include <iostream>
#include <vector>

class Nodo
{
protected:
    std::vector<Mensaje> Historial; //Protected porque lo heredan lo nene

public:
    
    void MostrarTodo();
    virtual void RecibirMensaje(Mensaje info) = 0; //Igual a 0 porque NO DEBE SER DEFINIDO EN EL .CPP,
    virtual Mensaje EnviarMensaje() = 0;           //Deben ser definidos en los hijos

    // IMPORTANTE: Toda clase con métodos virtuales NECESITA un destructor virtual
    virtual ~Nodo() = default;
};




#endif // NODO_H