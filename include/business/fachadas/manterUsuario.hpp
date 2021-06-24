#ifndef __MANTERUSUARIO_H__
#define __MANTERUSUARIO_H__
#include "business/application.hpp"

namespace Business{
    class ManterUsuario{
        public:
            bool cadastrarUsuario();
            bool login();
    };
}
#endif