#ifndef __MANTERTURMA_H__
#define __MANTERTURMA_H__
#include "business/application.hpp"
#include "business/Modelo/turma.hpp"
//#include "business/DAO/TurmaDAO.hpp"
#include "business/fachadas/excecoes/TurmaNotFoundException.hpp"

namespace Business{
    class ManterTurma{
        public:
            Modelo::Turma* pesquisarTurma(int id);
    };
}
#endif