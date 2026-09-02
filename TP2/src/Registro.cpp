#include "Registro.h"
#include <iostream>
#include <sstream>
#include <string>

// Methods


// Accessor methods



// Other methods



/// 
std::string Registro::convertirATexto(std::string formato)
{
    std::ostringstream salida;

    //Formato JSON
    if (formato=="JSON"||formato=="json")
    {
        salida << "{\n"
               << "  \"device_id\": \"" << id << "\",\n"
               << "  \"sample_id\": " << sample << ",\n"
               << "  \"timestamp\": \"" << timestamp << "\",\n"
               << "  \"position_x\": " << posicion_x << ",\n"
               << "  \"position_y\": " << posicion_y << ",\n"
               << "  \"velocity_x\": " << velocidad_x << ",\n"
               << "  \"velocity_y\": " << velocidad_y << ",\n"
               << "  \"total_distance\": " << dist_total << ",\n"
               << "  \"status\": " << (estatus ? 1 : 0) << "\n"
               << "}";
        return salida.str();
    }
    //Formato XML
    if (formato=="XML"||formato=="xml"){
        salida << "<registro>\n"
               << "  <device_id>" << id << "</device_id>\n"
               << "  <sample_id>" << sample << "</sample_id>\n"
               << "  <timestamp>" << timestamp << "</timestamp>\n"
               << "  <position_x>" << posicion_x << "</position_x>\n"
               << "  <position_y>" << posicion_y << "</position_y>\n"
               << "  <velocity_x>" << velocidad_x << "</velocity_x>\n"
               << "  <velocity_y>" << velocidad_y << "</velocity_y>\n"
               << "  <total_distance>" << dist_total << "</total_distance>\n"
               << "  <status>" << (estatus ? 1 : 0) << "</status>\n"
               << "</registro>";
        return salida.str();
    }

    //Formato CSV (predeterminado)
    salida << id << ",\t"
        << sample << ",\t"
        << timestamp << ",\t"
        << posicion_x << ",\t"
        << posicion_y << ",\t"
        << velocidad_x << ",\t"
        << velocidad_y << ",\t"
        << dist_total << ",\t"
        << (estatus ? "1" : "0"); // Convertimos el bool a "1" o "0" 
        return salida.str();
    
}


/// 
/// @param  texto 
void Registro::ConvertirDeTexto(std::string texto)
{
    std::stringstream datos(texto);
    std::string device_id,sample_id,pos_x,pos_y,vel_x,vel_y,dist,status;
    std::getline(datos,id,',');
    std::getline(datos,sample_id,',');
    std::getline(datos,timestamp,',');
    std::getline(datos,pos_x,',');
    std::getline(datos,pos_y,',');
    std::getline(datos,vel_x,',');
    std::getline(datos,vel_y,',');
    std::getline(datos,dist,',');
    std::getline(datos,status,'\n');

    sample=std::stoi(sample_id);
    posicion_x=std::stod(pos_x);
    posicion_y=std::stod(pos_y);
    velocidad_x=std::stod(vel_x);
    velocidad_y=std::stod(vel_y);
    dist_total=std::stod(dist);
    estatus=std::stoi(status);
    
    //Ejemplo del texto recibido:
    //device_id,sample_id,timestamp,position_x,position_y,velocity_x,velocity_y,total_distance,status
}


