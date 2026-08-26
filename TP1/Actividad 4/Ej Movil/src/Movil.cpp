#include "Movil.h"
#include <cmath>
#include <iostream>

// Constructors/Destructors

//Se cambió en el constructor Velocidad por Posición 
//para permitir iniciar en puntos distintos de 0
Movil::Movil(string nombre, float pos_x, float pos_y)
{
  initAttributes();
  Identificacion=nombre;
  posicion_x=pos_x;
  posicion_y=pos_y;
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

void Movil::establecerVelocidad(float vel_x, float vel_y){
  velocidad_x=vel_x;
  velocidad_y=vel_y;
  return;
}

void Movil::obtenerPosicion(){
  std::cout << "Posicion en X: " <<posicion_x<< "m; Posicion en Y: "<<posicion_y<< "m" <<endl;
  return;
}

void Movil::obtenerVelocidad(){
  std::cout << "Velocidad en X: " <<velocidad_x<< "m/s; Velocidad en Y: "<<velocidad_y<< "m/s" <<endl;
  return;
}

//Nuevo metodo: Se generó este metodo para poder mostrar la distancia total
void Movil::obtenerDistanciaTotal(){
  std::cout << "Distancia total recorrida: " <<distanciaTotal<<"m" <<endl;
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

