//
// Created by felip on 04/07/2021.
//

#include "persistence/DAO/TurmaDAOJSON.hpp"


namespace Persistence{
    TurmaDAOJSON::~TurmaDAOJSON(){
        delete jsonObject;
    }

    std::string TurmaDAOJSON::ARQUIVO_TURMA =  "turmas.json";
    std::string TurmaDAOJSON::MAX_ID_TURMA = "maxId";
    std::string TurmaDAOJSON::MAX_ID_PROVA = "maxIdProva";

    TurmaDAOJSON::TurmaDAOJSON() {
        jsonObject = new JSONObject(ARQUIVO_TURMA);
        checkMaxId();
    }

    int TurmaDAOJSON::cadastrar(Modelo::Turma Turma) {
        int maxId = getMaxId(MAX_ID_TURMA)+ 1;
        Turma.setId(maxId);
        atualizarRegistro(Turma);
        jsonObject->setEmptyObjectPropertyByPath({std::to_string(Turma.getId()), "provas"});
        setMaxId(MAX_ID_TURMA,Turma.getId());
        jsonObject->salvarNoArquivo(ARQUIVO_TURMA);
        return Turma.getId();
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

    int TurmaDAOJSON::getMaxId(std::string Path) {
        return jsonObject->getNumberPropertyByPath({Path});
    }

    void TurmaDAOJSON::setMaxId(std::string Path,int maxId) {
        jsonObject->setIntPropertyByPath({Path},maxId);
    }

    void TurmaDAOJSON::checkMaxId() {
        auto maxIds = { MAX_ID_PROVA, MAX_ID_TURMA};
        for(auto path : maxIds) {
            try {
                jsonObject->getNumberPropertyByPath({path});
            }
            catch (...) {
                jsonObject->setIntPropertyByPath({path},0);
            }
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

    int TurmaDAOJSON::cadastrarProva(int idTurma,Modelo::Prova prova) {
        std::string keyTurma = std::to_string(idTurma);
        prova.setId(getMaxId(MAX_ID_PROVA) + 1);
        std::string keyProva = std::to_string(prova.getId());

        jsonObject->setStringPropertyByPath({keyTurma,"provas",keyProva, "nome"},prova.getNome());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "id"},prova.getId());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "dataInicio"},prova.getDataInicio());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "dataFinal"},prova.getDataFinal());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "status"},(int)prova.getStatus());
        setMaxId(MAX_ID_PROVA,prova.getId());
        jsonObject->salvarNoArquivo(ARQUIVO_TURMA);

        return prova.getId();
    }

}

