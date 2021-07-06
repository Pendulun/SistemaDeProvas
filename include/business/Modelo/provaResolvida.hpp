#ifndef __PROVARESOLVIDA_H_
#define __PROVARESOLVIDA_H_
#include <string>
#include <list>


//por enquanto, estou pensando apenas no professor
namespace Modelo {
    class ProvaResolvida {
    private:
        std::list<int> idsAlternativasMarcadas;
        int pontuacao;
        bool corrigida;
    public:
        ProvaResolvida();
        const std::list<int> getIdsAlternativasMarcadas();
        const int getPontuacao();
        const bool isCorrigida();
        void adicionarIdAlternativasMarcadas(int);
        void setPontuacao(int);
        void setCorrigida(bool);
    };
}

#endif