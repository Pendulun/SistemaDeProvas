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
                int idRetornado = app->getUsuarioDAO()->cadastrar(*user);
                if(idRetornado<0){
                    cadastrou = false;
                }else{
                    cadastrou = true;
                }
            }else{
                cadastrou = false;
            }
        }catch(const std::invalid_argument& e){
            std::cout<<"Erro!\n";
        }catch(const std::exception& e){
            cadastrou = false;
            std::cout<<"ERRO!\n";
        }

        delete user;
        return cadastrou;
    }

    bool ManterUsuario::atualizarUsuario(Modelo::Usuario& usuarioVelho, Modelo::Usuario& usuarioNovo){
        Application* app = Application::getInstance();
        if(app->getUsuarioDAO()->atualizar(usuarioNovo)){
            usuarioVelho.setLogin(usuarioNovo.getLogin());
            usuarioVelho.setNome(usuarioNovo.getNome());
            usuarioVelho.setSenha(usuarioNovo.getSenha());
            return true;
        }else{
            return false;
        }
    }

    bool ManterUsuario::atualizar(Modelo::Usuario& usuario){
        Application* app = Application::getInstance();
        return app->getUsuarioDAO()->atualizar(usuario);
    }

    Modelo::Usuario* ManterUsuario::login(std::string login,std::string senha){ 
        Application* app = Application::getInstance();
        Modelo::Usuario* usuarioLogado = app->getUsuarioDAO()->login(login, senha);
        if(usuarioLogado == nullptr){
            throw Business::UserNotFoundException("Usuario nao encontrado");
        }
        return usuarioLogado;
    }


}