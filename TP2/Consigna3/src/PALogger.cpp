/*
 Clase PALogger que registra eventos y los almacena en un archivo,
 haciendo uso interno de ofstream para la escritura.
 Clase sin modularizar sin header ni optimizaciones especiales.
 Gestiona mensajes de 4 tipos: depuracion, informacion, advertencia y error
 debug, info, warning, error: metodos para registrar mensajes con diferentes nivel.
 Pendiente el agregado de metodo para fallos criticos.
 log (privado): metodo interno a la clase, que da formato y guarda al mensaje.
 LogLevel enum: sirve para definir los diferentes niveles de registro.
 level_: atributo que evita el registro de los mensajes por debajo de el.
 logToFile_: atributo que indica si se generan mensajes para registro en
 archivo o s�lo para salida en la interfaz de usuario.
 El formato de los mensajes es fijo. Sin embargo, admite la actualizaci�n de
 los mensajes al formato de registro. Mejoraria con un metodo de personalizacion,
 por ejemplo setFormat().
 El control de errores por apertura y existencia del archivo deberia 
 hacerse usando excepciones.
 Deberia revisarse la conveniencia del cambio automatico de logToFile a false.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
//Modificado: inclusion de Comunicación_archivo
#include "Comunicacion_Archivo.h"
#include "Registro.h"

using namespace std;
	
	class PALogger {
	public:
		enum class LogLevel {
			DEBUG = 0,
			INFO,
			WARNING,
			ERROR
		};

		//NUEVO: muestra los registros: No es mas que un handle a la función de Comunic_archivo
		void leerRegistros(std::string Modo = "CSV"){
			archivo_->leerRegistros(Modo);
		}

		PALogger(const LogLevel &level, bool logToFile,const std::string& module = "General", const std::string& filename = "Log.log") 
			: level_(level), logToFile_(logToFile) {
			
			this->modulo_=module;
			if (logToFile_) {
				archivo_=new Comunicacion_Archivo(filename); 
			}
		}
		
		~PALogger() {
			archivo_->escribirRegistros();
		}
		
		void debug(std::string& message, int id_d = -1, int id_u = -1) { log(LogLevel::DEBUG, message,id_d,id_u); }
		
		void info(std::string& message, int id_d = -1, int id_u = -1) { log(LogLevel::INFO, message,id_d,id_u); }
		
		void warning(std::string& message, int id_d= -1, int id_u = -1) { log(LogLevel::WARNING, message,id_d,id_u); }
		
		void error(std::string& message, int id_d = -1, int id_u = -1) { log(LogLevel::ERROR, message,id_d,id_u); }
		
	private:
		LogLevel level_;
		bool logToFile_;
		std::ofstream logFile_;
		Comunicacion_Archivo* archivo_;
		std::string modulo_;
			
		void log(LogLevel level, std::string& message, int id_dispositivo = -1, int id_usuario = -1) {
			
			if (level < level_) {
				return;
			}

			std::time_t now = std::time(0); // Hora actual
			std::tm timeinfo;
			localtime_r(&now, &timeinfo); 	// Lleva hora a local en timeinfo [POSIX]
			
			std::stringstream tiempo;
			tiempo << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
			std::string tipo;
			switch (level) {
			case LogLevel::DEBUG:
				tipo = "DEBUG";
				break;
			case LogLevel::INFO:
				tipo = "INFO";;
				break;
			case LogLevel::WARNING:
				tipo = "WARN";
				break;
			case LogLevel::ERROR:
				tipo = "ERROR";
				break;
			}
			

			Registro temporal(tiempo.str(),tipo,modulo_,message,id_dispositivo,id_usuario);
			archivo_->add_record(temporal);
			
		}
};


/*
int main() {
	// ejemplo b�sico de uso
	PALogger logger(PALogger::LogLevel::INFO, true, "aplicacionZ.log");
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
*/

/*
Observar
1) Uso de una clase de enumeracion como atributo
   formas PALogger::LogLevel::DEBUG y LogLevel::DEBUG segun ambito
2) uso de argumento string& message
   como mecanismo para modificar el contenido de presentacion y separar capas
3) creacion validada del recurso archivo, dentro del constructor
4) cierre de archivo en el destructor
*/