#include "gui/TelaTurmasProfessor.hpp"

namespace GUI{
    TelaTurmasProfessor::TelaTurmasProfessor(Modelo::Professor* professor){
        this->professor = professor;
    } 

    void TelaTurmasProfessor::show(){
        std::cout<<"Tela de turmas Professor\n";
    }

}