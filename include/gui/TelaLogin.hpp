#ifndef __TELALOGIN_H__
#define __TELALOGIN_H__
#include <iostream>
#include "business/Modelo/tipoUsuario.hpp"
#include "business/fachadas/manterUsuario.hpp"

namespace GUI{
    class TelaLogin{
        public:
            void show();

        private:
            void cadastrar();
            void fazLogin();
    };
}
#endif