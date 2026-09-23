
#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>


class Registro
{
public:
  /// 
  std::string convertirATexto(std::string formato="CSV");


  /// 
  /// @param  texto 
  void ConvertirDeTexto(std::string texto);

private:
  // Private attributes  


  std::string timestamp, type, menssage;

};

#endif // REGISTRO_H
