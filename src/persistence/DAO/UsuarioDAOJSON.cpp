#include <business/Modelo/professor.hpp>
#include <business/Modelo/aluno.hpp>
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
        atualizarRegistro(usuario);
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

    Modelo::Usuario* UsuarioDAOJSON::pesquisar(int id) {
        std::string key = jsonObject->pesquisar("id",id);
        if(key != "") {
            Modelo::Usuario* usuario;
            Modelo::TipoUsuario tipo = (Modelo::TipoUsuario)jsonObject->getNumberPropertyByPath({key, "tipoUsuario"});
            if(tipo == Modelo::TipoUsuario::ALUNO)
                usuario = new Modelo::Professor;
            else
                usuario = new Modelo::Aluno;

            usuario->setNome(jsonObject->getStringPropertyByPath({key, "nome"}));
            usuario->setSenha(jsonObject->getStringPropertyByPath({key, "senha"}));
            usuario->setLogin(jsonObject->getStringPropertyByPath({key, "login"}));
            usuario->setId(jsonObject->getNumberPropertyByPath({key, "id"}));
            usuario->setTipoUsuario(tipo);

            return usuario;
        }
        else {

            return nullptr;
        }
    }

    std::list<Modelo::Usuario> UsuarioDAOJSON::pesquisar(const std::list<int> ids)  {
        std::list<Modelo::Usuario> lista;
        for (int id : ids) {
            auto aux = pesquisar(id);
            if(aux != nullptr) {
                lista.push_back(*aux);
            }
        }
        return lista;
    }

    bool UsuarioDAOJSON::remover(Modelo::Usuario usuario) {
        if(loginExiste(usuario.getLogin())) {
            jsonObject->remover(usuario.getLogin());
            jsonObject->salvarNoArquivo(ARQUIVO_USUARIOS);
            return true;
        }
        return false;
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

    bool UsuarioDAOJSON::atualizar(Modelo::Usuario usuario) {
        if (!loginExiste(usuario.getLogin()) )
            throw std::invalid_argument( "Usuário não existe" );
        atualizarRegistro(usuario);
        jsonObject->salvarNoArquivo(ARQUIVO_USUARIOS);
        return true;
    }

    void UsuarioDAOJSON::atualizarRegistro(Modelo::Usuario usuario) {

        jsonObject->setStringPropertyByPath({usuario.getLogin(), "nome"},usuario.getNome());
        jsonObject->setStringPropertyByPath({usuario.getLogin(), "login"},usuario.getLogin());
        jsonObject->setStringPropertyByPath({usuario.getLogin(), "senha"},usuario.getSenha());
        jsonObject->setIntPropertyByPath({usuario.getLogin(), "id"},usuario.getId());
        jsonObject->setIntPropertyByPath({usuario.getLogin(), "tipoUsuario"},(int)usuario.getTipoUsuario());
        std::list<int> turmas = usuario.getTurmas();
        std::vector<int> turmasCadastrar(turmas.begin(),turmas.end());
        jsonObject->setIntArrayPropertyByPath({usuario.getLogin(), "turmas"},turmasCadastrar);
    }

    bool UsuarioDAOJSON::cadastrarEmTurma(Modelo::Usuario usuario, int idTurma) {
        if(!loginExiste(usuario.getLogin())) {
            return false;
        }
        auto turmasUsuario = jsonObject->getIntArrayPropertyByPath({usuario.getLogin(),"turmas"});
        turmasUsuario.push_back(idTurma);
        jsonObject->setIntArrayPropertyByPath({usuario.getLogin(),"turmas"},turmasUsuario);
        jsonObject->salvarNoArquivo(ARQUIVO_USUARIOS);

        return true;
    }

}
