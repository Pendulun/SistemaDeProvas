#include "business/fachadas/manterTurma.hpp"

namespace Business{

    bool ManterTurma::cadastrarTurma(Modelo::Turma turma, Modelo::Professor* professor){
        int idTurmaCadastrada = -1;
        std::list<Modelo::Turma> listaTurmasProfessor;
        listaTurmasProfessor = Business::Application::getInstance()->getTurmaDAO()->pesquisar(professor->getTurmas());
        for(Modelo::Turma turmaProf : listaTurmasProfessor){
            if(turmaProf.getNome().compare(turma.getNome())==0){
                return false;
            }
        }
        idTurmaCadastrada = Business::Application::getInstance()->getTurmaDAO()->cadastrar(turma);
        if(idTurmaCadastrada >=0){
            professor->adicionarTurma(idTurmaCadastrada);
            Business::ManterUsuario manterUsuario;
            manterUsuario.atualizar(*professor);
            return true;
        }else{
            return false;
        }
    }

    Modelo::Turma* ManterTurma::pesquisarTurma(int id){
        return Business::Application::getInstance()->getTurmaDAO()->pesquisar(id);
    }

    std::list<Modelo::Turma> ManterTurma::pesquisarTurmas(std::list<int> idsTurmas){
        return Business::Application::getInstance()->getTurmaDAO()->pesquisar(idsTurmas);
    }

    bool ManterTurma::cadastrarProva(Modelo::Turma& turma, Modelo::Prova prova){
         int idRetornadoProva = 1;
         idRetornadoProva = Application::getInstance()->getTurmaDAO()->cadastrarProva(turma.getId(), prova);
         if(idRetornadoProva >= 0){
             prova.setId(idRetornadoProva);
             turma.adicionarProva(prova);
             return true;
         }else{
             return false;
         }
    }

    bool ManterTurma::atualizarProvaEmTurma(const int idTurma, Modelo::Prova& prova){
        return Application::getInstance()->getTurmaDAO()->atualizarProva(idTurma,prova);
    }

}