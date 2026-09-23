#include "Registro.h"
#include <iostream>
#include <sstream>
#include <string>

/// 
/// @param  texto 
void Registro::ConvertirDeTexto(std::string texto)
{
    std::stringstream datos(texto);
    std::string vacio;
    std::getline(datos,vacio,'[');
    std::getline(datos,this->timestamp,']');
    std::getline(datos,vacio,'[');
    std::getline(datos,this->type,']');
    std::getline(datos,this->menssage,'\n');
    
    //Ejemplo del texto recibido:
    //[timestamp] [type] message
}


/// 
std::string Registro::convertirATexto(std::string formato)
{
    std::ostringstream salida;

    //Formato JSON
    if (formato=="JSON"||formato=="json")
    {
        salida << "{\n"
               << "  \"timestamp\": \"" << timestamp << "\",\n"
               << "  \"type\": \"" << type << "\",\n"
               << "  \"message\": \"" << menssage << "\",\n"
               << "}";
        return salida.str();
    }
    //Formato XML
    if (formato=="XML"||formato=="xml"){
        salida << "<Log>\n"
               << "  <timestamp>" << timestamp << "</timestamp>\n"
               << "  <type>" << type << "</type>\n"
               << "  <message>" << menssage << "</message>\n"
               << "</Log>";
        return salida.str();
    }

    //Formato CSV (predeterminado)
    salida
        << timestamp << ",\t"
        << type << ",\t"
        << menssage << ",\t"
        ; // Convertimos el bool a "1" o "0" 
        return salida.str();
    
}




