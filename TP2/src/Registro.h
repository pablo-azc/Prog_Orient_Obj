
#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>


class Registro
{
public:
  /// 
  std::string convertirATexto();


  /// 
  /// @param  texto 
  void ConvertirDeTexto(std::string texto);

private:
  // Private attributes  

  std::string id;
  std::string timestamp;
  double posicion_x;
  double posicion_y;
  double velocidad_x;
  double velocidad_y;
  double dist_total;
  bool estatus;
  int sample;

};

#endif // REGISTRO_H
