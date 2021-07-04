#ifndef __Questao_CPP__
#define __Questao_CPP__

#include <string>
#include <vector>
#include "Alternativa.cpp"

class Questao
{
public:
	int id;
	Questao(int id, std::string enunciado, float valor) {
		this->id = id;
		this->enunciado = enunciado;
		this->valor = valor;
	};

	void setAlternativas(std::vector<Alternativa> alternativas) {
		this->alternativas = alternativas;
	}

	std::vector<Alternativa> getAlternativas() {
		return this->alternativas;
	}

	void setValor(float valor) {
		this->valor = valor;
	}

	float getValor() {
		return this->valor;
	}

	void setEnunciado(std::string enunciado) {
		this->enunciado = enunciado;
	}

	std::string getEnumciado() {
		return this->enunciado;
	}

	void setAlternativaCorreta(Alternativa alternativa) {
		this->alternativaCorreta = alternativa;
	}

	Alternativa getAlternativaCorreta() {
		return this->alternativaCorreta;
	}


private:
	int provaDaMateriaId;
	std::string enunciado;
	float valor;
	std::vector<Alternativa> alternativas;
	Alternativa alternativaCorreta;
};

#endif