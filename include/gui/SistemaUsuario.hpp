#ifndef __SISTEMAUSUARIO_H__
#define __SISTEMAUSUARIO_H__
#include <iostream>
#include <string>

namespace GUI{
    class SistemaUsuario{
        public:
            virtual void show() = 0;
            virtual ~SistemaUsuario() = 0;
    };
}
#endif