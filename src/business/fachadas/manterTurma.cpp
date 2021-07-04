#include "business/fachadas/manterTurma.hpp"

namespace Business{
    Modelo::Turma* pesquisarTurma(int id){
        Application* app = Application::getInstance();
        // TODO - Pegar do banco
        int idTurma = id;
        std::string nomeTurma = "Matematica";
        Modelo::Turma* dummyTurma = new Modelo::Turma(idTurma,nomeTurma);
        return dummyTurma;
    }

}