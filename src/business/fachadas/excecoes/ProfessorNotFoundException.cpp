#include "business/fachadas/excecoes/ProfessorNotFoundException.hpp"

namespace Business{
    ProfessorNotFoundException::ProfessorNotFoundException(){
        this->msg = "Professor nao encontrado!";
    }

     ProfessorNotFoundException::ProfessorNotFoundException(const std::string& msg){
        this->msg = msg;
    }

    ProfessorNotFoundException::~ProfessorNotFoundException(){}

    const char* ProfessorNotFoundException::what() const throw(){
         return this->msg.c_str();
    }
}