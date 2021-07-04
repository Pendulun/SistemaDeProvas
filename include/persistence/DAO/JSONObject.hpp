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
        std::string getStringPropertyByPath(const std::vector<std::string>&);
        double getNumberPropertyByPath(const std::vector<std::string>& Path);
        bool getBoolPropertyByPath(const std::vector<std::string>&);
        nlohmann::json getObjectPropertyByPath(const std::vector<std::string>&);

        void setStringPropertyByPath(const std::vector<std::string>& , const std::string&);
        void setIntPropertyByPath(const std::vector<std::string>& , int);
        void setBoolPropertyByPath(const std::vector<std::string>& , bool);

        void salvarNoArquivo(std::string);

    private:
        nlohmann::json document;
        static std::string getPathFromVector(const std::vector<std::string>&);
    };
}

#endif //SISTEMA_PROVAS_JSONOBJECT_HPP
