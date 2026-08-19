#include "Movil.h"

// Constructors/Destructors


Movil::Movil()
{
  initAttributes();
}

Movil::~Movil()
{
}

// Methods


// Accessor methods



// Other methods


void Movil::initAttributes()
{
  Identificacion = "Generico";
  encendido = 0;
  posicion_x = 0;
  posicion_y = 0;
  velocidad_x = 0;
  velocidad_y = 0;
  distanciaTotal = 0;
}

