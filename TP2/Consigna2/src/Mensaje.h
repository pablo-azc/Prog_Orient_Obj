
#ifndef MENSAJE_H
#define MENSAJE_H

#include cadena (string)
#include vector


class Mensaje
{
public:
  /// 
  /// Si contiene el parametro, devuelve el indice. Si no lo contiene, devuelve 0
  /// @return int
  /// @param  nombreParametro 
  int contieneParametro(cadena (string) nombreParametro);


  /// 
  /// Devuelve el valor interno del valor pedido
  /// @return cadena (string)
  /// @param  nombreParametro 
  cadena (string) obtenerParametro(cadena (string) nombreParametro);


  /// 
  /// Si el mensaje contenia el parametro, lo sobre-escribe, caso contrario lo añade
  /// como parametro
  /// @param  nombreParametro 
  /// @param  informacionParametro 
  void establecerParametro(cadena (string) nombreParametro, cadena (string) informacionParametro);


  /// 
  /// Funcion que devuelve todos los nombres de parametros disponibles
  /// @return vector<string>
  vector<string> listarParametros();


  /// 
  /// @param  nombreParametro 
  void eliminarParametro(cadena (string) nombreParametro);

private:
  // Private attributes  


  vector<string> nombres;
  vector<string> datos;

};

#endif // MENSAJE_H
