#include "../lib/XmlRpc.h"

#include <iostream>
#include <stdlib.h>
#include "funcionalidades.h"

//Funciones de ServerTest

funciones::ServerTest::ServerTest(XmlRpc::XmlRpcServer* S) : XmlRpc::XmlRpcServerMethod("ServerTest", S) {}

void funciones::ServerTest::execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result)
{
    result = "Hi, soy el servidor RPC !!";
}

std::string funciones::ServerTest::help() { return std::string("Respondo quien soy cuando no hay argumentos"); }



// Funciones de ECO
// Con un argumento, el resultado es "Hola, " + argumento + argumento
funciones::Eco::Eco(XmlRpc::XmlRpcServer* S) : XmlRpc::XmlRpcServerMethod("Eco", S) {}

void funciones::Eco::execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result)
  {
    std::string resultString = "Hola, ";
    resultString += std::string(params[0]);
    resultString += std::string(" ");
    resultString += std::string(params[0]);
    result = resultString;
  }

std::string funciones::Eco::help() { return std::string("Diga algo y recibira un saludo"); }


// Funciones de SUMAR
// Con un numero variable de argumentos, todos dobles, el resultado es la suma
funciones::Sumar::Sumar(XmlRpc::XmlRpcServer* S) : XmlRpc::XmlRpcServerMethod("Sumar", S) {}

void funciones::Sumar::execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result)
  {
    int nArgs = params.size();
    double sum = 0.0;
    for (int i=0; i<nArgs; ++i)
      sum += double(params[i]);
    result = sum;
  }

std::string funciones::Sumar::help() { return std::string("Indique varios numeros reales separados por espacio"); }