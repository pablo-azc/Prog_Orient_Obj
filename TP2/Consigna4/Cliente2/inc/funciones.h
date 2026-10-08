#include <iostream>
#include <stdlib.h>
#include "../lib/XmlRpc.h"

class funciones
{
private:
    XmlRpc::XmlRpcClient *c;
    XmlRpc::XmlRpcValue noArgs, result;
    XmlRpc::XmlRpcValue oneArg;
    XmlRpc::XmlRpcValue numbers;
    
public:
    funciones(XmlRpc::XmlRpcClient &c);
    void mostrarMetodos();
    void Ayuda(std::string funcion);
    void serverTest();
    void Eco(std::string texto);
    double sumatoria(std::vector<float> lista);
    void metodoInexistente(); 
    void enviarMulticall(XmlRpc::XmlRpcValue multicall);
};

class MultiCall
{
private:
    XmlRpc::XmlRpcValue multicall;
    int indice;
public:
    void añadirSuma(std::vector<float> lista);
    void añadirEco(std::string text);
    XmlRpc::XmlRpcValue llamada();
};



