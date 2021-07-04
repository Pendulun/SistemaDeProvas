#ifndef __TELATURMAESCOLHIDAPROFESSOR_H__
#define __TELATURMAESCOLHIDAPROFESSOR_H__
#include <iostream>
#include "business/Modelo/turma.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    class TelaTurmaEscolhidaProfessor{
        public:
            void show();

            TelaTurmaEscolhidaProfessor(Modelo::Turma turma);

        private:
            Modelo::Turma turma; 
            void verProvas();
            void listarProvas();      
    };
}
#endif