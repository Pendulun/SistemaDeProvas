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

        bool contains(const nlohmann::json&);
        bool containsPath(const std::vector<std::string> &Path);

        std::string getStringPropertyByPath(const std::vector<std::string>&);
        double getNumberPropertyByPath(const std::vector<std::string>& Path);
        bool getBoolPropertyByPath(const std::vector<std::string>&);
        nlohmann::json getObjectPropertyByPath(const std::vector<std::string>&);
        std::vector<int> getIntArrayPropertyByPath(const std::vector<std::string>&);
        std::vector<std::string> getStringArrayPropertyByPath(const std::vector<std::string>&);
        std::vector<std::string> getObjectKeys(const std::vector<std::string>&);

        std::string pesquisar(std::string,nlohmann::json);

        void remover(nlohmann::json);

        void setStringPropertyByPath(const std::vector<std::string>& , const std::string&);
        void setIntPropertyByPath(const std::vector<std::string>& , int);
        void setBoolPropertyByPath(const std::vector<std::string>& , bool);
        void setIntArrayPropertyByPath(const std::vector<std::string> &Path, const std::vector<int> &values);
        void setStringArrayPropertyByPath(const std::vector<std::string> &Path, const std::vector<std::string> &values);
        void setEmptyObjectPropertyByPath(const std::vector<std::string> &Path);

        void salvarNoArquivo(std::string);

    private:
        nlohmann::json document;
        static std::string getPathFromVector(const std::vector<std::string>&);

    };
}

#endif //SISTEMA_PROVAS_JSONOBJECT_HPP
