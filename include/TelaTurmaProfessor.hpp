#ifndef __TELATURMAPROFESSOR_H__
#define __TELATURMAPROFESSOR_H__
#include <iostream>

namespace GUI{
    class TelaTurmaProfessor{
        public:
            void show();

        private:
            void cadastrarTurma();
            void listarTurmas();
    };
}
#endif