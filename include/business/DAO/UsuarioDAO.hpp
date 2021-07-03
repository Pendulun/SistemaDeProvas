#ifndef __USUARIODAO_H__
#define __USUARIODAO_H__
#include <string>
#include "business/DAO/BaseDAO.hpp"
#include "business/Modelo/usuario.hpp"
namespace Business{
    class UsuarioDAO : public BaseDAO<Modelo::Usuario>{
        public:
            virtual bool login(std::string, std::string) = 0;
            virtual ~UsuarioDAO() = 0;
    };
}
#endif