#ifndef __MANTERPROFESSOR_H__
#define __MANTERPROFESSOR_H__
#include <list>
#include "business/application.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include "business/Modelo/professor.hpp"
#include "business/Modelo/turma.hpp"
#include "business/DAO/ProfessorDAO.hpp"
#include "business/fachadas/excecoes/ProfessorNotFoundException.hpp"

namespace Business{
    class ManterProfessor{
        public:
            Modelo::Professor pesquisarProfessor(int id);
            Modelo::Turma cadastrarNovaTurma(std::string, Modelo::Professor*);
            std::list<Modelo::Turma> pesquisarTurmasProfessor(int idProfessor);
        private:
            bool existeTurma( const std::string, const std::list<Modelo::Turma>);

    };
}
#endif