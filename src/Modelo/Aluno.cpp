#ifndef __Aluno_CPP__
#define __Aluno_CPP__
#include <string>
#include <vector>

class Aluno
{
public:
    bool operator==(const Aluno aluno) const { return this->id == aluno.id; }
    Aluno(int id,std::string nome) {
        this->setId(id);
        this->setNome(nome);
    }

    Aluno() {}

    int getId() {
        return this->id;
    }

    void setId(int novoId) {
        this->id = novoId;
    }

    std::string getNome() {
        return this->nome;
    }

    void setNome(std::string novoNome) {
        this->nome = novoNome;
    }

    std::vector<int> getMaterias() {
        return this->materias;
    }

    void setMaterias(std::vector<int> materias) {
        this->materias = materias;
    }

    void adicionarAluno(int id) {
        this->materias.push_back(id);
    }

    void removerAluno(int id) {
        auto it = std::find(this->materias.begin(), this->materias.end(), id);
        if (it != this->materias.end())
        {
            this->materias.erase(it);
        }
    }

private:
    int id;
    std::string nome;
    std::vector<int> materias;

};

#endif