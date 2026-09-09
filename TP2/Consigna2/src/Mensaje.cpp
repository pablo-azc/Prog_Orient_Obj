#include "Mensaje.h"


// Methods


// Accessor methods



// Other methods



/// 
/// Si contiene el parametro, devuelve el indice. Si no lo contiene, devuelve 0
/// @return int
/// @param  nombreParametro 
int Mensaje::contieneParametro(std::string nombreParametro)
{
}


/// 
/// Devuelve el valor interno del valor pedido
/// @return std::string
/// @param  nombreParametro 
std::string Mensaje::obtenerParametro(std::string nombreParametro)
{
}


/// 
/// Si el mensaje contenia el parametro, lo sobre-escribe, caso contrario lo añade
/// como parametro
/// @param  nombreParametro 
/// @param  informacionParametro 
void Mensaje::establecerParametro(std::string nombreParametro, std::string informacionParametro)
{
}


/// 
/// Funcion que devuelve todos los nombres de parametros disponibles
/// @return vector<string>
std::vector<std::string> Mensaje::listarParametros()
{
}


/// 
/// @param  nombreParametro 
void Mensaje::eliminarParametro(std::string nombreParametro)
{
}


