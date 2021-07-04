#ifndef __TURMA_H__
#define __TURMA_H__
#include <string>
#include <set>
#include <list>
#include "business/Modelo/prova.hpp"

namespace Modelo{
    class Turma {
        public:
            void cadastrarAluno(int id);
            void removerAluno(int id);
            std::set<int> getAlunosCadastrados();
            void setAlunosCadastrados(std::set<int>);
            Turma(int id, std::string nome);
            Turma(int id);
            Turma();
            int getId();
            void setId(int);
            std::string getNome();
            void setNome(std::string);
            std::list<Prova> getProvas();
            void adicionarProva(Modelo::Prova);
        private:
            std::list<Prova> provas;
            std::set<int> idsAlunos;
            int id;
            std::string nome;
    };
}
#endif