#ifndef __ALUNO_H__
#define __ALUNO_H__
#include <list>
#include "business/Modelo/usuario.hpp"
#include "business/Modelo/tipoUsuario.hpp"
#include "business/Modelo/turma.hpp"

namespace Modelo{
    class Aluno : public Usuario{
        public:
            Aluno(int id, TipoUsuario tipoUsuario) : Usuario(id, tipoUsuario){};
            Aluno(int id, TipoUsuario tipoUsuario, std::string nome, std::string login, std::string senha) : Usuario(id, tipoUsuario, nome, login, senha){};
            Aluno(int id, TipoUsuario tipoUsuario, std::string login, std::string senha) : Usuario(id, tipoUsuario, login, senha){};
            bool isEmTurma(int);
            void adicionarTurma(Modelo::Turma);
            void removerTurma(int);
        private:
            std::list<Turma> turmas;
    };
}
#endif