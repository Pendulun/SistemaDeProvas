#include "business/Modelo/Prova.hpp"
#include <chrono>
#include <ctime>

namespace Modelo
{

    Prova::Prova() {
        this->nome = "";
        this->notasLiberadas=false;
        this->dataInicio = -1;
        this->dataFinal = -1;
        this->status = Status::PENDING;
        this->listaQuestoes.clear();
        this->submissoesAlunos.clear();
    }
    Prova::Prova(std::string name){
        this->nome = name;
        this->notasLiberadas=false;
        this->dataInicio = 0;
        this->dataFinal = 0;
        this->listaQuestoes.clear();
        this->status = Status::PENDING;
        this->submissoesAlunos.clear();
    }

    Prova::Prova(int startDate, int endDate, std::string name){
        this->nome = name;
        this->notasLiberadas=false;
        this->dataInicio = startDate;
        this->dataFinal = endDate;
        this->listaQuestoes.clear();
        this->status = Status::PENDING;
        this->submissoesAlunos.clear();
    }

    Prova::Prova(int startDate, int endDate, std::list<Questao> questaoList, std::string name){
        this->nome = name;
        this->notasLiberadas=false;
        this->dataInicio = startDate;
        this->dataFinal = endDate;
        this->listaQuestoes = questaoList;
        this->status = Status::PENDING;
        this->submissoesAlunos.clear();
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

    void Prova::addAssunto(std::string assunto){
        this->assuntos.push_back(assunto);
    }
    
    std::list<std::string> Prova::getAssuntos(){
        return this->assuntos;
    }

    void Prova::mostrarProva(){
        std::cout<<"A prova ocorre entre os dias: "<<this->dataInicio<<" e "<<this->dataFinal<<std::endl;
        std::cout<<"O titulo da prova eh: "<<this->nome<<std::endl;

        std::cout<<"\nOs assuntos da prova sao: "<<std::endl;
        
        if(this->assuntos.size()==0){
            std::cout<<"Prova sem assuntos listados.\n\n";
        }
        else{
            for(std::string assunto : this->assuntos){
                std::cout<<" -->"<<assunto<<std::endl;
            }
        }


        std::cout<<"\nAs questoes da prova sao: \n\n";
        
        int i = 1;
        for (std::list<Questao>::iterator it=this->listaQuestoes.begin(); it != this->listaQuestoes.end(); ++it){
            std::cout<<"(Valor: "<<(*it).getValor()<<")";
            std::cout<<" Questao "<<i<<": "<<(*it).getEnunciado()<<std::endl;
            
            for(Modelo::Alternativa alternativa : (*it).getAlternativas()){
                std::cout<<"Alternativa "<<alternativa.getNumeroAlternativa()<<": ";
                std::cout<<alternativa.getTexto()<<std::endl;
            }
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

    void Prova::addQuestao(Questao questao) {
        this->listaQuestoes.push_back(questao);
    }

    void Prova::submeterProva(int id,ProvaResolvida tentativa){
        this->submissoesAlunos.insert(std::pair<int,Modelo::ProvaResolvida>(id,tentativa));
    }
}