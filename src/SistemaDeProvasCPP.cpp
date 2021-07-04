// SistemaDeProvasCPP.cpp : Defines the entry point for the application.
//

#include "SistemaDeProvasCPP.h"

using namespace std;

int main()
{
	AlunoDAO alunoDAO;
	Aluno aluno = Aluno(1,"Felipe");
	Aluno aluno2 = Aluno(2,"Felipe Cordeiro");
	alunoDAO.getAlunosMateria(aluno);
	alunoDAO.getAlunosMateria(aluno2);

	Materia materia;
	materia.adicionarAluno(aluno.getId());

	cout << materia.getAlunos().at(0) << endl;
	return 0;
}
