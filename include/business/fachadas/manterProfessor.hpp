#ifndef __MANTERPROFESSOR_H__
#define __MANTERPROFESSOR_H__
#include "business/application.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include "business/Modelo/professor.hpp"
#include "business/fachadas/excecoes/ProfessorNotFoundException.hpp"

namespace Business{
    class ManterProfessor{
        public:
            Modelo::Professor* pesquisarProfessor(int id);
    };
}
#endif