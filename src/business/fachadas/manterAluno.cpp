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

    bool ManterAluno::cadastrarEmNovaTurma(Modelo::Aluno* aluno,const int idTurma){
        bool cadastrou = false;
        if(!aluno->isEmTurma(idTurma)){
            cadastrou = Application::getInstance()->getUsuarioDAO()->cadastrarEmTurma(*aluno, idTurma);
            if(cadastrou){
                aluno->adicionarTurma(idTurma);
            }
        }else{
            cadastrou = false;
        }
        return cadastrou;
    }
}