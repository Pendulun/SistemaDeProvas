#include "business/Modelo/Prova.hpp"
#include <chrono>
#include <ctime>

namespace Modelo
{
    Prova::Prova(string name){
        this->nome = name;
        this->dataInicio = 0;
        this->dataFinal = 0;
        this->listaQuestoes = new list<Questao>;
    }

    Prova::Prova(int startDate, int endDate, string name){
        this->nome = name;
        this->dataInicio = startDate;
        this->dataFinal = endDate;
        this->listaQuestoes = new list<Questao>;
    }

    Prova::Prova(int startDate, int endDate, list<Questao> *questaoList, string name){
        this->nome = name;
        this->dataInicio = startDate;
        this->dataFinal = endDate;
        this->listaQuestoes = questaoList;
    }

    Prova::~Prova(){
        delete this->listaQuestoes;
    }

    void Prova::InsertQuestao(Questao q){
        this->listaQuestoes->push_back(q);
    }

    list<Questao>* Prova::getQuestaos(){
        return this->listaQuestoes;
    }

    string Prova::getNome(){
        return this->nome;
    }

    void Prova::setNome(string name){
        this->nome=name;
    }

    void Prova::mostrarProva(){
        
    }
}