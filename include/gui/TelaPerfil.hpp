#ifndef __TELAPERFIL_H__
#define __TELAPERFIL_H__
#include "business/Modelo/professor.hpp"
#include "gui/TerminalUteis.hpp"
#include "gui/TelaTurmasProfessor.hpp"
#include "business/fachadas/manterUsuario.hpp"

namespace GUI{
    class TelaPerfil {
        public:
            void show();
            TelaPerfil(Modelo::Usuario& user);
            
        private:
            Modelo::Usuario user;
            void alterarPerfil();
    };
}
#endif