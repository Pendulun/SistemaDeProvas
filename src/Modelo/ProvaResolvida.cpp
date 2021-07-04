#ifndef __ProvaResolvida_CPP__
#define __ProvaResolvida_CPP__

#include <string>
#include <vector>
#include "Alternativa.cpp"

class ProvaResolvida
{
public:
	int id;

	ProvaResolvida(std::vector<Alternativa> alternativas) {
		this->alternativas = alternativas;
	}

	std::vector<Alternativa> getRespostas() {
		return this->alternativas;
	}

	void setPontuacao(float pontuacao) {
		this->pontuacao = pontuacao;
	}

	float getPontuacao() {
		return this->pontuacao;
	}

private:
	std::vector<Alternativa> alternativas;
	float pontuacao;
	
};


#endif