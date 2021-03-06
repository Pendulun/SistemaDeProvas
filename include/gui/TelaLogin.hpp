#ifndef __TELALOGIN_H__
#define __TELALOGIN_H__
#include <iostream>
#include "business/Modelo/tipoUsuario.hpp"
#include "business/fachadas/manterUsuario.hpp"
#include "business/Modelo/usuario.hpp"
#include "business/fachadas/excecoes/UserNotFoundException.hpp"
#include "business/fachadas/manterAluno.hpp"
#include "business/fachadas/manterProfessor.hpp"

namespace GUI{
    class TelaLogin{
        public:
            void show();

            Modelo::Usuario* getUser();

            ~TelaLogin();

        private:
            Modelo::Usuario* user = nullptr;

            void cadastrar();
            bool fazLogin();

            void pedirDados(std::string& nome, std::string& login, std::string& senha);
            bool checarDados(Modelo::TipoUsuario& opcaoTipoUsuario, std::string& nome, std::string& login, std::string& senha);       
    };
}
#endif