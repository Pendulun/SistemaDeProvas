#ifndef SISTEMA_PROVAS_JSONOBJECT_HPP
#define SISTEMA_PROVAS_JSONOBJECT_HPP

#include <string>
#include "libraries/nlohmann/json.hpp"

namespace Persistence {
    class JSONObject {
    public:
        JSONObject(std::string);

        JSONObject();
        JSONObject(nlohmann::json);
        void setDocument(nlohmann::json);
        nlohmann::json getDocument();
        std::string getStringPropertyByPath(std::vector<std::string>);
        nlohmann::json getObjectPropertyByPath(std::vector<std::string>);

        void setStringPropertyByPath(std::vector<std::string> , std::string);
        void setIntPropertyByPath(std::vector<std::string> , int);
        void setBoolPropertyByPath(std::vector<std::string> , bool);

        void salvarNoArquivo(std::string);

    private:
        nlohmann::json document;
        std::string getPathFromVector(std::vector<std::string>);
    };
}

#endif //SISTEMA_PROVAS_JSONOBJECT_HPP
