#ifndef __PROFESSOR_H__
#define __PROFESSOR_H__
#include "business/Modelo/usuario.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include "business/Modelo/turma.hpp"
#include <list>
#include <iterator>

namespace Modelo{
    class Professor : public Usuario{
        public:
            Professor(int id, TipoUsuario tipoUsuario) : Usuario(id, tipoUsuario){};
            Professor(int id, TipoUsuario tipoUsuario, std::string nome, std::string login, std::string senha) : Usuario(id, tipoUsuario, nome, login, senha){};
            Professor(int id, TipoUsuario tipoUsuario, std::string login, std::string senha) : Usuario(id, tipoUsuario, login, senha){};
            bool possuiTurma(std::string);
            void adicionarTurma(Turma);
            void removerTurma(int id);
        private:
            std::list<Turma> turmas;
    };
}
#endif