#ifndef __TELAPROVAESCOLHIDAPROFESSOR_H__
#define __TELAPROVAESCOLHIDAPROFESSOR_H__
#include <iostream>
#include <string>
#include "business/fachadas/manterTurma.hpp"
#include "business/Modelo/prova.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    class TelaProvaEscolhidaProfessor{
        public:
            void show();
            TelaProvaEscolhidaProfessor(int, Modelo::Prova prova);

        private:
            enum OpcaoMenuProvaEscolhidaProfessor{EDITAR = 1,
             LIBERARNOTAS = 2, RECORRIGIR = 3, VOLTAR = 4, OPERRADA = 5};
            void mostrarSaudacoes();
            OpcaoMenuProvaEscolhidaProfessor mostrarOpcoesMenu();
            void mapeiaEntrada(OpcaoMenuProvaEscolhidaProfessor);
            Modelo::Prova prova; 
            int idTurma;
  
    };
}
#endif