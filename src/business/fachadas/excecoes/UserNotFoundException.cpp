#include "business/fachadas/excecoes/UserNotFoundException.hpp"

namespace Business{
    UserNotFoundException::UserNotFoundException(){
        this->msg = "Usuario nao encontrado!";
    }

     UserNotFoundException::UserNotFoundException(const std::string& msg){
        this->msg = msg;
    }

    UserNotFoundException::~UserNotFoundException(){}

    const char* UserNotFoundException::what() const throw(){
         return this->msg.c_str();
    }
}