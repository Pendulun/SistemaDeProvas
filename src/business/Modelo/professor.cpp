#include "business/Modelo/professor.hpp"

namespace Modelo{
    void Professor::adicionarTurma(Turma turma){
        this->turmas.push_back(turma);
    }

    void Professor::removerTurma(int id){
        std::list<Turma>::iterator turmaIterator;
        for(turmaIterator = this->turmas.begin(); turmaIterator != this->turmas.end(); turmaIterator++){
            if(turmaIterator->getId() == id){
                this->turmas.erase(turmaIterator);
                break;
            }
        }
    }
}