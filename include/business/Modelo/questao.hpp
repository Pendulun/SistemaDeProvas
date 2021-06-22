#ifndef QUESTAO_H
#define QUESTAO_H
#include <string>

class Questao{
    private:
        string enunciado;
        string textoAlternativas[4];
        int alternativaCorreta;
    public:
        Questao(string,string,string,string,string,int);
        string getEnunciado();
        void setEnunciado(string);
        string getTextoAlternativa(int);
        void setTextoAlternativa(int,string);
        int getAlternativaCorreta();
        void setAlternativaCorreta(int);
};

#endif