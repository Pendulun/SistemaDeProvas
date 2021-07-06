#include "business/fachadas/manterTurma.hpp"

namespace Business{

    Modelo::Turma* ManterTurma::cadastrarTurma(const Modelo::Turma turma){
        return Business::Application::getInstance()->getTurmaDAO()->cadastrar(turma);
    }

    Modelo::Turma* ManterTurma::pesquisarTurma(int id){
        /*
        Application* app = Application::getInstance();
        return app->getTurmaDAO()->pesquisar(id);
        */
        int idTurma = id;
        std::string nomeTurma = "Matematica";
        Modelo::Turma* dummyTurma = new Modelo::Turma(idTurma,nomeTurma);
        return dummyTurma;
    }

    std::list<Modelo::Turma> ManterTurma::pesquisarTurmas(std::list<int> idsTurmas){
        std::list<Modelo::Turma> turmas;

        Modelo::Turma novaTurma;
        novaTurma.setNome("Turma Teste 1");

        turmas.push_back(novaTurma);

        return turmas;
        //return Business::Application::getInstance()->getTurmaDAO()->pesquisar(idsTurmas);
    }

    bool ManterTurma::cadastrarProva(Modelo::Turma& turma, Modelo::Prova prova){
         int idRetornadoProva = 1;
         //idRetornadoProva = Application::getInstance()->getTurmaDAO()->cadastrarProva(turma.getId(), prova);
         if(idRetornadoProva >= 0){
             prova.setId(idRetornadoProva);
             turma.adicionarProva(prova);
             return true;
         }else{
             return false;
         }
    }

}