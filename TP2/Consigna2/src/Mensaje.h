
#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
#include <vector>


class Mensaje
{
public:
  /// 
  /// Si contiene el parametro, devuelve el indice. Si no lo contiene, devuelve 0
  /// @return int
  /// @param  nombreParametro 
  int contieneParametro(std::string nombreParametro);


  /// 
  /// Devuelve el valor interno del valor pedido
  /// @return std::string
  /// @param  nombreParametro 
  std::string obtenerParametro(std::string nombreParametro);


  /// 
  /// Si el mensaje contenia el parametro, lo sobre-escribe, caso contrario lo añade
  /// como parametro
  /// @param  nombreParametro 
  /// @param  informacionParametro 
  void establecerParametro(std::string nombreParametro, std::string informacionParametro);


  /// 
  /// Funcion que devuelve todos los nombres de parametros disponibles
  /// @return vector<string>
  std::vector<std::string> listarParametros();


  /// 
  /// @param  nombreParametro 
  void eliminarParametro(std::string nombreParametro);

private:
  // Private attributes  


  std::vector<std::string> nombres;
  std::vector<std::string> datos;

};

#endif // MENSAJE_H
