#include "business/Modelo/usuario.hpp"

namespace Modelo{

    Usuario::Usuario(int id, Modelo::TipoUsuario tipoUsuario){
        this->id = id;
        this->nome = "";
        this->login = "";
        this->senha = "";
        this->tipoUsuario = tipoUsuario;
    }

    Usuario::Usuario(int id, Modelo::TipoUsuario tipoUsuario, std::string nome, std::string login, std::string senha){
        this->id = id;
        this->nome = nome;
        this->login = login;
        this->senha = senha;
        this->tipoUsuario = tipoUsuario;
    }

    Usuario::Usuario(int id, TipoUsuario tipoUsuario, std::string login, std::string senha){
        this->id = id;
        this->nome = "";
        this->login = login;
        this->senha = senha;
        this->tipoUsuario = tipoUsuario;
    }

    std::string Usuario::getNome(){
        return this->nome;
    }

    void Usuario::setNome(std::string nome){
        this->nome = nome;
    }

    std::string Usuario::getLogin(){
        return this->login;
    }

    void Usuario::setLogin(std::string login){
        this->login = login;
    }

    std::string Usuario::getSenha(){
        return this->senha;
    }

    void Usuario::setSenha(std::string senha){
        this->senha = senha;
    }

    TipoUsuario Usuario::getTipoUsuario(){
        return this->tipoUsuario;
    }

    void Usuario::setTipoUsuario(TipoUsuario tipoUsuario){
        this->tipoUsuario = tipoUsuario;
    }

    bool Usuario::isAluno(){
        return this->tipoUsuario == Modelo::TipoUsuario::ALUNO;
    }

    bool Usuario::isProfessor(){
        return this->tipoUsuario == Modelo::TipoUsuario::PROFESSOR;
    }

    int Usuario::getId(){
        int idCopia = this->id;
        return idCopia;
    }
}
