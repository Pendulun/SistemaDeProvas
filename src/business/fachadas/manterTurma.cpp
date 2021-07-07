#include "business/fachadas/manterTurma.hpp"

namespace Business{

    bool ManterTurma::cadastrarTurma(const Modelo::Turma turma, Modelo::Professor* professor){
        int idTurmaCadastrada = -1;
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

}