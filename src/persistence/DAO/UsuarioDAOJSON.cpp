#include "persistence/DAO/UsuarioDAOJSON.hpp"

namespace Persistence{
    UsuarioDAOJSON::~UsuarioDAOJSON(){
        delete jsonObject;
    }

    std::string UsuarioDAOJSON::ARQUIVO_USUARIOS =  "usuarios.json";

    UsuarioDAOJSON::UsuarioDAOJSON() {
        jsonObject = new JSONObject(ARQUIVO_USUARIOS);
        checkMaxId();
    }

    Modelo::Usuario* UsuarioDAOJSON::cadastrar(Modelo::Usuario usuario) {
        int maxId = getMaxId()+ 1;
        usuario.setId(maxId);
        if (loginExiste(usuario.getLogin()) )
            throw std::invalid_argument( "Login já existe" );
        jsonObject->setStringPropertyByPath({usuario.getLogin(), "nome"},usuario.getNome());
        jsonObject->setStringPropertyByPath({usuario.getLogin(), "senha"},usuario.getSenha());
        jsonObject->setIntPropertyByPath({usuario.getLogin(), "id"},usuario.getId());
        jsonObject->setIntPropertyByPath({usuario.getLogin(), "tipoUsuario"},(int)usuario.getTipoUsuario());
        setMaxId(usuario.getId());
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

    Modelo::Usuario UsuarioDAOJSON::pesquisar(int id) {
        return Modelo::Usuario();
    }

    int UsuarioDAOJSON::getMaxId() {
        return jsonObject->getNumberPropertyByPath({"maxId"});
    }

    void UsuarioDAOJSON::setMaxId(int maxId) {
        jsonObject->setIntPropertyByPath({"maxId"},maxId);
    }

    void UsuarioDAOJSON::checkMaxId() {
        try {
            jsonObject->getNumberPropertyByPath({"maxId"});
        }
        catch (...) {
            jsonObject->setIntPropertyByPath({"maxId"},0);
        }
    }

    std::list<Modelo::Usuario> UsuarioDAOJSON::pesquisar(const std::list<int>) {
        return std::list<Modelo::Usuario>();
    }

    bool UsuarioDAOJSON::remover(Modelo::Usuario) {
        return false;
    }

}
