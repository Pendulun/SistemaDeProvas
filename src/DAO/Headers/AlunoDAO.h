#ifndef __AlunoDAO_H__
#define __AlunoDAO_H__

#include "BaseDAO.h"
#include "../../Modelo/Aluno.cpp"

class AlunoDAO : public BaseDAO<Aluno>
{
    public:
        void getAlunosMateria(Aluno);
};

#endif