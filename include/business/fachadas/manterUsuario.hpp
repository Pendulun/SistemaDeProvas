#ifndef __MANTERUSUARIO_H__
#define __MANTERUSUARIO_H__
#include <string>
#include "business/application.hpp"
#include "business/Modelo/tipoUsuario.hpp"

namespace Business{
    class ManterUsuario{
        public:
            bool cadastrarUsuario(std::string, std::string, std::string, Modelo::TipoUsuario);
            bool login();
    };
}
#endif