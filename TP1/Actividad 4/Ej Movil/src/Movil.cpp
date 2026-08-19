#include "Movil.h"
#include <cmath>

// Constructors/Destructors


Movil::Movil()
{
  initAttributes();
}

Movil::Movil(string nombre, float vel_x, float vel_y)
{
  initAttributes();
  Identificacion=nombre;
  velocidad_x=vel_x;
  velocidad_y=vel_y;
}

Movil::~Movil()
{
}

// Methods
bool Movil::estaMoviendose(){
  if ((abs(velocidad_x)+abs(velocidad_y)>0) and encendido)
  {
    return true;
  } else {
    return false;
  }
}

bool Movil::encender(){
  encendido=true;
  return estaMoviendose();
}

void Movil::apagar(){
  encendido=false;
}

void Movil::simular(float tiempo){
  if (encendido)
  {
    posicion_x=posicion_x+velocidad_x*tiempo;
    posicion_y=posicion_y+velocidad_y*tiempo;
    distanciaTotal=distanciaTotal+sqrt(pow(velocidad_x*tiempo,2)+pow(velocidad_y*tiempo,2));
  }
  return;
}


// Accessor methods
// Other methods


void Movil::initAttributes()
{
  Identificacion = "Generico";
  encendido = false;
  posicion_x = 0;
  posicion_y = 0;
  velocidad_x = 0;
  velocidad_y = 0;
  distanciaTotal = 0;
}

