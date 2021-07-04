#include "business/fachadas/manterTurma.hpp"

namespace Business{

    Modelo::Turma ManterTurma::cadastrarTurma(const Modelo::Turma turma){
        return Business::Application::getInstance()->getTurmaDAO()->cadastrar(turma);
    }

    Modelo::Turma ManterTurma::pesquisarTurma(int id){
        Application* app = Application::getInstance();
        // TODO - Pegar do banco
        int idTurma = id;
        std::string nomeTurma = "Matematica";
        Modelo::Turma dummyTurma(idTurma,nomeTurma);
        return dummyTurma;
    }

    std::list<Modelo::Turma> ManterTurma::pesquisarTurmas(std::list<int> idsTurmas){
        return Business::Application::getInstance()->getTurmaDAO()->pesquisar(idsTurmas);
    }

}