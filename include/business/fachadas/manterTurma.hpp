#ifndef __MANTERTURMA_H__
#define __MANTERTURMA_H__
#include <list>
#include <string>
#include "business/application.hpp"
#include "business/Modelo/turma.hpp"
#include "business/DAO/TurmaDAO.hpp"
#include "business/fachadas/excecoes/TurmaNotFoundException.hpp"

namespace Business{
    class ManterTurma{
        public:
            Modelo::Turma* cadastrarTurma(const Modelo::Turma);
            Modelo::Turma* pesquisarTurma(int id);
            std::list<Modelo::Turma> pesquisarTurmas(std::list<int> idsTurmas);
            bool cadastrarProva(Modelo::Turma&, Modelo::Prova);

    };
}
#endif