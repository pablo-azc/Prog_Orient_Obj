#include "../lib/XmlRpc.h"

#include <iostream>
#include <stdlib.h>
class funciones{
    public:
    // Sin argumentos, el resultado es "Hi, soy el servidor RPC !!".
    class ServerTest : public XmlRpc::XmlRpcServerMethod
    {
    public:
        ServerTest(XmlRpc::XmlRpcServer* S);

        void execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result);

        std::string help();
    };

    // Con un argumento, el resultado es "Hola, " + argumento + argumento
    class Eco : public XmlRpc::XmlRpcServerMethod
    {
    public:
        Eco(XmlRpc::XmlRpcServer* S);

        void execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result);

        std::string help();
    };


    // Con un numero variable de argumentos, todos dobles, el resultado es la suma
    class Sumar : public XmlRpc::XmlRpcServerMethod
    {
    public:
        Sumar(XmlRpc::XmlRpcServer* S);

        void execute(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result);

        std::string help();
    };
};