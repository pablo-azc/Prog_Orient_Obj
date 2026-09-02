#include <iostream>
#include <string>
#include "Comunicacion_Arduino.h"
#include "Comunicacion_Archivo.h"

using namespace std;

Comunicacion_Arduino Arduino;
Comunicacion_Archivo Archivo("salida.csv");
string formato = "CSV";

bool entradaCorrecta(string entrada){
    //Si la respuesta es muy corta, es la inicial o el encabezado, lo ignora
    if (entrada.length()<5|entrada.find("device_id")!= string::npos|entrada.find("#")!= string::npos)
    {
        return false;
    }
    return true;
}


void leerArduino(int veces = 1)
{
    cout<<"Estado: Conectado con Arduino"<<endl;
    string temporal;    
    //Elimina la primera linea por si se inició la comunicacion con el monitor serial
    Arduino.leerSerial();

    for (int i = 0; i < veces; i++)
    {
        cout<<"Estado: Leyendo Registro "<<i<<endl;
        Registro temp;
        Arduino.escribirSerial("c");
        do
        {
            //comprueba si la linea es correcta
            temporal=Arduino.leerSerial();
            //cout<<"Respuesta del Arduino:"<<temporal;
        } while (!entradaCorrecta(temporal));
        temp.ConvertirDeTexto(temporal);
        Archivo.add_record(temp);
    }
}


enum objetivos{NoEspecificado,leer,escribir};


int main (int argc, char ** argv){    

    objetivos comando;
    int veces=1;
    string puerto="/dev/ttyUSB0";

    //std::cout << "Lista de "<< argc<<" parametros:"<<std::endl;
    for (int i = 0; i < argc; i++)
    {
        string arg = argv[i];
        //std::cout<<"argv["<<i<<"]_"<<arg << std::endl; //Linea de desarrolo: lista los parametros
        if (arg=="--mode")
        {     
            if (argc>i)
            {
                i++;
            }
            
            arg=argv[i];
            if (arg== "read")
            {
                comando=leer;
            }
            else if (arg=="write")
            {
                comando=escribir;
            }else{
                cout<<"Comando --mode Mal usado"<<endl;
            }
            
        }
        if (arg=="--file")
        {
            if (argc>i)
            {
            i++;
            arg=argv[i];
            Archivo.nombreArchivo=arg;
            } else
            {
                cout<<"Comando --file Mal usado"<<endl;
            }
            
        }
        if (arg=="--port")
        {
            if (argc>i)
            {
            i++;
            arg=argv[i];
            puerto=arg;}else
            {
                cout<<"Comando --port Mal usado"<<endl;
            }
        }
        if (arg=="--count")
        {
            if (argc>i)
            {
            i++;
            arg=argv[i];
            veces=stoi(arg);
            }else
            {
                cout<<"Comando --count Mal usado"<<endl;
            }
        }
        if (arg=="--format")
        {
            if (argc>i)
            {
            i++;
            arg=argv[i];
            formato=arg;
            } else
            {
                cout<<"Comando --format Mal usado"<<endl;
            }
        }
        
    }

    //Realiza las acciones según operación
    switch (comando)
    {
    case leer:
        Archivo.leerArchivo();
        Archivo.leerRegistros(formato);
        break;

    case escribir:
        Arduino.iniciar(puerto);
        leerArduino(veces);
        Archivo.leerRegistros(formato);
        Archivo.escribirRegistros();
        break;
    
    default:
        cout<<"Faltó especificar operación"<<endl;
        break;
    }


    
}
