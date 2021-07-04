#ifndef __PROFESSORDAO_H__
#define __PROFESSORDAO_H__
#include <string>
#include "business/Modelo/professor.hpp"
#include "business/Modelo/turma.hpp"
#include "business/DAO/BaseDAO.hpp"
namespace Business{
    class ProfessorDAO : public BaseDAO<Modelo::Professor>{
        public:
            virtual Modelo::Turma cadastrarTurma(Modelo::Professor, std::string) = 0;
            virtual ~ProfessorDAO() = 0;
    };
}
#endif