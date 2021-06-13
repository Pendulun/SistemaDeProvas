#ifndef __Alternativa_CPP__
#define __Alternativa_CPP__

#include <string>

class Alternativa
{
public:
	int id;
	Alternativa();

	Alternativa(int id, std::string texto,int questaoId) {
		this->id = id;
		this->texto = texto;
		this->questaoId = questaoId;
	}

	std::string getTexto() {
		return this->texto;
	}

	int getQuestaoId() {
		return this->questaoId;
	}

private:
	std::string texto;
	int questaoId;
};


#endif