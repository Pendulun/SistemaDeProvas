#ifndef __USUARIODAO_H__
#define __USUARIODAO_H__
#include <string>
#include "business/Modelo/tipoUsuario.hpp"
namespace Business{
    class UsuarioDAO{
        public:
            virtual bool cadastrar(std::string, std::string, std::string, Modelo::TipoUsuario) = 0;
            virtual bool login(std::string, std::string) = 0;
            virtual ~UsuarioDAO() = 0;
    };
}
#endif