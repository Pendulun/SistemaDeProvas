#ifndef __TELAPROVAESCOLHIDAPROFESSOR_H__
#define __TELAPROVAESCOLHIDAPROFESSOR_H__
#include <iostream>
#include <string>
#include "business/fachadas/manterTurma.hpp"
#include "business/Modelo/prova.hpp"
#include "business/Modelo/status.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    class TelaProvaEscolhidaProfessor{
        public:
            void show();
            TelaProvaEscolhidaProfessor(int, Modelo::Prova prova);

        private:
            enum OpcaoMenuProvaEscolhidaProfessor{EDITAR = 1, DISPONIVEL=2,
             LIBERARNOTAS = 3, RECORRIGIR = 4, VOLTAR = 5, OPERRADA = 6};
            void mostrarSaudacoes();
            OpcaoMenuProvaEscolhidaProfessor mostrarOpcoesMenu();
            void mapeiaEntrada(OpcaoMenuProvaEscolhidaProfessor);
            Modelo::Prova prova; 
            int idTurma;
  
    };
}
#endif