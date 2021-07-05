//
// Created by felip on 04/07/2021.
//

#include "persistence/DAO/TurmaDAOJSON.hpp"


namespace Persistence{
    TurmaDAOJSON::~TurmaDAOJSON(){
        delete jsonObject;
    }

    std::string TurmaDAOJSON::ARQUIVO_TURMA =  "turmas.json";

    TurmaDAOJSON::TurmaDAOJSON() {
        jsonObject = new JSONObject(ARQUIVO_TURMA);
        checkMaxId();
    }

    Modelo::Turma* TurmaDAOJSON::cadastrar(Modelo::Turma Turma) {
        int maxId = getMaxId()+ 1;
        Turma.setId(maxId);
        atualizarRegistro(Turma);
        setMaxId(Turma.getId());
        jsonObject->salvarNoArquivo(ARQUIVO_TURMA);
        return &Turma;
    }

    Modelo::Turma* TurmaDAOJSON::pesquisar(int id) {
        std::string key = std::to_string(id);
        if(jsonObject->contains(key)) {
            Modelo::Turma* Turma = new Modelo::Turma();
            Turma->setNome(jsonObject->getStringPropertyByPath({key, "nome"}));
            Turma->setId(jsonObject->getNumberPropertyByPath({key, "id"}));
            auto idArray = jsonObject->getIntArrayPropertyByPath({key, "idsAlunos"});
            std::set<int> idSet(idArray.begin(),idArray.end());
            Turma->setAlunosCadastrados(idSet);

            return Turma;
        }
        else {
            return nullptr;
        }
    }

    std::list<Modelo::Turma> TurmaDAOJSON::pesquisar(const std::list<int> ids)  {
        std::list<Modelo::Turma> lista;
        for (int id : ids) {
            auto aux = pesquisar(id);
            if(aux != nullptr) {
                lista.push_back(*aux);
            }
        }
        return lista;
    }

    bool TurmaDAOJSON::remover(Modelo::Turma Turma) {
        std::string key = std::to_string(Turma.getId());
        if(jsonObject->contains(key)) {
            jsonObject->remover(key);
            jsonObject->salvarNoArquivo(ARQUIVO_TURMA);
            return true;
        }
        return false;
    }

    int TurmaDAOJSON::getMaxId() {
        return jsonObject->getNumberPropertyByPath({"maxId"});
    }

    void TurmaDAOJSON::setMaxId(int maxId) {
        jsonObject->setIntPropertyByPath({"maxId"},maxId);
    }

    void TurmaDAOJSON::checkMaxId() {
        try {
            jsonObject->getNumberPropertyByPath({"maxId"});
        }
        catch (...) {
            jsonObject->setIntPropertyByPath({"maxId"},0);
        }
    }

    bool TurmaDAOJSON::atualizar(Modelo::Turma Turma) {
        std::string key = std::to_string(Turma.getId());
        if(!jsonObject->contains(key))
            throw std::invalid_argument("Turma não existe");
        atualizarRegistro(Turma);
        jsonObject->salvarNoArquivo(ARQUIVO_TURMA);
        return true;
    }

    void TurmaDAOJSON::atualizarRegistro(Modelo::Turma Turma) {

        jsonObject->setStringPropertyByPath({std::to_string(Turma.getId()), "nome"},Turma.getNome());
        jsonObject->setIntPropertyByPath({std::to_string(Turma.getId()), "id"},Turma.getId());

        std::set<int> idSet = Turma.getAlunosCadastrados();
        std::vector<int> alunosIds;
        std::copy(idSet.begin(),idSet.end(),std::back_inserter(alunosIds));
        jsonObject->setIntArrayPropertyByPath({std::to_string(Turma.getId()), "idsAlunos"},alunosIds);
    }

}

