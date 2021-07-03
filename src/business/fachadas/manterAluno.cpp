#include "business/fachadas/manterAluno.hpp"

namespace Business{
    Modelo::Aluno* ManterAluno::pesquisarAluno(int idAluno){
        Application* app = Application::getInstance();
        // TODO - Pegar do banco
        Modelo::Aluno* dummyAluno = new Modelo::Aluno(idAluno, Modelo::TipoUsuario::ALUNO);
        return dummyAluno;
    }

}