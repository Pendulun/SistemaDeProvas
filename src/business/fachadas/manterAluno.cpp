#include "business/fachadas/manterAluno.hpp"

namespace Business{
    Modelo::Aluno* ManterAluno::pesquisarAluno(int idAluno){
        Application* app = Application::getInstance();
        // TODO - Pegar do banco
        Modelo::Aluno* dummyAluno = new Modelo::Aluno(idAluno, Modelo::TipoUsuario::ALUNO);
        dummyAluno->setNome("Aluno Teste");
        dummyAluno->setLogin("alunoTest");
        dummyAluno->setSenha("123Teste");
        return dummyAluno;
    }

    bool ManterAluno::cadastrarEmNovaTurma(Modelo::Aluno* aluno, int idTurma){
        bool cadastrou = false;
        if(!aluno->isEmTurma(idTurma)){
            Modelo::Turma* turma = Application::getInstance()->getAlunoDAO()->cadastrarEmTurma(*aluno, idTurma);
            if(turma!=nullptr){
                cadastrou = true;
                aluno->adicionarTurma(*turma);
            }else{
                cadastrou=false;
            }
        }else{
            cadastrou = false;
        }
        return cadastrou;
    }
}