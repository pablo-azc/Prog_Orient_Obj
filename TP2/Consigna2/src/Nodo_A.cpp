#include "Nodo_A.h"

// Methods


// Accessor methods



// Other methods



/// 
/// @param  info 
void Nodo_A::RecibirMensaje(Mensaje info)
{
    try
    {
        this->Parametro1=info.obtenerParametro("Parametro1");
        this->Parametro2=std::stoi(info.obtenerParametro("Parametro2"));
        this->Parametro3=std::stod(info.obtenerParametro("Parametro3"));
        this->Parametro4=std::stof(info.obtenerParametro("Parametro4"));
        this->indice=std::stoi(info.obtenerParametro("indice"));
        Historial.push_back(info);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Posible parametro no existente" << '\n';
    }
    
}


/// 
/// @return Mensaje
Mensaje Nodo_A::EnviarMensaje()
{
    Mensaje AEnviar;
    AEnviar.establecerParametro("Parametro1",Parametro1);
    AEnviar.establecerParametro("Parametro2",std::to_string(Parametro2));
    AEnviar.establecerParametro("Parametro3",std::to_string(Parametro3));
    AEnviar.establecerParametro("Parametro4",std::to_string(Parametro4));
    AEnviar.establecerParametro("ID",std::to_string(ID));
    AEnviar.establecerParametro("indice",std::to_string(indice));
    return AEnviar;
}

void Nodo_A::setMemoria(std::string Parametro1, int Parametro2, double Parametro3, 
  float Parametro4, int ID, int indice){
    this->Parametro1=Parametro1;
    this->Parametro2=Parametro2;
    this->Parametro3=Parametro3;
    this->Parametro4=Parametro4;
    this->ID = ID;
    this->indice = indice;
  }

void Nodo_A::MostrarTodo(){
    for (int indiceMensaje = 0; indiceMensaje < Historial.size(); indiceMensaje++)
    {
        std::vector<std::string> temp = Historial[indiceMensaje].listarParametros();
        std::cout<<std::endl<<"Mensaje "<<indiceMensaje<<std::endl;
        for (int i = 0; i < temp.size(); i++)
        {
            std::cout<<" nombre:"<< temp[i] 
            <<" Contenido:"<<Historial[indiceMensaje].obtenerParametro(i)
            <<std::endl;
        }
    }
    
}




