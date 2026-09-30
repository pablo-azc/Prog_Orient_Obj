#include "Registro.h"
#include <iostream>
#include <sstream>
#include <string>

/// 
/// @param  texto 
void Registro::ConvertirDeTexto(std::string texto)
{
    std::stringstream datos(texto);
    std::getline(datos,this->timestamp,',');
    std::getline(datos,this->type,',');
    std::getline(datos,this->modulo,',');
    std::string tempo1,tempo2;
    std::getline(datos,tempo1,',');
    this->ID_disp=stoi(tempo1);
    std::getline(datos,tempo2,',');
    this->ID_client=stoi(tempo2);
    std::getline(datos,this->menssage,'\n');
    
    //Ejemplo del texto recibido:
    //[timestamp] [type] message
}

Registro::Registro(std::string timestamp,std::string tipo,std::string modulo,std::string mensaje,int disp, int client){
    this ->timestamp = timestamp;
    this ->type=tipo;
    this ->modulo=modulo;
    this ->menssage=mensaje;
    this ->ID_disp=disp;
    this ->ID_client=client;
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
               << "  \"type\": \"" << type << "\",\n";


        if (ID_disp != -1)
        {
            salida <<"  \"ID_disp\": \"" << ID_disp << "\",\n";
        }
        if (ID_client != -1)
        {
            salida <<"  \"ID_client\": \"" << ID_client << "\",\n";
        }

        salida << "  \"message\": \"" << menssage << "\",\n"
               << "}";
        return salida.str();
    }
    //Formato XML
    if (formato=="XML"||formato=="xml"){
        salida << "<Log>\n"
               << "  <timestamp>" << timestamp << "</timestamp>\n"
               << "  <type>" << type << "</type>\n";

        if (ID_disp != -1)
        {
            salida << "  <ID_Disp>" << ID_disp << "</ID_Disp>\n";
        }
        if (ID_client != -1)
        {
            salida << "  <ID_client>" << ID_client << "</ID_client>\n";
        }

        salida << "  <message>" << menssage << "</message>\n"
               << "</Log>";
        return salida.str();
    }

    //Formato CSV (predeterminado)
    salida
        << timestamp << ",\t"
        << type << ",\t"
        << ID_disp << ",\t"
        << ID_client << ",\t"
        << menssage << ",\t"
        ;
        return salida.str();
    
}




