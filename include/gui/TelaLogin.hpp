#ifndef __TELALOGIN_H__
#define __TELALOGIN_H__
#include <iostream>
#include "business/Modelo/tipoUsuario.hpp"
#include "business/fachadas/manterUsuario.hpp"
#include "business/Modelo/usuario.hpp"
#include "business/fachadas/excecoes/UserNotFoundException.hpp"
#include "business/fachadas/manterAluno.hpp"
#include "business/fachadas/manterProfessor.hpp"

namespace GUI{
    class TelaLogin{
        public:
            void show();

        private:
            Modelo::Usuario* user = nullptr;

            void cadastrar();
            void fazLogin();
    };
}
#endif