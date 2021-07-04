#ifndef __Materia_CPP__
#define __Materia_CPP__
#include <string>
#include <vector>
#include "Aluno.cpp"
#include "ProvaDaMateria.cpp"

class Materia
{
public:
    bool operator==(const Materia materia) const { return this->id == materia.id; }
    int id;

    Materia() {
    }

    Materia(int id,std::string nome) {
        this->id = id;
        this->setNome(nome);
    }

    Materia(int id, std::string nome, std::vector<int> alunos) {
        this->id = id;
        this->setNome(nome);
        this->alunos = alunos;
    }

    int getProfessorId() {
        return this->professorId;
    }

    void setProfessorId(int novoId) {
        this->professorId = novoId;
    }

    std::string getNome() {
        return this->nome;
    }

    void setNome(std::string novoNome) {
        this->nome = novoNome;
    }

    std::vector<int> getAlunos() {
        return this->alunos;
    }

    void setAlunos(std::vector<int> alunos) {
        this->alunos = alunos;
    }

    void adicionarAluno(int id) {
        this->alunos.push_back(id);
    }

    void removerAluno(int id) {
        auto it = std::find(this->alunos.begin(), this->alunos.end(), id);
        if (it != this->alunos.end())
        {
            this->alunos.erase(it);
        }
    }



private:
    int professorId;
    std::string nome;
    std::vector<int> alunos;
    std::vector<Prova> Provas;
};

#endif
