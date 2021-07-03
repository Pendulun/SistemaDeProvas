#ifndef __SISTEMAALUNO_H__
#define __SISTEMAALUNO_H__
#include <iostream>
#include "gui/SistemaUsuario.hpp"
#include "business/Modelo/aluno.hpp"

namespace GUI{
    class SistemaAluno : public SistemaUsuario{
        public:
            void show() override;
            SistemaAluno(Modelo::Aluno*);
            ~SistemaAluno();
        private:
            Modelo::Aluno* aluno;
    };
}
#endif