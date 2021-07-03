#include "business/fachadas/manterProfessor.hpp"

namespace Business{
    Modelo::Professor* ManterProfessor::pesquisarProfessor(int idProfessor){
        Application* app = Application::getInstance();
        // TODO - Pegar do banco
        Modelo::Professor* dummyProfessor = new Modelo::Professor(idProfessor, Modelo::TipoUsuario::PROFESSOR);
        return dummyProfessor;
    }

    bool ManterProfessor::cadastrarNovaTurma(std::string nomeTurma, Modelo::Professor* professor){
        bool cadastrou = false;
        if(!professor->possuiTurma(nomeTurma)){
            Modelo::Turma* novaTurma = Application::getInstance()->getProfessorDAO()->cadastrarTurma(*professor, nomeTurma);
            if(novaTurma!=nullptr){
                professor->adicionarTurma(*novaTurma);
                return true;
            }else{
                return false;
            }
        
        }else{
            cadastrou = false;
        }
        return cadastrou;
    }

}