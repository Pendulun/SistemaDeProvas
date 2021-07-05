#include "business/fachadas/manterProfessor.hpp"

namespace Business{
    Modelo::Professor* ManterProfessor::pesquisarProfessor(int idProfessor){
        //Application::getInstance()->getProfessorDAO()->pesquisar(idProfessor);
        // TODO - Pegar do banco
        Modelo::Professor* dummyProfessor = new Modelo::Professor(idProfessor, Modelo::TipoUsuario::PROFESSOR);
        dummyProfessor->setNome("Professor Fulano");
        dummyProfessor->setLogin("loginteste");
        dummyProfessor->setSenha("123");
        return dummyProfessor;
    }

    Modelo::Turma ManterProfessor::cadastrarNovaTurma(std::string nomeTurma, Modelo::Professor* professor){
        Modelo::Turma novaTurma(-1);
        std::list<Modelo::Turma> turmasProfessor;
        turmasProfessor = Application::getInstance()->getTurmaDAO()->pesquisar(professor->getTurmas());

        if(!this->existeTurma(nomeTurma,turmasProfessor)){
            novaTurma.setNome(nomeTurma);
            //novaTurma =
            auto turmaCadastrada = Application::getInstance()->getTurmaDAO()->cadastrar(novaTurma);
            novaTurma.setId(turmaCadastrada->getId());
            professor->adicionarTurma(novaTurma.getId());
        }
        return novaTurma;
    }

    bool ManterProfessor::existeTurma(const std::string nomeTurma, const std::list<Modelo::Turma> turmas){
        for(Modelo::Turma turma : turmas){
            if(turma.getNome().compare(nomeTurma)==0){
                return true;
            }
        }
        return false;
    }

    std::list<Modelo::Turma> ManterProfessor::pesquisarTurmasProfessor(int idProfessor){
        Modelo::Professor* professor;
        std::list<Modelo::Turma> turmas;
        professor = (Modelo::Professor*) Business::Application::getInstance()->getUsuarioDAO()->pesquisar(idProfessor);
        turmas = Business::Application::getInstance()->getTurmaDAO()->pesquisar(professor->getTurmas());
        delete professor;
        return turmas;
    }

}