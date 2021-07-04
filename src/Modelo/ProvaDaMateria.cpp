#ifndef __ProvaDaMateria_CPP__
#define __ProvaDaMateria_CPP__

#include <map>
#include <vector>
#include <string>
#include "Questao.cpp"
#include <unordered_map>
#include "ProvaResolvida.cpp"

class Prova
{
public:
    int id;

	Prova(int id, int materiaId) {
		this->id = id;
        this->materiaId = materiaId;
        this->disponivelParaResposta = false;
        this->notasVisiveis = false;
	}

    int getMateriaId() {
        return this->id;
    }

    void setMateriaId(int novoId) {
        this->id = novoId;
    }

    void setNotasVisiveis(bool notasVisiveis) {
        this->notasVisiveis = notasVisiveis;
    }

    bool getNotasVisiveis() {
        return this->notasVisiveis;
    }

    void setDisponivelParaRespostas(bool disponivelParaResposta) {
        this->disponivelParaResposta = disponivelParaResposta;
    }

    bool estaDisponivelParaResposta() {
        return this->disponivelParaResposta;
    }

private:
    int materiaId;
    bool disponivelParaResposta;
    bool notasVisiveis;
    std::vector<Questao> questoes;
    std::unordered_map<int, ProvaResolvida> subsmissoesAlunos;
};

#endif