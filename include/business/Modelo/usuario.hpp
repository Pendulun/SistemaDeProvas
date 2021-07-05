#ifndef __USUARIO_H__
#define __USUARIO_H__
#include <string>
#include <list>
#include "business/Modelo/tipoUsuario.hpp"
namespace Modelo{
    class Usuario{
        protected:
            std::string nome;
            std::string login;
            std::string senha;
            TipoUsuario tipoUsuario;
            int id;
            std::list<int> turmas;
        public:
            std::string getNome();
            void setNome(std::string);
            std::string getLogin();
            void setLogin(std::string);
            std::string getSenha();
            void setSenha(std::string);
            TipoUsuario getTipoUsuario();
            void setTipoUsuario(TipoUsuario);
            bool isAluno();
            bool isProfessor();
            int getId();
            void setId(int);
            const std::list<int> getTurmas();
            void  setTurmas(std::list<int>);
            Usuario(int id, TipoUsuario);
            Usuario(int id, TipoUsuario, std::string nome, std::string login, std::string senha);
            Usuario(int id, TipoUsuario, std::string login, std::string senha);
            Usuario();
    };
}
#endif