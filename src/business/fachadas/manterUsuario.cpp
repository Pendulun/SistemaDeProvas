#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    bool ManterUsuario::cadastrarUsuario(std::string nome, std::string login, std::string senha, Modelo::TipoUsuario tipoUsuario){
        Application* app = Application::getInstance();
        // TODO
        // app->getUsuarioDAO()->cadastrar(nome, login, senha, tipoUsuario);
        return true;
    }

    Modelo::Usuario* ManterUsuario::login(std::string login,std::string senha){
        // TODO
        // app->getUsuarioDAO()->login()
        int idUser = 1;
        std::string nomeUser = "Professor Teste";
        std::string loginUser = login;
        std::string senhaUser = senha;
        Modelo::Usuario* dummyUser = new Modelo::Usuario(idUser, Modelo::TipoUsuario::PROFESSOR, nomeUser , loginUser, senhaUser);
        if(dummyUser == nullptr){
            throw Business::UserNotFoundException("Usuario nao encontrado");
        }else{
            return dummyUser;
        }
    }
}