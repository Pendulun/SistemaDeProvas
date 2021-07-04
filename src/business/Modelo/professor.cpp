#include "business/Modelo/professor.hpp"

namespace Modelo{

    bool Professor::possuiTurma(const int idTurma){
        for(int idMinhaTurma : this->turmas){
            if(idMinhaTurma == idTurma){
                return true;
            }
        }

        return false;
    }

    void Professor::adicionarTurma(int idTurma){
        if(!this->possuiTurma(idTurma)){
            this->turmas.push_back(idTurma);
        }
    }

    void Professor::removerTurma(int id){
        std::list<int>::iterator turmaIterator;
        for(turmaIterator = this->turmas.begin(); turmaIterator != this->turmas.end(); turmaIterator++){
            if(*turmaIterator == id){
                this->turmas.erase(turmaIterator);
                break;
            }
        }
    }
}