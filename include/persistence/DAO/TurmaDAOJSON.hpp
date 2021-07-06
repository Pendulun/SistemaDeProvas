//
// Created by felip on 04/07/2021.
//

#ifndef SISTEMA_PROVAS_TURMADAOJSON_HPP
#define SISTEMA_PROVAS_TURMADAOJSON_HPP
#include <string>
#include "persistence/DAO/JSONFileHandler.hpp"
#include "JSONObject.hpp"
#include "business/DAO/TurmaDAO.hpp"

namespace Persistence {
    class TurmaDAOJSON : public Business::TurmaDAO {
    public:
        TurmaDAOJSON();

        static std::string ARQUIVO_TURMA;
        static std::string MAX_ID_TURMA;
        static std::string MAX_ID_PROVA;

        int cadastrar(Modelo::Turma ) override;
        Modelo::Turma* pesquisar(int ) override;
        std::list<Modelo::Turma> pesquisar(const std::list<int>) override;
        bool remover(Modelo::Turma) override;
        bool atualizar(Modelo::Turma) override;
        int cadastrarProva(int,Modelo::Prova) override;
        bool atualizarProva(int,Modelo::Prova) override;
        Modelo::Prova* pesquisarProva(int,int) override;
        ~TurmaDAOJSON() override;

    private:
        void checkMaxId();
        int getMaxId(std::string);
        void setMaxId(std::string,int);
        void atualizarRegistro(Modelo::Turma);
        void atualizarRegistroProva(int, Modelo::Prova);
        void cadastrarQuestao(int,int,Modelo::Questao);
    Modelo::Questao* buscarQuestao(int,int,int);
        void cadastrarAlternativa(int,int,int,Modelo::Alternativa);
        Modelo::Alternativa* buscarAlternativa(int,int,int,int);
        JSONObject* jsonObject;
    };
}

#endif //SISTEMA_PROVAS_TURMADAOJSON_HPP
