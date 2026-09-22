#include "Nodo_B.h"

// Methods


// Accessor methods



// Other methods



/// 
/// @param  info 
void Nodo_B::RecibirMensaje(Mensaje info)
{
  actualizar(this->Parametro1, "Parametro1", info);
  actualizar(this->Parametro2, "Parametro2", info);
  actualizar(this->Parametro3, "Parametro3", info);
  actualizar(this->Parametro4, "Parametro4", info);
  actualizar(this->indice, "indice", info);
  Historial.push_back(info);
    
}


/// 
/// @return Mensaje
Mensaje Nodo_B::EnviarMensaje()
{
    Mensaje AEnviar;
    AEnviar.establecerParametro("Parametro1",Parametro1);
    AEnviar.establecerParametro("Parametro2",std::to_string(Parametro2));
    AEnviar.establecerParametro("Parametro3",std::to_string(Parametro3));
    AEnviar.establecerParametro("Parametro4",std::to_string(Parametro4));
    AEnviar.establecerParametro("ID_Dispositivo",std::to_string(ID_Dispositivo));
    AEnviar.establecerParametro("ID_Usuario",std::to_string(ID_Usuario));
    AEnviar.establecerParametro("indice",std::to_string(indice));
    return AEnviar;
}

void Nodo_B::setMemoria(std::string Parametro1, int Parametro2, double Parametro3, 
  float Parametro4, int indice, int ID_Dispositivo,int ID_Usuario){
    this->Parametro1=Parametro1;
    this->Parametro2=Parametro2;
    this->Parametro3=Parametro3;
    this->Parametro4=Parametro4;
    this->ID_Dispositivo = ID_Dispositivo;
    this->ID_Usuario = ID_Usuario;
    this->indice = indice;
  }

void Nodo_B::setMemoria(std::string Parametro1, int Parametro2, double Parametro3, 
  float Parametro4, int indice){
    this->Parametro1=Parametro1;
    this->Parametro2=Parametro2;
    this->Parametro3=Parametro3;
    this->Parametro4=Parametro4;
    this->indice = indice;
  }






