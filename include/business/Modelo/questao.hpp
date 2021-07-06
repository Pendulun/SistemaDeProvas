#ifndef QUESTAO_H
#define QUESTAO_H
#include <string>

namespace Modelo{
    class Questao{
        private:
            std::string enunciado;
            std::string textoAlternativas[4];
            int alternativaCorreta;
        public:
            Questao(std::string, std::string, std::string, std::string, std::string, int);
            std::string getEnunciado();
            void setEnunciado(std::string);
            std::string getTextoAlternativa(int);
            void setTextoAlternativa(int,std::string);
            int getAlternativaCorreta();
            void setAlternativaCorreta(int);
    };
}
#endif