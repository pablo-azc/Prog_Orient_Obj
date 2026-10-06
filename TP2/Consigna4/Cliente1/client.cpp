/* client.cpp : codigo auxiliar para TP de un cliente XMLRPC con bucle.
   Uso: client Host Port
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "lib/XmlRpc.h"
using namespace XmlRpc;

#include "inc/funciones.h"

int main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Uso: miclient IP_HOST N_PORT\n";
    return -1;
  }
  
  int port = atoi(argv[2]);
  //XmlRpc::setVerbosity(5);

  XmlRpcClient c(argv[1], port);

  int cont = 0;
  
  funciones cliente(c);

  while(true){
    switch(cont){
      case 0:
        cliente.mostrarMetodos();
        break;
      case 1:
        cliente.Ayuda("Eco");
        break;
      case 2:
        cliente.serverTest();
        break;
      case 3:
        cliente.Eco("Pinocho");
        break;
      case 4:
        cliente.sumatoria({3.14,22,67});
        break;
      case 5:
        cliente.metodoInexistente();
        break;
      case 6:
        std::cout << "---------------------------------------------------------------------" << std::endl ;
        std::cout << "**************** Prueba de llamada a metodos multiples ***************" << std::endl;
        // En este caso se trata de argumento unico, un array de estructuras
        MultiCall multi1;
        multi1.añadirSuma({5,9});
        multi1.añadirEco("Juan");
        multi1.añadirSuma({10.5,12.5,-3.0});

        cliente.enviarMulticall(multi1.llamada());
        break;
    }
    cont++;
    if(cont==7) break;
  }

  return 0;
}
