
#include <exception>
#include <iostream>

class ErrorParametro : public std::invalid_argument {
public:
    explicit ErrorParametro(const std::string& msg) 
        : std::invalid_argument("Error de Parámetro: " + msg) {}
};

class ErrorConexion : public std::runtime_error {
public:
    explicit ErrorConexion(const std::string& msg) 
        : std::runtime_error("Error de Red/Conexión: " + msg) {}
};

class ErrorRpc : public std::runtime_error {
public:
    explicit ErrorRpc(const std::string& msg) 
        : std::runtime_error("Error Servidor RPC: " + msg) {}
};