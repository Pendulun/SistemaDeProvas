#ifndef __MANTERALUNO_H__
#define __MANTERALUNO_H__
#include <string>
#include "business/application.hpp"
#include "business/Modelo/aluno.hpp"
#include "business/Modelo/turma.hpp"
#include "business/DAO/AlunoDAO.hpp"
#include "business/fachadas/manterTurma.hpp"
#include "business/fachadas/excecoes/AlunoNotFoundException.hpp"

namespace Business{
    class ManterAluno{
        public:
            Modelo::Aluno* pesquisarAluno(int id);
            bool cadastrarEmNovaTurma(Modelo::Aluno*, int);
    };
}
#endif