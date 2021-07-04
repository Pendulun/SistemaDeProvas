#include "business/Modelo/turma.hpp"

namespace Modelo{
    Turma::Turma(){
        this->id = -1;
        this->nome = "";
    }
    Turma::Turma(int id){
        this->id = id;
        this->nome = "";
    }

    Turma::Turma(int id, std::string nome){
         this->id = id;
        this->nome = nome;
    }

    void Turma::cadastrarAluno(int idAluno){
        this->idsAlunos.insert(idAluno);
    }

    void Turma::removerAluno(int idAluno){
        this->idsAlunos.erase(idAluno);
    }

    int Turma::getId(){
        return this->id;
    }

    void Turma::setNome(std::string nome){
        this->nome = nome;
    }

    std::string Turma::getNome(){
        return this->nome;
    }

    std::list<Prova> Turma::getProvas(){
        return this->provas;
    }

    void Turma::adicionarProva(Modelo::Prova prova){
        this->provas.push_back(prova);
    }
}