#ifndef __TELATURMASPROFESSOR__H_
#define __TELATURMASPROFESSOR__H_
#include <iostream>
#include <string>
#include "business/Modelo/professor.hpp" 
namespace GUI{
    class TelaTurmasProfessor{
        public:
            void show();
            TelaTurmasProfessor(Modelo::Professor*);
        private:
            Modelo::Professor* professor;
    };
}

#endif