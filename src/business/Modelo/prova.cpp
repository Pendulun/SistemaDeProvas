#include "business/Modelo/Prova.hpp"
#include <chrono>
#include <ctime>

namespace Modelo
{
    Prova::Prova(std::string name){
        this->nome = name;
        this->dataInicio = 0;
        this->dataFinal = 0;
        this->listaQuestoes.clear();
    }

    Prova::Prova(int startDate, int endDate, std::string name){
        this->nome = name;
        this->dataInicio = startDate;
        this->dataFinal = endDate;
        this->listaQuestoes.clear(); 
    }

    Prova::Prova(int startDate, int endDate, std::list<Questao> questaoList, std::string name){
        this->nome = name;
        this->dataInicio = startDate;
        this->dataFinal = endDate;
        this->listaQuestoes = questaoList;
    }

    Prova::~Prova(){}

    void Prova::InsertQuestao(Questao q){
        this->listaQuestoes.push_back(q);
    }

    std::list<Questao> Prova::getQuestaos(){
        return this->listaQuestoes;
    }

    std::string Prova::getNome(){
        return this->nome;
    }

    void Prova::setNome(std::string name){
        this->nome=name;
    }

    void Prova::mostrarProva(){
        std::cout<<"A prova ocorre entre os dias: "<<this->dataInicio<<" e "<<this->dataFinal<<std::endl;
        std::cout<<"O titulo da prova eh: "<<this->nome<<std::endl;

        std::cout<<"\nAs questoes da prova sao: \n\n";
        
        int i = 1;
        for (std::list<Questao>::iterator it=this->listaQuestoes.begin(); it != this->listaQuestoes.end(); ++it){
            std::cout<<"Questao "<<i<<": "<<(*it).getEnunciado()<<std::endl;
            std::cout<<"Alternativa 1: "<<(*it).getTextoAlternativa(1)<<std::endl;
            std::cout<<"Alternativa 2: "<<(*it).getTextoAlternativa(2)<<std::endl;
            std::cout<<"Alternativa 3: "<<(*it).getTextoAlternativa(3)<<std::endl;
            std::cout<<"Alternativa 4: "<<(*it).getTextoAlternativa(4)<<std::endl;
            std::cout<<"Alternativa Correta: "<<(*it).getAlternativaCorreta()<<std::endl;
            std::cout<<"\n";
            i++;
        }
    }

    void Prova::setId(int id) {
        this->id = id;
    }

    int Prova::getId() {
        return this->id;
    }

    int Prova::getDataInicio() {
        return this->dataInicio;
    }

    void Prova::setDataInicio(int dataInicio) {
        this->dataInicio = dataInicio;
    }

    int Prova::getDataFinal() {
        return this->dataFinal;
    }

    void Prova::setDataFinal(int dataFinal) {
        this->dataFinal = dataFinal;
    }

    Status Prova::getStatus() {
        return this->status;
    }

    void Prova::setStatus(Status status) {
        this->status = status;
    }
}