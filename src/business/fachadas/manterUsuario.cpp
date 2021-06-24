#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    bool ManterUsuario::cadastrarUsuario(){
        Application* app = Application::getInstance();
        //TODO
        return app->getUsuarioDAO()->cadastrar();
    }

    bool ManterUsuario::login(){
        return true;
    }
}