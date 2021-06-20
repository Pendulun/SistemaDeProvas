#ifndef __ALUNO_H__
#define __ALUNO_H__
#include "business/Modelo/usuario.hpp"
#include "business/Modelo/tipoUsuario.hpp"

namespace Modelo{
    class Aluno : public Usuario{
        public:
            Aluno(int id, TipoUsuario tipoUsuario) : Usuario(id, tipoUsuario){};
            Aluno(int id, TipoUsuario tipoUsuario, std::string nome, std::string login, std::string senha) : Usuario(id, tipoUsuario, nome, login, senha){};
            Aluno(int id, TipoUsuario tipoUsuario, std::string login, std::string senha) : Usuario(id, tipoUsuario, login, senha){};
    };
}
#endif