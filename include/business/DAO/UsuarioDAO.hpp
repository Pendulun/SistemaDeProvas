#ifndef __USUARIODAO_H__
#define __USUARIODAO_H__
#include <string>
#include "business/DAO/BaseDAO.hpp"
#include "business/Modelo/usuario.hpp"
namespace Business{
    class UsuarioDAO : public BaseDAO<Modelo::Usuario>{
        public:
            virtual Modelo::Usuario* login(std::string, std::string) = 0;
            virtual bool loginExiste(std::string) = 0;
            virtual bool cadastrarEmTurma(Modelo::Usuario, int) = 0;
            virtual Modelo::Usuario* buscarUsuarioPeloLogin(std::string ) = 0;
            virtual ~UsuarioDAO() = 0;
    };
}
#endif