#include <iostream>
#include <string>
#include "Comunicacion_Arduino.h"
#include "Comunicacion_Archivo.h"
using namespace std;

Comunicacion_Arduino Arduino;
Comunicacion_Archivo Archivo("salida.csv");

int main (int argc, char ** argv){    

    std::cout << "Lista de "<< argc<<" parametros:"<<std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout<<"argv["<<i<<"]_"<<argv[i] << std::endl;
        if (argv[i]=="-read")
        {
            cout<<"Lectura detectada";
        }
        
    }

    //cout<<Arduino.leerSerial("h");
    //Registro basura;
    //basura.ConvertirDeTexto("2,1,1000,1.25,0.75,1.25,0.75,1.46,1");
    //Archivo.add_record(basura);
    //Archivo.escribirRegistros();
    Archivo.leerArchivo();

    
}

void leerArduino(int veces = 1)
{
    sleep(1);

    while (Arduino.leerSerial()!="")
    {
        sleep(0.5);
    }
    for (int i = 0; i < veces; i++)
    {
        Registro temp;
        temp.ConvertirDeTexto(Arduino.leerSerial("c"));
        Archivo.add_record(temp);
    }
}


/// 
void escribir()
{
}


