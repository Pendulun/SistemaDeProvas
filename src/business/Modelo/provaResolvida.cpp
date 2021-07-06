#include "business/Modelo/provaResolvida.hpp"

namespace Modelo{
    ProvaResolvida::ProvaResolvida(){
        this->corrigida = false;
        this->idsAlternativasMarcadas.clear();
        this->pontuacao=0;
    }

     const std::list<int> ProvaResolvida::getIdsAlternativasMarcadas(){
         return this->idsAlternativasMarcadas;
     }

     const int ProvaResolvida::getPontuacao(){
         return this->pontuacao;
     }

     const bool ProvaResolvida::isCorrigida(){
         return this->corrigida;
     }

     void ProvaResolvida::adicionarIdAlternativasMarcadas(int idAlternativa){
         this->idsAlternativasMarcadas.push_back(idAlternativa);
     }

     void ProvaResolvida::setPontuacao(int pontuacao){
         this->pontuacao = pontuacao;
     }

     void ProvaResolvida::setCorrigida(bool corrigida){
         this->corrigida = corrigida;
     }
}