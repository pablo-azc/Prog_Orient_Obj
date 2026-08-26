
#ifndef COMUNICACION_ARCHIVO_H
#define COMUNICACION_ARCHIVO_H

#include <string>
#include <vector>
#include "Registro.h"


class Comunicacion_Archivo
{
public:
  // Public attributes  


  std::string nombreArchivo;


  /// 
  /// @param  aIncluir 
  void add_record(Registro aIncluir);


  /// 
  /// @return bool
  bool leerRegistros();


  /// 
  /// @param  nombre 
   Comunicacion_Archivo(std::string nombre = "texto.txt");


  /// 
  /// @return bool
  bool escribirRegistros();

private:
  // Private attributes  


  std::string timestamp;
  int size;
  std::vector<Registro> registros;

};

#endif // COMUNICACION_ARCHIVO_H
