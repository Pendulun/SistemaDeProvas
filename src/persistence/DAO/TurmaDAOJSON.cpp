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
        prova.setId(getMaxId(MAX_ID_PROVA) + 1);

        atualizarRegistroProva(idTurma,prova);

        setMaxId(MAX_ID_PROVA,prova.getId());
        jsonObject->salvarNoArquivo(ARQUIVO_TURMA);

        return prova.getId();
    }

    void TurmaDAOJSON::cadastrarQuestao(int idTurma, int idProva, Modelo::Questao questao) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(idProva);
        std::string keyQuestao = std::to_string(questao.getNumeroQuestao());

        jsonObject->setStringPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "enunciado"},questao.getEnunciado());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "valor"},questao.getValor());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "numeroQuestao"},questao.getNumeroQuestao());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "alternativaCorreta"},questao.getAlternativaCorreta());
        jsonObject->setEmptyObjectPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "alternativas"});

        for(auto alternativa : questao.getAlternativas()) {
            cadastrarAlternativa(idTurma,idProva,questao.getNumeroQuestao(),alternativa);
        }

    }

    void TurmaDAOJSON::cadastrarAlternativa(int idTurma, int idProva, int numQuestao, Modelo::Alternativa alternativa) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(idProva);
        std::string keyQuestao = std::to_string(numQuestao);
        std::string keyAlternativa = std::to_string(alternativa.getNumeroAlternativa());

        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "alternativas", keyQuestao, "numeroAlternativa"},
                                         alternativa.getNumeroAlternativa());
        jsonObject->setStringPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "alternativas", keyQuestao, "texto"},
                                         alternativa.getTexto());

    }

    void TurmaDAOJSON::atualizarRegistroProva(int  idTurma, Modelo::Prova prova) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(prova.getId());

        jsonObject->setStringPropertyByPath({keyTurma,"provas",keyProva, "nome"},prova.getNome());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "id"},prova.getId());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "dataInicio"},prova.getDataInicio());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "dataFinal"},prova.getDataFinal());
        jsonObject->setIntPropertyByPath({keyTurma,"provas",keyProva, "status"},(int)prova.getStatus());
        auto assuntos =  prova.getAssuntos();
        std::vector<std::string> assuntosInserir(assuntos.begin(),assuntos.end());
        jsonObject->setStringArrayPropertyByPath({keyTurma,"provas",keyProva, "assuntos"},assuntosInserir);
        jsonObject->setEmptyObjectPropertyByPath({keyTurma,"provas",keyProva, "questoes"});

        for(auto questao : prova.getQuestaos()) {
            cadastrarQuestao(idTurma,prova.getId(),questao);
        }
    }

    bool TurmaDAOJSON::atualizarProva(int idTurma, Modelo::Prova prova) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(prova.getId());
        if (!jsonObject->containsPath({keyTurma,"provas",keyProva}))
            return false;

        atualizarRegistroProva(idTurma,prova);
        jsonObject->salvarNoArquivo(ARQUIVO_TURMA);
        return true;
    }

    Modelo::Prova *TurmaDAOJSON::pesquisarProva(int idTurma, int idProva) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(idProva);
        if (!jsonObject->containsPath({keyTurma,"provas",keyProva}))
            return nullptr;
        Modelo::Prova* prova = new Modelo::Prova();

        prova->setNome(jsonObject->getStringPropertyByPath({keyTurma,"provas",keyProva, "nome"}));
        prova->setId(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva, "id"}));
        prova->setDataFinal(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva, "dataFinal"}));
        prova->setDataInicio(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva, "dataFinal"}));
        prova->setStatus((Modelo::Status)jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva, "status"}));

        auto assuntos = jsonObject->getStringArrayPropertyByPath({keyTurma,"provas",keyProva, "assuntos"});
        for(auto assunto : assuntos) {
            prova->addAssunto(assunto);
        }

        for(auto key : jsonObject->getObjectKeys({keyTurma,"provas",keyProva, "questoes"})) {
            auto questao = buscarQuestao(idTurma,idProva,std::stoi(key));
            prova->addQuestao(*questao);
        }

        return prova;
    }

    Modelo::Questao *TurmaDAOJSON::buscarQuestao(int idTurma, int idProva, int numQuestao) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(idProva);
        std::string keyQuestao = std::to_string(numQuestao);

        auto* questao = new Modelo::Questao();

        questao->setEnunciado(jsonObject->getStringPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "enunciado"}));
        questao->setValor(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "valor"}));
        questao->setNumeroQuestao(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "numeroQuestao"}));
        questao->setAlternativaCorreta(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao, "alternativaCorreta"}));

        for(auto key : jsonObject->getObjectKeys({keyTurma,"provas",keyProva,"questoes", keyQuestao, "alternativas"})) {
            auto alternativa = buscarAlternativa(idTurma,idProva,numQuestao,std::stoi(key));
            questao->addAlternativa(*alternativa);
        }

        return questao;
    }

    Modelo::Alternativa *TurmaDAOJSON::buscarAlternativa(int idTurma, int idProva,
                                                         int numQuestao, int numAlternativa) {
        std::string keyTurma = std::to_string(idTurma);
        std::string keyProva = std::to_string(idProva);
        std::string keyQuestao = std::to_string(numQuestao);
        std::string keyAlternativa = std::to_string(numAlternativa);

        auto alternativa = new Modelo::Alternativa();

        alternativa->setNumeroAlternativa(jsonObject->getNumberPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao,
                                                                               "alternativas", keyQuestao, "numeroAlternativa"}));
        alternativa->setTexto(jsonObject->getStringPropertyByPath({keyTurma,"provas",keyProva,"questoes", keyQuestao,
                                             "alternativas", keyQuestao, "texto"}));

        return alternativa ;
    }


}

