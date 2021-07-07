#ifndef PROVA_H
#define PROVA_H

//isso precisa ser movido pra outro arquivo depois


#include "business/Modelo/questao.hpp"
#include "business/Modelo/alternativa.hpp"
#include "business/Modelo/provaResolvida.hpp"
#include "business/Modelo/status.hpp"
#include <string>
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include <iostream>


//por enquanto, estou pensando apenas no professor
namespace Modelo {
    class Prova {
    private:
        std::list<Questao> listaQuestoes;
        bool notasLiberadas;
        int dataInicio;
        int dataFinal;
        std::string nome;
        std::list<std::string> assuntos;
        std::map<int,Modelo::ProvaResolvida> submissoesAlunos;
        int id;
        Status status;
    public:
        Prova();
        Prova(std::string);                             //prova sem data definida
        Prova(int, int, std::string);                   //prova com data definida
        Prova(int, int, std::list<Questao>, std::string); //reutilizar questões
        ~Prova();

        std::list<Questao> getQuestaos();
        void setQuestao(Questao, Questao);
        void RemoveQuestao(Questao);
        void addQuestao(Questao);
        void InsertQuestao(Questao);
        int getDataInicio();
        void setDataInicio(int);
        int getDataFinal();
        void setDataFinal(int);
        Status getStatus();
        void setStatus(Status);
        std::string getNome();
        void setNome(std::string);
        void addAssunto(std::string assunto);
        std::list<std::string> getAssuntos();
        void setId(int);
        int getId();
        void setNotasLiberadas(bool);
        bool isNotasLiberadas();
        void mostrarProva();

        void submeterProva(int,ProvaResolvida);
    };
}

#endif