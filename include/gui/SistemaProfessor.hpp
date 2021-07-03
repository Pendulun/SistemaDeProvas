#ifndef __SISTEMAPROFESSOR_H__
#define __SISTEMAPROFESSOR_H__
#include <iostream>
#include "gui/SistemaUsuario.hpp"
#include "business/Modelo/professor.hpp"

namespace GUI{
    class SistemaProfessor : public SistemaUsuario{
        public:
            void show() override;
            SistemaProfessor(Modelo::Professor*);
            ~SistemaProfessor();
        private:
            Modelo::Professor* professor;
    };
}
#endif