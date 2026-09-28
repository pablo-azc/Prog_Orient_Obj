#include <iostream>
#include <string>
#include "src/Comunicacion_Archivo.h"
#include "src/PALogger.cpp"

int main() {
	// ejemplo b�sico de uso
	PALogger logger(PALogger::LogLevel::INFO, true, "aplicacionZ.log");
    Comunicacion_Archivo archivoLog("Log.csv");
	std::string message;
	
	logger.info(message = "Aplicacion iniciada.");
	archivoLog.add_record(message);
	std::cout << message << std::endl;

	logger.warning(message = "Este es un mensaje de advertencia.");
	archivoLog.add_record(message);
	std::cout << message << std::endl;

	logger.debug(message = "Caso util durante el desarrollo para saber que ocurre.");
	archivoLog.add_record(message);
	std::cout << message << std::endl;

	logger.error(message = "Se produjo un error inesperado.");
	archivoLog.add_record(message);
	std::cout << message << std::endl;

	logger.info(message = "Aplicacion finalizada."); 
	archivoLog.add_record(message);
	std::cout << message << std::endl;

	archivoLog.leerRegistros();
	std::cout<<std::endl<<"XML"<<std::endl;
	archivoLog.leerRegistros("xml");
	std::cout<<std::endl<<"JSON"<<std::endl;
	archivoLog.leerRegistros("json");
	archivoLog.escribirRegistros();

	return 0;
}
