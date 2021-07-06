#ifndef __USERTERMINALGUI_H__
#define __USERTERMINALGUI_H__
#include <iostream>
#include "business/gui/UserGUI.hpp"
#include "business/Modelo/usuario.hpp"
#include "business/Modelo/professor.hpp"
#include "business/Modelo/aluno.hpp"
#include "business/fachadas/excecoes/AlunoNotFoundException.hpp"
#include "business/fachadas/excecoes/ProfessorNotFoundException.hpp"
#include "business/fachadas/manterAluno.hpp"
#include "business/fachadas/manterProfessor.hpp"
#include "gui/TelaLogin.hpp"
#include "gui/SistemaAluno.hpp"
#include "gui/SistemaProfessor.hpp"
#include "gui/SistemaUsuario.hpp"

namespace GUI{
    class UserTerminalGUI :public Business::UserGUI{
        public:
            void show() override;
            ~UserTerminalGUI() override;
        private:
            SistemaUsuario* configSistema(Modelo::Usuario*);

    };
}
#endif