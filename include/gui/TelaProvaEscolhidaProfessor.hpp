#ifndef __TELAPROVAESCOLHIDAPROFESSOR_H__
#define __TELAPROVAESCOLHIDAPROFESSOR_H__
#include <iostream>
#include <string>
#include "business/Modelo/prova.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    class TelaProvaEscolhidaProfessor{
        public:
            void show();
            TelaProvaEscolhidaProfessor(Modelo::Prova prova);

        private:
            enum OpcaoMenuProvaEscolhidaProfessor{EDITAR = 1,
             LIBERARNOTAS = 2, RECORRIGIR = 3, VOLTAR = 4, OPERRADA = 5};
            void mostrarSaudacoes();
            OpcaoMenuProvaEscolhidaProfessor mostrarOpcoesMenu();
            void mapeiaEntrada(OpcaoMenuProvaEscolhidaProfessor);
            Modelo::Prova prova; 
  
    };
}
#endif