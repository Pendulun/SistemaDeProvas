#ifndef __USUARIODAO_H__
#define __USUARIODAO_H__
#include <string>
#include "business/Modelo/usuario.hpp"
namespace Business{
    class UsuarioDAO{
        public:
            virtual void cadastrar(Modelo::Usuario) = 0;
            virtual bool login(std::string, std::string) = 0;
            virtual ~UsuarioDAO() = 0;
    };
}
#endif