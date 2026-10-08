#include <iostream>
#include <stdlib.h>
#include "../lib/XmlRpc.h"
#include "funciones.h"

funciones::funciones(XmlRpc::XmlRpcClient &c){
    this->c = &c;
}

void funciones::mostrarMetodos(){
    XmlRpc::XmlRpcValue noArgs, result;
    std::cout << "---------------------------------------------------------------------" << std::endl ;
    std::cout << "*********** Una mirada a los metodos soportados por la API **********" << std::endl ;
    if (c->execute("system.listMethods", noArgs, result))
        std::cout << "\nMetodos:\n " << result << "\n\n";
    else
        std::cout << "Error en la llamada a 'listMethods'\n\n";
}

void funciones::Ayuda(std::string funcion){
    std::cout << "---------------------------------------------------------------------" << std::endl ;
    std::cout << "****** Peticion para recuperar una ayuda sobre el metodo" << funcion << "******" << std::endl ;
    oneArg[0] = funcion;
    if (c->execute("system.methodHelp", oneArg, result))
        std::cout << "Ayuda para el metodo "<<funcion<<": " << result << "\n\n";
    else
        std::cout << "Error en la llamada a 'methodHelp'\n\n";
}

void funciones::serverTest(){
    std::cout << "---------------------------------------------------------------------" << std::endl ;
    std::cout << "********************** Llamada al metodo ServerTest **********************" << std::endl ;
    if (c->execute("ServerTest", noArgs, result))
        std::cout << result << "\n\n";
    else
        std::cout << "Error en la llamada a 'ServerTest'\n\n";
}

void funciones::Eco(std::string texto){
    std::cout << "---------------------------------------------------------------------" << std::endl ;
    std::cout << "******************* Llamada al metodo Eco *******************" << std::endl ;
    oneArg[0] = texto;
    if (c->execute("Eco", oneArg, result))
        std::cout << result << "\n\n";
    else
        std::cout << "Error en la llamada a 'Eco'\n\n";
}

double funciones::sumatoria(std::vector<float> lista){
    std::cout << "---------------------------------------------------------------------" << std::endl ;
    std::cout << "****************** Llamada con un array de numeros *******************" << std::endl ;
    
    for (int i = 0; i < lista.size(); i++)
    {
        numbers[i] = lista[i];
    }
    std::cout << "numbers.size() is " << numbers.size() << std::endl;
    if (c->execute("Sumar", numbers, result)){
        std::cout << "Suma = " << double(result) << "\n\n";
        return double(result);
    }else{
        std::cout << "Error en la llamada a 'Sumar'\n\n";
        return 0;
    }
}

void funciones::metodoInexistente(){
    std::cout << "---------------------------------------------------------------------" << std::endl ;
    std::cout << "*********** Prueba de fallo por llamada a metodo inexistente *********" << std::endl ;        
    if (c->execute("MetodoX", numbers, result)){
        std::cout << "Llamada a MetodoX: fallo: " << c->isFault() << std::endl; 
        std::cout << "  con resultado = " << result << std::endl;
    }
    else
        std::cout << "Error en la llamada a 'MetodoX'\n";
}

void funciones::enviarMulticall(XmlRpc::XmlRpcValue multicall){
    if (c->execute("system.multicall", multicall, result))
          std::cout << "\nResultado multicall = " << result << std::endl;
        else
          std::cout << "\nError en la llamada a 'system.multicall'\n";
}

XmlRpc::XmlRpcValue MultiCall::llamada(){
    return this->multicall;
}

void MultiCall::añadirSuma(std::vector<float> lista){
    multicall[0][indice]["methodName"] = "Sumar";
    for (int i = 0; i < lista.size(); i++)
    {
        multicall[0][indice]["params"][i] = lista[i];
    }
    indice++;
}

void MultiCall::añadirEco(std::string text){
    multicall[0][indice]["methodName"] = "Eco";
    multicall[0][indice]["params"][0] = text;
    indice++;
}