#ifndef PROVA_H
#define PROVA_H

//isso precisa ser movido pra outro arquivo depois


#include "business/Modelo/questao.hpp"
#include "business/Modelo/status.hpp"
#include <string>
#include <list>
#include <iterator>
#include <iostream>


//por enquanto, estou pensando apenas no professor
namespace Modelo {
    class Prova {
    private:
        std::list<Questao> listaQuestoes;
        int dataInicio;
        int dataFinal;
        std::string nome;
        int id;
        Status status;

    public:
        Prova(std::string);                             //prova sem data definida
        Prova(int, int, std::string);                   //prova com data definida
        Prova(int, int, std::list<Questao>, std::string); //reutilizar questões
        ~Prova();

        std::list<Questao> getQuestaos();
        void setQuestao(Questao, Questao);
        void RemoveQuestao(Questao);
        void InsertQuestao(Questao);
        int getDataInicio();
        void setDataInicio(int);
        int getDataFinal();
        void setDataFinal(int);
        Status getStatus();
        void setStatus(Status);
        std::string getNome();
        void setNome(std::string);
        void setId(int);
        int getId();

        void mostrarProva();
    };
}

#endif