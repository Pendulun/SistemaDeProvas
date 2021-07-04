#ifndef __SISTEMAPROFESSOR_H__
#define __SISTEMAPROFESSOR_H__
#include "business/Modelo/professor.hpp"
#include "gui/SistemaUsuario.hpp"
#include "gui/TerminalUteis.hpp"
#include "gui/TelaTurmasProfessor.hpp"
#include "business/Modelo/prova.hpp"

namespace GUI{
    class SistemaProfessor : public SistemaUsuario{
        public:
            void show() override;
            SistemaProfessor(Modelo::Professor*);
            ~SistemaProfessor();
        private:
            enum OpcaoMenuInicial{TURMAS=1, PERFIL=2, SAIR=3, OPERRADA=4};
            Modelo::Professor* professor;
            void mostrarSaudacoes();
            OpcaoMenuInicial mostrarOpcoesMenu();
            void mapeiaEntrada(OpcaoMenuInicial);

            bool alterarPerfil();
    };
}
#endif