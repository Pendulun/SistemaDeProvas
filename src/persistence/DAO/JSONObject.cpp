//
// Created by felip on 29/06/2021.
//

#include "persistence/DAO/JSONObject.hpp"

#include <utility>
#include "persistence/DAO/JSONFileHandler.hpp"

namespace Persistence  {


    JSONObject::JSONObject() {}

    JSONObject::JSONObject(std::string Arquivo) {
        JsonHandler jsonHandler;
        document = jsonHandler.LerArquivo(std::move(Arquivo));
    }

    JSONObject::JSONObject(nlohmann::json doc) {
        document = std::move(doc);
    }

    void JSONObject::setStringPropertyByPath(const std::vector<std::string>& Path, const std::string& property) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = property;
    }

    void JSONObject::setIntPropertyByPath(const std::vector<std::string>& Path,int property) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = property;
    }

    void JSONObject::setIntArrayPropertyByPath(const std::vector<std::string>& Path,const std::vector<int>& values) {
        nlohmann::json array = nlohmann::json::array();
        for (auto value : values)
        {
            array.push_back(value);
        };
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = array;
    }

    void JSONObject::setEmptyObjectPropertyByPath(const std::vector<std::string> &Path) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = nlohmann::json::object();
    }

    void JSONObject::setBoolPropertyByPath(const std::vector<std::string>& Path, bool property) {
        std::string path = getPathFromVector(Path);
        document[nlohmann::json::json_pointer(path)] = property;
    }

    nlohmann::json JSONObject::getObjectPropertyByPath(const std::vector<std::string>& Path) {
        std::string path = getPathFromVector(Path);
        nlohmann::json Property = document[nlohmann::json::json_pointer(path)];

        return Property;
    }

    std::string JSONObject::getStringPropertyByPath(const std::vector<std::string>& Path) {
        nlohmann::json Property = getObjectPropertyByPath(Path);

        if (Property.is_string())
            return Property;
        else
            throw std::exception("Invalid Path");
    }

    double JSONObject::getNumberPropertyByPath(const std::vector<std::string>& Path) {
        nlohmann::json Property = getObjectPropertyByPath(Path);

        if (Property.is_number())
            return Property;
        else
            throw std::exception("Invalid Path");
    }

    bool JSONObject::getBoolPropertyByPath(const std::vector<std::string>& Path) {
        nlohmann::json Property = getObjectPropertyByPath(Path);

        if (Property.is_boolean())
            return Property;
        else
            throw std::exception("Invalid Path");
    }

    std::vector<int> JSONObject::getIntArrayPropertyByPath(const std::vector<std::string> &Path) {
        std::vector<int> array;
        nlohmann::json Property = getObjectPropertyByPath(Path);
        if(Property.is_array()) {
            for(auto item : Property) {
                if(item.is_number_integer()) {
                    array.push_back(item);
                }
            }
        }
        return array;
    }

    std::string JSONObject::getPathFromVector(const std::vector<std::string>& Steps) {
        std::string path;
        for (const auto& step : Steps) {
            path += + "/" + step;
        }
        return path;
    }

    void JSONObject::setDocument(nlohmann::json doc) {
        document = std::move(doc);
    }

    nlohmann::json JSONObject::getDocument() {
        return document;
    }

    void JSONObject::salvarNoArquivo(std::string Arquivo) {
        JsonHandler jsonHandler;
        jsonHandler.SalvarEmArquivo(std::move(Arquivo),document);
    }

    std::string JSONObject::pesquisar(std::string property,nlohmann::json value) {
        for (auto row = document.begin(); row != document.end(); ++row) {
            if(row->contains(property) && (*row)[property].type_name() == value.type_name()) {
                if((*row)[property] == value) {
                    return row.key();
                }
            }
        }

        return "";
    }

    void JSONObject::remover(nlohmann::json key) {
        document.erase(document.find(key));
    }

    bool JSONObject::contains(const nlohmann::json& key) {
        return document.contains(key);
    }


}
