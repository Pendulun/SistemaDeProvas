#ifndef __Professor_CPP__
#define __Professor_CPP__
#include <string>
#include <vector>

class Professor
{
public:
    bool operator==(const Professor aluno) const { return this->id == aluno.id; }
    int id;

    Professor(int id, std::string nome) {
        this->id = id;
        this->setNome(nome);
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
    std::string nome;
    std::vector<int> materias;

};

#endif