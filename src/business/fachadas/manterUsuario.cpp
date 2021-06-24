#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    bool ManterUsuario::cadastrarUsuario(){
        Application* app = Application::getInstance();
        return true;
    }

    bool ManterUsuario::login(){
        return true;
    }
}