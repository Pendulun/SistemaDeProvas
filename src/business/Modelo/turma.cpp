#include "business/Modelo/turma.hpp"

namespace Modelo{
    Turma::Turma(){
        this->id = -1;
        this->nome = "";
        this->provas.clear();
    }
    Turma::Turma(int id){
        this->id = id;
        this->nome = "";
        this->provas.clear();
    }

    Turma::Turma(int id, std::string nome){
        this->id = id;
        this->nome = nome;
        this->provas.clear();
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
    
    void Turma::setId(int id) {
        this->id = id;
    }

    std::set<int> Turma::getAlunosCadastrados() {
        return this->idsAlunos;
    }

    void Turma::setAlunosCadastrados(std::set<int> alunoIds) {
        this->idsAlunos = std::move(alunoIds);
    }

    std::list<Prova> Turma::getProvasPendentes(){
        std::list<Prova> lista={};
        for (std::list<Prova>::iterator it = this->provas.begin(); it != this->provas.end(); ++it){
            if (it->getStatus()==Status::PENDING){
                lista.push_back(*it);
            }
        }
        return lista;
    }

    Prova* Turma::getProvaPorID(int id){
        for (std::list<Prova>::iterator it = this->provas.begin(); it != this->provas.end(); ++it){
            if (it->getId()==id){
                return &(*it);
            }
        }
        return nullptr;
    }

}