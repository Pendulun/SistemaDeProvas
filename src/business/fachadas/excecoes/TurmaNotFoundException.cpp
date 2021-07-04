#include "business/fachadas/excecoes/TurmaNotFoundException.hpp"

namespace Business{
    TurmaNotFoundException::TurmaNotFoundException(){
        this->msg = "Turma nao encontrada!";
    }

     TurmaNotFoundException::TurmaNotFoundException(const std::string& msg){
        this->msg = msg;
    }

    TurmaNotFoundException::~TurmaNotFoundException(){}

    const char* TurmaNotFoundException::what() const throw(){
         return this->msg.c_str();
    }
}