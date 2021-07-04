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

        Modelo::Turma* cadastrar(Modelo::Turma ) override;
        Modelo::Turma* pesquisar(int ) override;
        std::list<Modelo::Turma> pesquisar(const std::list<int>) override;
        bool remover(Modelo::Turma) override;
        ~TurmaDAOJSON() override;

    private:
        void checkMaxId();
        int getMaxId();
        void setMaxId(int);
        JSONObject* jsonObject;
    };
}

#endif //SISTEMA_PROVAS_TURMADAOJSON_HPP
