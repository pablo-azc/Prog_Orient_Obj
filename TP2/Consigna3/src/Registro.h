
#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>


class Registro
{
public:
  /// 

  Registro(){};
  Registro(std::string timestamp,std::string tipo,std::string modulo,std::string mensaje,
  int disp=-1, int client=-1);

  std::string convertirATexto(std::string formato="CSV");


  /// 
  /// @param  texto 
  void ConvertirDeTexto(std::string texto);

private:
  // Private attributes  


  std::string timestamp, type,modulo, menssage;
  int ID_disp,ID_client;
};

#endif // REGISTRO_H
