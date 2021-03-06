#ifndef __MANTERUSUARIO_H__
#define __MANTERUSUARIO_H__
#include <string>
#include <exception>
#include <stdexcept>
#include "business/application.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include "business/Modelo/usuario.hpp"
#include "business/fachadas/excecoes/UserNotFoundException.hpp"

namespace Business{
    class ManterUsuario{
        public:
            bool cadastrarUsuario(std::string, std::string, std::string, Modelo::TipoUsuario);
            bool atualizarUsuario(Modelo::Usuario&, Modelo::Usuario&);
            bool atualizar(Modelo::Usuario&);
            Modelo::Usuario* login(std::string login,std::string senha);
    };
}
#endif