#include "business/Modelo/alternativa.hpp"

namespace Modelo{
    Alternativa::Alternativa(){
        this->numeroAlternativa=-1;
        this->texto="";
    }

    Alternativa::Alternativa(std::string texto){
        this->texto = texto;
        this->numeroAlternativa = -1;
    }

    Alternativa::Alternativa(std::string texto, int numeroAlternativa){
        this->texto = texto;
        this->numeroAlternativa = numeroAlternativa;
    }

    const int Alternativa::getNumeroAlternativa(){
        return this->numeroAlternativa;
    }

    void Alternativa::setNumeroAlternativa(int numero){
        this->numeroAlternativa = numero;
    }

    const std::string Alternativa::getTexto(){
        return this->texto;
    }

    void Alternativa::setTexto(std::string texto){
        this->texto = texto;
    }
}