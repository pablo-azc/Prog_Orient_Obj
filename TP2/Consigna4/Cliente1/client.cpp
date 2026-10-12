/* client.cpp : codigo auxiliar para TP de un cliente XMLRPC con bucle.
   Uso: client Host Port
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "lib/XmlRpc.h"
using namespace XmlRpc;

#include "inc/funciones.h"
#include "inc/excepcionesRed.h"

int main(int argc, char* argv[])
{
  XmlRpcClient* clienteRPC;
  try
  {
    if (argc != 3) {
      throw ErrorParametro("Uso: Cliente IP_SERVIDOR PUERTO");
    }
  
    int port = atoi(argv[2]);
    //XmlRpc::setVerbosity(5);

    clienteRPC = new XmlRpcClient(argv[1], port);
    
  
  }
  catch(const ErrorParametro& e)
  {
    std::cerr << e.what() << '\n';
    return -1;
  }
  catch(const std::exception& e){
    std::cerr << "Error durante la ejecución: " << e.what() << '\n';
    return -1;
  }

  int cont = 0;

  funciones cliente(*clienteRPC);
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
