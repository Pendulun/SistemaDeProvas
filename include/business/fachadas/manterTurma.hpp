#ifndef __MANTERTURMA_H__
#define __MANTERTURMA_H__
#include <list>
#include <string>
#include "business/application.hpp"
#include "business/Modelo/turma.hpp"
#include "business/Modelo/prova.hpp"
#include "business/Modelo/professor.hpp"
#include "business/DAO/TurmaDAO.hpp"
#include "business/fachadas/excecoes/TurmaNotFoundException.hpp"
#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    class ManterTurma{
        public:
            bool cadastrarTurma(Modelo::Turma, Modelo::Professor*);
            Modelo::Turma* pesquisarTurma(int id);
            std::list<Modelo::Turma> pesquisarTurmas(std::list<int> idsTurmas);
            bool cadastrarProva(Modelo::Turma&, Modelo::Prova);
            bool atualizarProvaEmTurma(const int idTurma, Modelo::Prova&);

    };
}
#endif