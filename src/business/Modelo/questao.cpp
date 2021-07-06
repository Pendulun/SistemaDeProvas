#include "business/Modelo/questao.hpp"

namespace Modelo{
    Questao::Questao(){
        this->enunciado="";
        this->alternativas.clear();
        this->alternativaCorreta=-1;
        this->valor=-1;
        this->numeroQuestao=-1;
    }

    void Questao::addAlternativa(Modelo::Alternativa alternativa){
        this->alternativas.push_back(alternativa);
    }

    bool Questao::removerAlternativa(int numeroAlternativa){
        if(numeroAlternativa>0 && numeroAlternativa<=this->alternativas.size()){
            if(numeroAlternativa == this->alternativaCorreta){
                this->alternativaCorreta=-1;
            }
            this->alternativas.erase(this->alternativas.begin() + numeroAlternativa -1);
            this->atualizarNumerosTodasAlternativas();
            return true;
        }
        return false;
    }

    void Questao::atualizarNumerosTodasAlternativas(){
        for(int i = 0; i< this->alternativas.size(); i++){
            this->alternativas.at(i).setNumeroAlternativa(i+1);
        }
    }

    const std::vector<Modelo::Alternativa> Questao::getAlternativas(){
        return this->alternativas; 
    }

    const std::string Questao::getEnunciado(){
        return this->enunciado;
    }

    void Questao::setEnunciado(std::string enunciado){
        this->enunciado=enunciado;
    }

    void Questao::setValor(int valor){
        this->valor = valor;
    }

    const int Questao::getValor(){
        return this->valor;
    }

    void Questao::setNumeroQuestao(int numero){
        this->numeroQuestao = numero;
    }

    const int Questao::getNumeroQuestao(){
        return this->numeroQuestao;
    }
    
    void Questao::setTextoAlternativa(int numero, std::string texto){
        if(numero>0 && numero<=this->alternativas.size()){
            this->alternativas.at(numero-1).setTexto(texto);
        }
    }

    const int Questao::getAlternativaCorreta(){
        return this->alternativaCorreta;
    }

    void Questao::setAlternativaCorreta(int numero){
        if(numero>0 && numero<=this->alternativas.size()){
            this->alternativaCorreta=numero;
        }
    }
}

