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
	std::cout << message << std::endl;

	logger.warning(message = "Este es un mensaje de advertencia.");
	std::cout << message << std::endl;

	logger.debug(message = "Caso util durante el desarrollo para saber que ocurre.");
	std::cout << message << std::endl;

	logger.error(message = "Se produjo un error inesperado.");
	std::cout << message << std::endl;

	logger.info(message = "Aplicacion finalizada."); 
	std::cout << message << std::endl;

	return 0;
}
