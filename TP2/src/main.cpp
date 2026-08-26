#include <iostream>
#include <string>
#include "Comunicacion_Arduino.h"
#include "Comunicacion_Archivo.h"
using namespace std;
int main (int argc, char ** argv){

    Comunicacion_Arduino Arduino;
    Comunicacion_Archivo Archivo();
    

    std::cout << "Lista de "<< argc<<" parametros:"<<std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout<<"argv["<<i<<"]_"<<argv[i] << std::endl;
        if (argv[i]=="-read")
        {
            cout<<"Lectura detectada";
        }
        
    }


    
}

void leerArduino(int veces = 1)
{
}


/// 
void escribir()
{
}


