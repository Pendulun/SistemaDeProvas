#include "gui/SistemaAluno.hpp"

namespace GUI{
    void SistemaAluno::show(){
        std::cout<<"Mostrando sistema Aluno\n";
    }

    SistemaAluno::SistemaAluno(Modelo::Aluno* aluno){
        this->aluno = aluno;
    }

    SistemaAluno::~SistemaAluno(){
        std::cout<<"Destruindo Sistema Aluno"<<std::endl;
        delete this->aluno;
    }
}

