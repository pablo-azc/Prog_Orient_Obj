#include "Comunicacion_Archivo.h"
#include <string>

// Methods


// Accessor methods



// Other methods



/// 
/// @param  aIncluir 
void Comunicacion_Archivo::add_record(Registro aIncluir)
{
    //añade una copia del registro al archivo original
    registros.push_back(aIncluir);
}


/// 
/// @return bool
bool Comunicacion_Archivo::leerArchivo()
{
    //abre el archivo
    std::fstream Archivo;
    Archivo.open(nombreArchivo);
    //crea una cadena temporal
    std::string temp;
    while (getline(Archivo,temp))
    {
        //comprueba si es el header. Si es el header, lo ignora
        if (temp=="device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status")
        {
            continue;
        }

        //si la linea esta vacia, la ignora
        if(temp==""){
            break;
        }

        //Guarda una copia del registro temporal en los registros
        Registro temporal;
        temporal.ConvertirDeTexto(temp);
        add_record(temporal);
    }
    //cierra el archivo
    Archivo.close();
    return 1;
}


/// 
/// @param  nombre 
 Comunicacion_Archivo::Comunicacion_Archivo(std::string nombre)
{
    //el constructror solo guarda el nombre de archivo
    nombreArchivo=nombre;
}


/// 
/// @return bool
bool Comunicacion_Archivo::escribirRegistros()
{
    //abre el archivo
    std::ofstream Archivo;
    Archivo.open(nombreArchivo,std::ios::out | std::ios::trunc);
    //escribe la cabecera
    Archivo<<"device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status"<<std::endl;
    //escribe todos los registros
    for (int i = 0; i < registros.size(); i++)
    {
        Archivo<<registros[i].convertirATexto()<<std::endl;
    }
    //cierra
    Archivo.close();
    return 1;
    
}

void Comunicacion_Archivo::leerRegistros(std::string formato){
    //esto es solo una muestra grafica de los registros
    if (!formato.compare("CSV")&!formato.compare("csv")&!formato.compare("JSON")&!formato.compare("json")&!formato.compare("xml")&!formato.compare("XML"))
    {
        std::cout<<"NOTA: formato de salida de terminal No reconocido, usando CSV."<<std::endl;
    }
    std::cout<<"Los registros están codificados de la siguiente forma:"<<std::endl;
    std::cout<<"device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status"<<std::endl;
    for (int i = 0; i < registros.size(); i++)
    {
        std::cout<<registros[i].convertirATexto(formato)<<std::endl;
    }
}


