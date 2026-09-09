#include <iostream>
#include "src/Nodo_A.h"
using namespace std;


int main(){
    Nodo_A Nodo1;
    Nodo_A Nodo2;

    Nodo1.setMemoria("Pablo Azcurra",14100,512,3.1415,14100,1);
    Nodo2.RecibirMensaje(Nodo1.EnviarMensaje());
    Nodo2.MostrarTodo();
    cout<<endl;
    Nodo1.setMemoria("Test2",141,51,4.5,14100,2);
    Nodo2.RecibirMensaje(Nodo1.EnviarMensaje());
    Nodo2.MostrarTodo();
    cout<<endl;
    Nodo1.setMemoria("Test3",1413,5,67,14100,3);
    Nodo2.RecibirMensaje(Nodo1.EnviarMensaje());
    Nodo2.MostrarTodo();
    cout<<endl;

    return 0;
}