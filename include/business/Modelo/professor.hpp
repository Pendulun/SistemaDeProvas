#ifndef __PROFESSOR_H__
#define __PROFESSOR_H__
#include "business/Modelo/usuario.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include <list>
#include <iterator>

namespace Modelo{
    class Professor : public Usuario{
        public:
            Professor() : Usuario(){};
            Professor(int id, TipoUsuario tipoUsuario) : Usuario(id, tipoUsuario){};
            Professor(int id, TipoUsuario tipoUsuario, std::string nome, std::string login, std::string senha) : Usuario(id, tipoUsuario, nome, login, senha){};
            Professor(int id, TipoUsuario tipoUsuario, std::string login, std::string senha) : Usuario(id, tipoUsuario, login, senha){};
            bool possuiTurma(int);
            void adicionarTurma(int);
            void removerTurma(int);
            void finalizarDisponibilidadeProva(int);
        private:
    };
}
#endif