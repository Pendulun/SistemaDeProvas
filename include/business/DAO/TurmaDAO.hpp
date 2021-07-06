#ifndef __TURMADAO_H__
#define __TURMADAO_H__
#include <string>
#include <list>
#include "business/Modelo/turma.hpp"
#include "business/DAO/BaseDAO.hpp"
namespace Business{
    class TurmaDAO : public BaseDAO<Modelo::Turma>{
        public:
            virtual int cadastrarProva(int,Modelo::Prova) = 0;
            virtual bool atualizarProva(int,Modelo::Prova) = 0;
            virtual Modelo::Prova* pesquisarProva(int,int) = 0;
            virtual ~TurmaDAO() = 0;
    };
}
#endif