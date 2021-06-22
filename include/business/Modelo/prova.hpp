#ifndef PROVA_H
#define PROVA_H

//isso precisa ser movido pra outro arquivo depois
enum Status
{
    PENDING,
    OPEN,
    FINISHED
};

#include "business/Modelo/questao.hpp"
#include <string>
#include <list>
#include <iterator>

using namespace std;

//por enquanto, estou pensando apenas no professor
namespace GUI{
    class Prova{
    private:
        list<Questao> *listaQuestoes;
        int dataInicio;
        int dataFinal;
        string nome;

    public:
        Prova(string);                             //prova sem data definida
        Prova(int, int, string);                   //prova com data definida
        Prova(int, int, list<Questao> *, string); //reutilizar questões
        ~Prova();

        list<Questao> *getQuestaos();
        void setQuestao(Questao, Questao);
        void RemoveQuestao(Questao);
        void InsertQuestao(Questao);
        int getDataInicio();
        void setDataInicio(int);
        int getDataFinal();
        void setDataFinal(int);
        Status getStatus();
        string getNome();
        void setNome(string);
    };
}

#endif