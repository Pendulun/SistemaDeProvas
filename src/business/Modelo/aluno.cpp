#include "business/Modelo/aluno.hpp"
#include "business/fachadas/manterTurma.hpp"


namespace Modelo{
    bool Aluno::isEmTurma(int idTurma){
        for(int idMinhaTurma : this->turmas){
            if(idMinhaTurma==idTurma){
                return true;
            }
        }

        return false;
    }

    void Aluno::adicionarTurma(int idTurma){
        if(!this->isEmTurma(idTurma)){
            this->turmas.push_back(idTurma);
        }
    }

    void Aluno::removerTurma(int id){
        std::list<int>::iterator turmaIterator;
        for(turmaIterator = this->turmas.begin(); turmaIterator != this->turmas.end(); turmaIterator++){
            if(*turmaIterator == id){
                this->turmas.erase(turmaIterator);
                break;
            }
        }
    }

    void Aluno::submeterTentativa(int idTurma,int idProva,ProvaResolvida respostas){
        Business::ManterTurma manterTurma;
        Turma* t=manterTurma.pesquisarTurma(idTurma);
        Prova* p=t->getProvaPorID(idProva);
        p->submeterProva(this->id,respostas);
    }
}