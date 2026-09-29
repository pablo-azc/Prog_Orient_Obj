#include <iostream>
#include "src/Nodo_A.h"
#include "src/Nodo_B.h"

using namespace std;

int main(){

    Nodo_A Nodo1;
    Nodo_B Nodo2;

    //Prueba: de nodo A a nodo B
    cout<<endl<<"Prueba:Mensaje del nodo A al nodo B"<<endl<<endl;
    Nodo1.setMemoria("Pablo Azcurra",14100,512,3.1415,1);
    Nodo2.RecibirMensaje(Nodo1.EnviarMensaje());
    cout<<"Memoria del Nodo B"<<endl;
    Nodo2.MostrarTodo();
    cout<<endl;

    //Prueba: Un segundo mensaje de Nodo A a Nodo B
    cout<<endl<<"Prueba:Segundo Mensaje del nodo A al nodo B"<<endl<<endl;
    Nodo1.setMemoria("Test1",2100,65,2.1718,2);
    Nodo2.RecibirMensaje(Nodo1.EnviarMensaje());
    cout<<"Memoria del Nodo B"<<endl;
    Nodo2.MostrarTodo();
    cout<<endl;

    //Prueba: de nodo B a Nodo A
    cout<<endl<<"Prueba:Mensaje del nodo B al nodo A"<<endl<<endl;
    Nodo2.setMemoria("Test2",141,51,4.5,2);
    Nodo1.RecibirMensaje(Nodo2.EnviarMensaje());
    cout<<"Memoria del Nodo A:"<<endl;
    Nodo1.MostrarTodo();
    cout<<endl;

    //Prueba: de nodo B a Nodo A con IDS incorrectas
    cout<<endl<<"Prueba:Mensaje del nodo B al nodo A, pero con una ID incorrecta"<<endl<<endl;
    Nodo2.setMemoria("Test3",400,47,4.6,3,1000,1000);
    cout<<"Memoria del Nodo A"<<endl;
    Nodo1.RecibirMensaje(Nodo2.EnviarMensaje());
    Nodo1.MostrarTodo();
    cout<<endl;

    return 0;
}