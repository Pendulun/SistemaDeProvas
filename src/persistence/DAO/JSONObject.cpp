//
// Created by felip on 29/06/2021.
//

#include "persistence/DAO/JSONObject.hpp"
#include "persistence/DAO/JSONFileHandler.hpp"

namespace Persistence  {


    JSONObject::JSONObject() {}

    JSONObject::JSONObject(std::string Arquivo) {
        JsonHandler jsonHandler;
        document = jsonHandler.LerArquivo(Arquivo);
    }

    JSONObject::JSONObject(nlohmann::json doc) {
        document = doc;
    }

    void JSONObject::setStringPropertyByPath(std::vector<std::string> Path, std::string property) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = property;
    }

    void JSONObject::setIntPropertyByPath(std::vector<std::string> Path,int property) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = property;
    }

    void JSONObject::setBoolPropertyByPath(std::vector<std::string> Path, bool property) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = property;
    }

    nlohmann::json JSONObject::getObjectPropertyByPath(std::vector<std::string> Path) {
        std::string path = getPathFromVector(Path);
        nlohmann::json Property = document[nlohmann::json::json_pointer(path)];

        return Property;
    }

    std::string JSONObject::getStringPropertyByPath(std::vector<std::string> Path) {
        nlohmann::json Property = getObjectPropertyByPath(Path);

        if (Property.is_string())
            return Property;
        else
            return "";
    }

    std::string JSONObject::getPathFromVector(std::vector<std::string> Steps) {
        std::string path = "";
        for (auto step : Steps) {
            path = path + "/" + step;
        }
        return path;
    }

    void JSONObject::setDocument(nlohmann::json doc) {
        document = doc;
    }

    nlohmann::json JSONObject::getDocument() {
        return document;
    }

    void JSONObject::salvarNoArquivo(std::string Arquivo) {
        JsonHandler jsonHandler;
        jsonHandler.SalvarEmArquivo(Arquivo,document);
    }


}
