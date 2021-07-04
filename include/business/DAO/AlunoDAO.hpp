#ifndef __ALUNODAO_H__
#define __ALUNODAO_H__
#include <string>
#include "business/Modelo/aluno.hpp"
#include "business/Modelo/turma.hpp"
#include "business/DAO/BaseDAO.hpp"
namespace Business{
    class AlunoDAO : public BaseDAO<Modelo::Aluno>{
        public:
            virtual Modelo::Turma* cadastrarEmTurma(Modelo::Aluno, int) = 0;
            virtual ~AlunoDAO() = 0;
    };
}
#endif