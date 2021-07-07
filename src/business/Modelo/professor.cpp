#include "business/Modelo/professor.hpp"
#include "business/fachadas/manterTurma.hpp"

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

    void Professor::finalizarDisponibilidadeProva(int id){
        Business::ManterTurma manterTurma;
        for (std::list<int>::iterator it = this->turmas.begin(); it != this->turmas.end(); ++it){
            Turma* t=manterTurma.pesquisarTurma(*it);
            Prova* p=t->getProvaPorID(id);
            if (p!=nullptr){
                p->setStatus(Status::FINISHED);
                break;
            }
        }
    }
}