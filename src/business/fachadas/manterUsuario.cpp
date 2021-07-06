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

    bool ManterUsuario::atualizarUsuario(Modelo::Usuario& usuarioVelho, Modelo::Usuario& usuarioNovo){
        /*
        Application* app = Application::getInstance();
        if(app->getUsuarioDAO()->atualizar(usuarioNovo)){
            usuarioVelho.setLogin(usuarioNovo.getLogin());
            usuarioVelho.setNome(usuarioNovo.getNome());
            usuarioVelho.setSenha(usuarioNovo.getSenha());
            return true;
        }else{
            return false;
        }
        */
        return true;
    }

    Modelo::Usuario* ManterUsuario::login(std::string login,std::string senha){
        // TODO
        /*
        Application* app = Application::getInstance();
        Modelo::Usuario* usuarioLogado = app->getUsuarioDAO()->login(login, senha);
        if(usuarioLogado == nullptr){
            throw Business::UserNotFoundException("Usuario nao encontrado");
        }
        return usuarioLogado;
        */
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