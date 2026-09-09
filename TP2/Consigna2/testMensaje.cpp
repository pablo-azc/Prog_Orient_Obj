#include <iostream>
#include "src/Mensaje.h"
using namespace std;


int main(){
    std::cout<<"ESTE ES UN ARCHIVO DE PRUEBA"<<std::endl;
    Mensaje mensajero;
    mensajero.establecerParametro("Test1",to_string(100));
    mensajero.establecerParametro("Pi",to_string(3.14));
    mensajero.establecerParametro("Artpop","Lady Gaga");
    mensajero.establecerParametro("Judas","LadyGaga");
    vector<string> temp = mensajero.listarParametros();
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<"ubicacion:"<<mensajero.obtenerIndice(temp[i])
        <<" nombre:"<< temp[i] 
        <<" Contenido:"<<mensajero.obtenerParametro(i)
        <<" Contenido:"<<mensajero.obtenerParametro(temp[i])
        <<endl;
    }
    cout<<mensajero.obtenerIndice("LoveDrug");
    
    return 0;
}