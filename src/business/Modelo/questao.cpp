#include "business/Modelo/questao.hpp"

namespace Modelo{
    Questao::Questao(std::string enunciado, std::string alternativa1, std::string alternativa2, std::string alternativa3, std::string alternativa4, int alternativaCorreta){
        this->enunciado=enunciado;
        this->textoAlternativas[0]=alternativa1;
        this->textoAlternativas[1]=alternativa2;
        this->textoAlternativas[2]=alternativa3;
        this->textoAlternativas[3]=alternativa4;
        this->alternativaCorreta=alternativaCorreta;
    }

    std::string Questao::getEnunciado(){
        return this->enunciado;
    }

    void Questao::setEnunciado(std::string enunciado){
        this->enunciado=enunciado;
    }

    std::string Questao::getTextoAlternativa(int numero){
        if(numero>0&&numero<=4){
            return this->textoAlternativas[numero-1];
        }else{
            return NULL;
        }
    }

    void Questao::setTextoAlternativa(int numero, std::string texto){
        if(numero>0&&numero<=4){
            this->textoAlternativas[numero-1]=texto;
        }
    }

    int Questao::getAlternativaCorreta(){
        return this->alternativaCorreta;
    }

    void Questao::setAlternativaCorreta(int numero){
        if(numero>0&&numero<=4){
            this->alternativaCorreta=numero;
        }
    }
}

