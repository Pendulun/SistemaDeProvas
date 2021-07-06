#include "business/fachadas/manterUsuario.hpp"

namespace Business{
    bool ManterUsuario::cadastrarUsuario(std::string nome, std::string login, std::string senha, Modelo::TipoUsuario tipoUsuario){
        bool cadastrou = false;
        Modelo::Usuario* user = new Modelo::Usuario();
        Application* app = Application::getInstance();
        try{
            if(!app->getUsuarioDAO()->loginExiste(login)){
                user->setNome(nome);
                user->setLogin(login);
                user->setSenha(senha);
                user->setTipoUsuario(tipoUsuario);
                Modelo::Usuario* userCadastrado = app->getUsuarioDAO()->cadastrar(*user);
                if(userCadastrado->getId()==-1){
                    cadastrou = false;
                }else{
                    cadastrou = true;
                }
            }else{
                cadastrou = false;
            }
        }catch(const std::exception& e){
            cadastrou = false;
            std::cout<<"ERRO!\n";
            std::cout<<e.what()<<std::endl;
        }

        delete user;
        return cadastrou;
    }

    Modelo::Usuario* ManterUsuario::login(std::string login,std::string senha){
        // TODO
        // app->getUsuarioDAO()->login()
        int idUser = 1;
        std::string nomeUser = "Usuario Teste";
        std::string loginUser = login;
        std::string senhaUser = senha;
        Modelo::TipoUsuario tipo = Modelo::TipoUsuario::PROFESSOR;
        Modelo::Usuario* dummyUser = new Modelo::Usuario(idUser, tipo, nomeUser , loginUser, senhaUser);
        if(dummyUser == nullptr){
            throw Business::UserNotFoundException("Usuario nao encontrado");
        }else{
            return dummyUser;
        }
    }
}