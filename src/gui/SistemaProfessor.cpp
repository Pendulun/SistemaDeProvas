#include "gui/SistemaProfessor.hpp"

namespace GUI{
    void SistemaProfessor::show(){
        std::cout<<"Mostrando sistema professor\n";
    }

    SistemaProfessor::SistemaProfessor(Modelo::Professor* professor){
        this->professor = professor;
    }

    SistemaProfessor::~SistemaProfessor(){
        std::cout<<"Destruindo Sistema Professor"<<std::endl;
        delete this->professor;
    }
}

