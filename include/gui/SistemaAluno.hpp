#ifndef __SISTEMAALUNO_H__
#define __SISTEMAALUNO_H__
#include <iostream>
#include "gui/SistemaUsuario.hpp"
#include "gui/TerminalUteis.hpp"
#include "gui/TelaPerfil.hpp"
#include "business/Modelo/aluno.hpp"
#include "gui/TelaTurmasAluno.hpp"

namespace GUI{
    class SistemaAluno : public SistemaUsuario{
        public:
            void show() override;
            SistemaAluno(Modelo::Aluno*);
            ~SistemaAluno();
        private:
            Modelo::Aluno* aluno;
            enum OpcaoMenuInicialAluno{TURMAS=1, PERFIL=2, SAIR=3, OPERRADAALUNO=4};
            void mostrarSaudacoes();
            void mapeiaEntrada(OpcaoMenuInicialAluno);
            OpcaoMenuInicialAluno mostrarOpcoesMenu();
    };
}
#endif