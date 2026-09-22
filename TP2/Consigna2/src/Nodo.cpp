#include "Nodo.h"

void Nodo::MostrarTodo(){
    for (int indiceMensaje = 0; indiceMensaje < Historial.size(); indiceMensaje++)
    {
        std::vector<std::string> temp = Historial[indiceMensaje].listarParametros();
        std::cout<<std::endl<<"<Mensaje "<<indiceMensaje<<">"<<std::endl;
        for (int i = 0; i < temp.size(); i++)
        {
            std::cout<<"\t<"<< temp[i] << ">"
            <<Historial[indiceMensaje].obtenerParametro(i)
            <<"</"<< temp[i] << ">" << std::endl;
        }
        std::cout<<std::endl<<"</Mensaje "<<indiceMensaje<<">"<<std::endl;
    }
    
}

void Nodo::actualizar(std::string &Destino,const std::string &Nombre, const Mensaje &Fuente){
    if (Fuente.estaPresente(Nombre)){
        try
        {
            Destino=Fuente.obtenerParametro(Nombre);
        }
        catch(const std::exception& e)
        {
           return;
        }
    }
}

void Nodo::actualizar(int &Destino,const std::string &Nombre, const Mensaje &Fuente){
        if (Fuente.estaPresente(Nombre)){
        try
        {
            Destino=std::stoi(Fuente.obtenerParametro(Nombre));
        }
        catch(const std::exception& e)
        {
            std::cerr<<"[Error]Converison No Valida"<<std::endl;
           return;
        }
    }
}
void Nodo::actualizar(float &Destino,const std::string &Nombre, const Mensaje &Fuente){
            if (Fuente.estaPresente(Nombre)){
        try
        {
            Destino=std::stof(Fuente.obtenerParametro(Nombre));
        }
        catch(const std::exception& e)
        {
            std::cerr<<"[Error]Converison No Valida"<<std::endl;
           return;
        }
    }
}
void Nodo::actualizar(double &Destino,const std::string &Nombre, const Mensaje &Fuente){
        if (Fuente.estaPresente(Nombre)){
        try
        {
            Destino=std::stod(Fuente.obtenerParametro(Nombre));
        }
        catch(const std::exception& e)
        {
            std::cerr<<"[Error]Converison No Valida"<<std::endl;
           return;
        }
    }
}

