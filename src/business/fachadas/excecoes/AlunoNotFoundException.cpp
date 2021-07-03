#include "business/fachadas/excecoes/AlunoNotFoundException.hpp"

namespace Business{
    AlunoNotFoundException::AlunoNotFoundException(){
        this->msg = "Aluno nao encontrado!";
    }

     AlunoNotFoundException::AlunoNotFoundException(const std::string& msg){
        this->msg = msg;
    }

    AlunoNotFoundException::~AlunoNotFoundException(){}

    const char* AlunoNotFoundException::what() const throw(){
         return this->msg.c_str();
    }
}