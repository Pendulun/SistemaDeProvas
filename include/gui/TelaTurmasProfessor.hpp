#ifndef __TELATURMASPROFESSOR__H_
#define __TELATURMASPROFESSOR__H_
#include <iostream>
#include <string>
#include "business/Modelo/professor.hpp" 
#include "gui/TerminalUteis.hpp"
#include <list>
#include "business/fachadas/manterTurma.hpp"
#include "gui/TelaTurmaEscolhidaProfessor.hpp"

namespace GUI{
    class TelaTurmasProfessor{
        public:
            void show();
            TelaTurmasProfessor(Modelo::Professor*);
        private:
            enum OpcoesMenuTurmasProfessor{CADASTRAR=1, LISTAR=2,VOLTAR=3, OPERRADA=4};
            void mostrarCabecalhoMenuInicial();
            void mostrarCabecalhoCadastroNovaTurma();
            OpcoesMenuTurmasProfessor mostrarOpcoesMenu();
            Modelo::Professor* professor;
            void mapeiaEntrada(OpcoesMenuTurmasProfessor);
            void cadastrarNovaTurma();
            bool confirmarNomeNovaTurma(std::string);
            void listarTurmasProfessor();
    };
}

#endif