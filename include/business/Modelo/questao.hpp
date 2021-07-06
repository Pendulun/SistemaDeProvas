#ifndef QUESTAO_H
#define QUESTAO_H
#include <string>
#include <vector>
#include <iterator>
#include "business/Modelo/alternativa.hpp"

namespace Modelo{
    class Questao{
        private:
            std::string enunciado;
            std::vector<Modelo::Alternativa> alternativas;
            int alternativaCorreta;
            int valor;
            int numeroQuestao;
            void atualizarNumerosTodasAlternativas();
        public:
            Questao();
            Questao();
            const std::string getEnunciado();
            void setEnunciado(std::string);
            const std::string getTextoAlternativa(int);
            void setTextoAlternativa(int,std::string);
            void addAlternativa(Modelo::Alternativa);
            bool removerAlternativa(int);
            const int getAlternativaCorreta();
            void setAlternativaCorreta(int);
            void setValor(int);
            const int getValor();
            void setNumeroQuestao(int);
            const int getNumeroQuestao();
    };
}
#endif