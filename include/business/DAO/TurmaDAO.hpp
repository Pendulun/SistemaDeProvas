#ifndef __TURMADAO_H__
#define __TURMADAO_H__
#include <string>
#include <list>
#include "business/Modelo/turma.hpp"
#include "business/DAO/BaseDAO.hpp"
namespace Business{
    class TurmaDAO : public BaseDAO<Modelo::Turma>{
        public:
            virtual ~TurmaDAO() = 0;
    };
}
#endif