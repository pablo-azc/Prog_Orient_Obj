#include "Movil.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    ///Definir posiciones iniciales
    vector<Movil> Moviles;
    Moviles.push_back(Movil("A"));
    Moviles.push_back(Movil("B",2,-2));
    Moviles.push_back(Movil("C",1,-1));

    ///Comprobacion de estado detenido: Prueba si inician detendios y sin posicion
    for (int i = 0; i < 3; i++)
    {
        Moviles[i].simular(2);
        cout<<endl<<"Datos del Movil "<<Moviles[i].Identificacion<<":"<<endl;
        Moviles[i].obtenerPosicion();
        Moviles[i].obtenerVelocidad();
        Moviles[i].obtenerDistanciaTotal();
    }
    cout<<"+--------------------------------------------------+"<<endl;
    ///Primera Iteracion: Prueba si funciona
    for (int i = 0; i < 3; i++)
    {
        Moviles[i].establecerVelocidad(2*(i-1),1);
        Moviles[i].encender();
        Moviles[i].simular(2);
        cout<<endl<<"Datos del Movil "<<Moviles[i].Identificacion<<":"<<endl;
        Moviles[i].obtenerPosicion();
        Moviles[i].obtenerVelocidad();
        Moviles[i].obtenerDistanciaTotal();
    }

    ///Segunda iteracion: prueba si simula con moviles apagados
    cout<<"+--------------------------------------------------+"<<endl;
    for (int i = 0; i < 3; i++)
    {
        Moviles[i].apagar();
        Moviles[i].simular(2);
        cout<<endl<<"Datos del Movil "<<Moviles[i].Identificacion<<":"<<endl;
        Moviles[i].obtenerPosicion();
        Moviles[i].obtenerVelocidad();
        Moviles[i].obtenerDistanciaTotal();
    }
    return 0;
}