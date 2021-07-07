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

    Prova* Aluno::findProvaPorID(int idTurma,int idProva){
        Business::ManterTurma manterTurma;
        Turma* t=manterTurma.pesquisarTurma(idTurma);
        return t->getProvaPorID(idProva);
    }

    void Aluno::submeterTentativa(int idTurma,int idProva,ProvaResolvida respostas){
        Prova* p=this->findProvaPorID(idTurma,idProva);
        if(p!=nullptr){
            p->submeterProva(this->id,respostas);
        }
    }

    int Aluno::getPontuacaoEmProva(int idTurma,int idProva){
        Prova* p=this->findProvaPorID(idTurma,idProva);
        if(p!=nullptr){
            return p->notaDeTentativaDoAluno(this->id); //retorna -1 se não foi encontrada uma submissão já corrigida
        }
        return -1;
    }
}