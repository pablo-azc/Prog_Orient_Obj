/* server.cpp : codigo base para el TP sobre servidor XMLRPC
*/

#include "lib/XmlRpc.h"
using namespace XmlRpc;

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "inc/funcionalidades.h"

int main(int argc, char* argv[])
{
  //Comentarios de inicialización
  if (argc != 2) {
    std::cerr << "Uso: miserver N_Port\n";
    return 1;
  }
  int port = atoi(argv[1]);

  // S es el servidor
  XmlRpcServer S;

  // Registro de metodos en el servidor
  // mediante el uso del constructor heredado.
  // Cada clase modela un metodo, implementado en execute().
  // Cada clase admite una ayuda, en help().
  ServerTest serverTest(&S);
  Eco eco(&S);
  Sumar sumar(&S);

  XmlRpc::setVerbosity(5);

  // Se crea un socket de servidor sobre el puerto indicado
  S.bindAndListen(port);

  // Enable introspection
  S.enableIntrospection(true);

  // A la escucha de requerimientos
  S.work(-1.0);

  return 0;
}
