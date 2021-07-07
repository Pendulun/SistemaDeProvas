#ifndef __TELATURMASALUNO__H_
#define __TELATURMASALUNO__H_
#include <iostream>
#include <string>
#include <exception>
#include "business/Modelo/aluno.hpp" 
#include "gui/TerminalUteis.hpp"
#include "business/fachadas/manterAluno.hpp"
#include <list>
#include "gui/TelaTurmaEscolhidaAluno.hpp" 

namespace GUI{
    class TelaTurmasAluno{
        public:
            void show();
            TelaTurmasAluno(Modelo::Aluno*);
        private:
            enum OpcoesMenuTurmasAluno{CADASTRAR=1, LISTAR=2,VOLTAR=3, OPERRADA=4};
            void mostrarCabecalhoMenuInicial();
            void mostrarCabecalhoCadastroNovaTurma();
            OpcoesMenuTurmasAluno mostrarOpcoesMenu();
            Modelo::Aluno* aluno;
            void mapeiaEntrada(OpcoesMenuTurmasAluno);
            void cadastrarEmNovaTurma();
            void listarTurmasAluno();
    };
}

#endif