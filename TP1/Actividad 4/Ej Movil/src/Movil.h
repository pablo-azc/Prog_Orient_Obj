
#ifndef MOVIL_H
#define MOVIL_H

#include <string>
using namespace std;


class Movil
{
public:
  // Constructors/Destructors  

  /// 
  /// Ademas, permite especificar velocidades en X e Y
  /// @param  nombre 
  /// @param  vel_x 
  /// @param  vel_y 
  Movil(string nombre = "Generico", float vel_x = 0, float vel_y = 0);

  /// 
  /// Empty Constructor
  Movil();

  /// 
  /// Empty Destructor
  virtual ~Movil();

  // Public attributes  


  string Identificacion;


  /// 
  /// Devuelve 1 si está encendido con una velocidad distinta a 0
  /// @return bool
  bool estaMoviendose();


  /// 
  /// inicia el movimiento del movil. Si la velocidad es nula, devuelve 0
  /// @return bool
  bool encender();


  /// 
  /// detiene el vehiculo, pero mantiene la velocidad anterior en memoria
  void apagar();


  /// 
  /// @param  vel_x 
  /// @param  vel_y 
  void establecerVelocidad(float vel_x = 0, float vel_y = 0);


  /// 
  /// @param  tiempo tiempo a simular
  void simular(float tiempo);


  /// 
  /// @return cadena (string)
  string obtenerPosicion();


  /// 
  /// @return cadena (string)
  string obtenerVelocidad();

private:
  // Private attributes  


  // Estado del movil. 0 equivale a Detenido, 1 a Encendido  
  bool encendido;
  // Posicion en X en Metros  
  float posicion_x;
  // Posicion en Y en Metros  
  float posicion_y;
  // Velocidad en X en metros/seg  
  float velocidad_x;
  // Velocidad en Y en metros/seg  
  float velocidad_y;
  // contador de la distancia total recorrida (en valor absoluto)  
  float distanciaTotal;

  void initAttributes();

};

#endif // MOVIL_H
