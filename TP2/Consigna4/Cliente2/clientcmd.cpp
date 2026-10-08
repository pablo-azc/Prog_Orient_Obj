/* clientcmd.cpp : codigo fuente para TP de un cliente XMLRPC de prueba basica.
   Uso: clientcmd Host Port [otros_argumentos]
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

#include "lib/XmlRpc.h"
using namespace XmlRpc;
#include "inc/funciones.h"
// Se puede recibir por linea de argumentos una cadena vacia,
// una cadena alfanumerica, un conjunto de numeros reales
// 2 cadenas siendo la primera la palabra help


// Verifica si la cadena es un entero valido
bool esEntero(const std::string& s) {
    if (s.empty()) return false;

    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i = 1; // permitir signo

    if (i == s.size()) return false; // solo un signo no es válido

    for (; i < s.size(); ++i) {
        if (!isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

// Verifica si la cadena es una dirección IPv4 válida
bool esIP(const std::string& s) {
    std::stringstream ss(s);
    std::string segmento;
    int count = 0;

    while (getline(ss, segmento, '.')) {
        if (!esEntero(segmento)) return false;

        int valor = stoi(segmento);
        if (valor < 0 || valor > 255) return false;

        count++;
    }

    return (count == 4);
}

// Verificar si es alfanumerica (sin espacios, solo letras o digitos)
bool esAlfanumerica(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isalnum(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

// Verificar si una cadena es un numero real
bool esReal(const std::string& s) {
    try {
        size_t pos;
        std::stod(s, &pos);       // convierte a double
        return pos == s.size(); // true si se consumio toda la cadena
    }
    catch (...) {
        return false; // excepcion => no es un numero valido
    }
}

// Verificar si todos los tokens son numeros reales
bool sonNumerosReales(const std::vector<std::string>& tokens, std::vector<float> &salida) {
  for (size_t i = 3; i < tokens.size(); ++i) {
      if(!esReal(tokens[i])) return false;
      salida[i-3]=std::stof(tokens[i]);
  }
  
  return true;
}



int main(int argc, char* argv[])
{
  std::vector<std::string> args(argv, argv + argc);
  int port;
  const char* ip; // string

  std::vector<float> temporal;

  if (argc < 3) {
    std::cerr << "Modo de Uso: clientcmd25 IP_HOST N_PORT otros_argumentos\n";
    std::cerr << "o bien: clientcmd25 IP_HOST N_PORT help nombre_servicio\n";
    return -1;
  }

  for (size_t i = 0; i < args.size(); ++i) {
    std::cout << "Arg " << i << ": " << args[i] << "\n";
  }

  if(esIP(args[1])){
    ip = args[1].c_str();
  }
  else {
    std::cerr << "No corresponde a un IP valido\n";
    return -1;
  }

  if(esEntero(args[2])){
    port = atoi(args[2].c_str());
  }
  else {
    std::cerr << "El port debe ser un entero\n";
    return -1;
  }

  XmlRpcClient c(ip, port);

  funciones Cliente(c);

  if(args.size()==3){
        cout << "Caso 1: Cadena vacia\n";
        Cliente.serverTest();
        return 0;
  }

  if(args.size()==4 && esAlfanumerica(args[3])) {
        cout << "Caso 2: Una cadena alfanumerica sin espacios '" << args[3] << "'\n";
        Cliente.Eco(args[3]);
        return 0;
    }

  if (args.size()>=4 && sonNumerosReales(args,temporal)) {
      cout << "Caso 3: Conjunto de números reales [";
      for (size_t i = 3; i < args.size(); ++i) {
          cout << args[i] << (i + 1 < args.size() ? ", " : "");
      }
      Cliente.sumatoria(temporal);
      return 0;
  }

  if (args.size()==5 && args[3] == "help") {
      cout << "Caso 4: Solicitud de Help para el servicio '" << args[4] << "'\n";
    std::cout << "****** Llamada a help ******" << std::endl ;
      Cliente.Ayuda(args[4]);
  }

  // Ningún caso coincide
  cout << "Entrada no reconocida.\n";
  return 0;
}
