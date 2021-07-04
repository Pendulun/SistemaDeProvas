#include "business/Modelo/aluno.hpp"

namespace Modelo{
    bool Aluno::isEmTurma(int idTurma){
        for(Turma turma : this->turmas){
            if(turma.getId()==idTurma){
                return true;
            }
        }

        return false;
    }

    void Aluno::adicionarTurma(Turma turma){
        if(!this->isEmTurma(turma.getId())){
            this->turmas.push_back(turma);
        }
    }

    void Aluno::removerTurma(int id){
        std::list<Turma>::iterator turmaIterator;
        for(turmaIterator = this->turmas.begin(); turmaIterator != this->turmas.end(); turmaIterator++){
            if(turmaIterator->getId() == id){
                this->turmas.erase(turmaIterator);
                break;
            }
        }
    }
}