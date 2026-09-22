#include "Mensaje.h"


Mensaje::Mensaje(int operacionEsperada){
    this -> modo = operacionEsperada;
}



/// 
/// Si contiene el parametro, devuelve el indice. Si no lo contiene, devuelve -1
/// @return int
/// @param  nombreParametro 
int Mensaje::obtenerIndice(std::string nombreParametro) const
{
    for (int i = 0; i < nombres.size(); i++)
    {
        if (nombreParametro == nombres [i])
        {
            return i;
        }
    }
    return -1;
}


/// 
/// Devuelve el valor interno del valor pedido
/// @return std::string
/// @param  nombreParametro 
std::string Mensaje::obtenerParametro(std::string nombreParametro) const
{
    int indice=obtenerIndice(nombreParametro);
    if (indice == -1)
    {
        throw std::runtime_error("Parametro No Encontrado");
    }
    return datos[indice];
}

std::string Mensaje::obtenerParametro(int indice) const
{
    return datos[indice];
}


/// 
/// Si el mensaje contenia el parametro, lo sobre-escribe, caso contrario lo añade
/// como parametro
/// @param  nombreParametro 
/// @param  informacionParametro 
void Mensaje::establecerParametro(std::string nombreParametro, std::string informacionParametro)
{
    //Estructura Switch por si acaso
    switch (modo)
    {
        case 0:
            {
            //Reaccion ante el metodo Lectura y Escritura
            int indice = obtenerIndice(nombreParametro);
            if (indice == -1)
            {
                nombres.push_back(nombreParametro);
                datos.push_back(informacionParametro);
            } else {
                datos[indice]=informacionParametro;
            }
            break;
            }
        default:
            {
            std::cerr<<"Intento de escritura en mensaje Sólo lectura"<<std::endl;
            break;
            }
    }
}


/// 
/// Funcion que devuelve todos los nombres de parametros disponibles
/// @return vector<string>
std::vector<std::string> Mensaje::listarParametros() const
{
    return nombres;
}

bool Mensaje::estaPresente(std::string nombreParametro) const{
    int valor=obtenerIndice(nombreParametro);
    if (valor==-1)
    {
        return false;
    }
    return true;
}

void Mensaje::establecerModo(int modo){
    this ->modo = modo;
}

