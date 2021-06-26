#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    bool ManterUsuario::cadastrarUsuario(std::string nome, std::string login, std::string senha, Modelo::TipoUsuario tipoUsuario){
        Application* app = Application::getInstance();
        // TODO
        // app->getUsuarioDAO()->cadastrar(nome, login, senha, tipoUsuario);
        return true;
    }

    bool ManterUsuario::login(){
        // TODO
        // app->getUsuarioDAO()->login()
        return true;
    }
}