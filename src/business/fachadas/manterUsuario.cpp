#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    bool ManterUsuario::cadastrarUsuario(std::string nome, std::string login, std::string senha, Modelo::TipoUsuario tipoUsuario){
        Application* app = Application::getInstance();
        // TODO
        // app->getUsuarioDAO()->cadastrar(nome, login, senha, tipoUsuario);
        return true;
    }

    Modelo::Usuario ManterUsuario::login(std::string login,std::string senha){
        // TODO
        // app->getUsuarioDAO()->login()
        if(true){
            throw Business::UserNotFoundException("Usuario nao encontrado");
        }
        return ;
    }
}