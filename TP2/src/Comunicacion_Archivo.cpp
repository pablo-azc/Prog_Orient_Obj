#include "Comunicacion_Archivo.h"
#include <string>

// Methods


// Accessor methods



// Other methods



/// 
/// @param  aIncluir 
void Comunicacion_Archivo::add_record(Registro aIncluir)
{
    registros.push_back(aIncluir);
}


/// 
/// @return bool
bool Comunicacion_Archivo::leerArchivo()
{
    std::fstream Archivo;
    Archivo.open(nombreArchivo);
    std::string temp;
    while (getline(Archivo,temp))
    {
        if (temp=="device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status")
        {
            continue;
        }

        if(temp==""){
            break;
        }

        Registro temporal;
        temporal.ConvertirDeTexto(temp);
        add_record(temporal);
    }
    Archivo.close();
    return 1;
}


/// 
/// @param  nombre 
 Comunicacion_Archivo::Comunicacion_Archivo(std::string nombre)
{
    nombreArchivo=nombre;
}


/// 
/// @return bool
bool Comunicacion_Archivo::escribirRegistros()
{
    std::ofstream Archivo;
    Archivo.open(nombreArchivo,std::ios::out | std::ios::trunc);
    Archivo<<"device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status"<<std::endl;
    for (int i = 0; i < registros.size(); i++)
    {
        Archivo<<registros[i].convertirATexto()<<std::endl;
    }
    Archivo.close();
    return 1;
    
}

void Comunicacion_Archivo::leerRegistros(){
    std::cout<<"Los registros están codificados de la siguiente forma:"<<std::endl;
    std::cout<<"device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status"<<std::endl;
    for (int i = 0; i < registros.size(); i++)
    {
        std::cout<<registros[i].convertirATexto()<<std::endl;
    }
}


