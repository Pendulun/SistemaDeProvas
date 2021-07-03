#ifndef __SISTEMAPROFESSOR_H__
#define __SISTEMAPROFESSOR_H__
#include "gui/SistemaUsuario.hpp"
#include "business/Modelo/professor.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    class SistemaProfessor : public SistemaUsuario{
        public:
            void show() override;
            SistemaProfessor(Modelo::Professor*);
            ~SistemaProfessor();
        private:
            enum OpcaoMenuInicial{TURMAS=1, PROVAS=2, PERFIL=3, SAIR=4};
            Modelo::Professor* professor;
            void mostrarSaudacoes();
            OpcaoMenuInicial mostrarOpcoesMenu();
    };
}
#endif