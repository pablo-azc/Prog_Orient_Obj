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

