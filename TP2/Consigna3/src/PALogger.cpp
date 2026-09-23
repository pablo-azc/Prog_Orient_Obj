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

using namespace std;
	
	class PALogger {
	public:
		enum class LogLevel {
			DEBUG = 0,
			INFO,
			WARNING,
			ERROR
		};

		PALogger(const LogLevel &level, bool logToFile, const std::string& filename) 
			: level_(level), logToFile_(logToFile) {
			
			if (logToFile_) {
				logFile_.open(filename, std::ios::app); 
				if (!logFile_.is_open()) {
					std::cerr << "Error al abrir el archivo de log: " << filename << std::endl;
					std::cerr << "Se continua sin registro permanente. " << std::endl;
					logToFile_ = false;
				}
			}
		}
		
		~PALogger() {
			if (logToFile_) {
				if (logFile_.is_open()) {
					logFile_.close();
				}
			}
		}
		
		void debug(std::string& message) { log(LogLevel::DEBUG, message); }
		
		void info(std::string& message) { log(LogLevel::INFO, message); }
		
		void warning(std::string& message) { log(LogLevel::WARNING, message); }
		
		void error(std::string& message) { log(LogLevel::ERROR, message); }
		
	private:
		LogLevel level_;
		bool logToFile_;
		std::ofstream logFile_;
			
		void log(LogLevel level, std::string& message) {
			std::time_t now = std::time(0); // Hora actual
			std::tm timeinfo;
			localtime_r(&now, &timeinfo); 	// Lleva hora a local en timeinfo [POSIX]
			
			std::stringstream messageNew;
			messageNew << "[" << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S") << "] ";
			// tambien puede usar asctime_r(&timeinfo, buf) junto un char buffer[N];
			
			switch (level) {
			case LogLevel::DEBUG:
				messageNew << "[DEBUG] ";
				break;
			case LogLevel::INFO:
				messageNew << "[INFO] ";
				break;
			case LogLevel::WARNING:
				messageNew << "[WARNING] ";
				break;
			case LogLevel::ERROR:
				messageNew << "[ERROR] ";
				break;
			}

			messageNew << message;
			message = messageNew.str();

			if (level < level_) {
				return;
			}
			
			if (logToFile_) {
				if (!logFile_.is_open()) {
					std::cerr << "El archivo de log no esta abierto." << std::endl;
					return;
				}
				
				logFile_ << message << std::endl;
			}			
		}
};



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


/*
Observar
1) Uso de una clase de enumeracion como atributo
   formas PALogger::LogLevel::DEBUG y LogLevel::DEBUG segun ambito
2) uso de argumento string& message
   como mecanismo para modificar el contenido de presentacion y separar capas
3) creacion validada del recurso archivo, dentro del constructor
4) cierre de archivo en el destructor
*/