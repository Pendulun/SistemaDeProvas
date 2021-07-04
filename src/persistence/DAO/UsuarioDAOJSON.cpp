#include "persistence/DAO/UsuarioDAOJSON.hpp"

namespace Persistence{
    UsuarioDAOJSON::~UsuarioDAOJSON(){
        delete jsonObject;
    }

    std::string UsuarioDAOJSON::ARQUIVO_USUARIOS =  "usuarios.json";

    UsuarioDAOJSON::UsuarioDAOJSON() {
        jsonObject = new JSONObject(ARQUIVO_USUARIOS);
    }
    
    Modelo::Usuario* UsuarioDAOJSON::cadastrar(Modelo::Usuario usuario) {

        if (loginExiste(usuario.getLogin()) )
            throw std::invalid_argument( "Login já existe" );
        jsonObject->setStringPropertyByPath({usuario.getLogin(), "nome"},usuario.getNome());
        jsonObject->setStringPropertyByPath({usuario.getLogin(), "senha"},usuario.getSenha());
        jsonObject->setIntPropertyByPath({usuario.getLogin(), "id"},usuario.getId());
        jsonObject->setIntPropertyByPath({usuario.getLogin(), "tipoUsuario"},(int)usuario.getTipoUsuario());
        jsonObject->salvarNoArquivo(ARQUIVO_USUARIOS);
        return &usuario;
    }

    bool UsuarioDAOJSON::loginExiste(std::string login) {
        std::vector<std::string> Path = { login };
        auto user = jsonObject->getObjectPropertyByPath(Path);
        bool existe = user == nullptr;
        return !(existe);
    }

    bool UsuarioDAOJSON::login(std::string login, std::string senha) {
        std::vector<std::string> path = { login, "senha"};
        auto senhaBanco = jsonObject->getStringPropertyByPath(path);
        if (senha == senhaBanco)
            return true;
        return false;
    }

}
