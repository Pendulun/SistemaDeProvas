#ifndef __TELATURMAESCOLHIDAALUNO_H__
#define __TELATURMAESCOLHIDAALUNO_H__
#include <iostream>
#include "business/Modelo/turma.hpp"
#include "gui/TerminalUteis.hpp"
#include "business/Modelo/status.hpp"

namespace GUI{
    class TelaTurmaEscolhidaAluno{
        public:
            void show();

            TelaTurmaEscolhidaAluno(Modelo::Turma turma, int idAluno);

        private:
            int idAluno;
            Modelo::Turma turma; 
            void verProvas();
            void verProvasRealizadas();
            void verProvasDisponiveis();
            void listarProvasRealizadas();
            void listarProvasDisponiveis();
    };
}
#endif