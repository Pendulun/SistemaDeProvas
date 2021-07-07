#include "business/Modelo/usuario.hpp"
#include "business/fachadas/manterTurma.hpp"

namespace Modelo{

    Usuario::Usuario(){
        this->id = -1;
        this->nome = "";
        this->login = "";
        this->senha = "";
        this->tipoUsuario = Modelo::TipoUsuario::ALUNO;
    }

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

    void Usuario::setId(int id) {
        this->id = id;
    }

    const std::list<int> Usuario::getTurmas(){
        return this->turmas;
    }

    void Usuario::setTurmas(std::list<int> turmas) {
        this->turmas = std::move(turmas);
    }

    std::list<Prova> Usuario::getProvasPendentes(){
        std::list<Prova> lista={};
        Business::ManterTurma manterTurma;
        for (std::list<int>::iterator it = this->turmas.begin(); it != this->turmas.end(); ++it){
            Turma* t=manterTurma.pesquisarTurma(*it);
            lista.splice( std::end( lista ), t->getProvasPendentes() );
        }
        return lista;
    }
}
