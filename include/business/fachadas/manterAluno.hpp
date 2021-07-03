#ifndef __MANTERALUNO_H__
#define __MANTERALUNO_H__
#include "business/application.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include "business/Modelo/aluno.hpp"
#include "business/fachadas/excecoes/AlunoNotFoundException.hpp"

namespace Business{
    class ManterAluno{
        public:
            Modelo::Aluno* pesquisarAluno(int id);
    };
}
#endif