#ifndef __SISTEMAPROFESSOR_H__
#define __SISTEMAPROFESSOR_H__
#include "business/Modelo/professor.hpp"
#include "gui/SistemaUsuario.hpp"
#include "gui/TerminalUteis.hpp"
#include "gui/TelaTurmasProfessor.hpp"

namespace GUI{
    class SistemaProfessor : public SistemaUsuario{
        public:
            void show() override;
            SistemaProfessor(Modelo::Professor*);
            ~SistemaProfessor();
        private:
            enum OpcaoMenuInicial{TURMAS=1, PROVAS=2, PERFIL=3, SAIR=4, OPERRADA=5};
            Modelo::Professor* professor;
            void mostrarSaudacoes();
            OpcaoMenuInicial mostrarOpcoesMenu();
            void mapeiaEntrada(OpcaoMenuInicial);

            bool alterarPerfil();
    };
}
#endif