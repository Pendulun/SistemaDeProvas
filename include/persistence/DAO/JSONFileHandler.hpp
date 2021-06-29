#ifndef SISTEMA_PROVAS_JSONFILEHANDLER_HPP
#define SISTEMA_PROVAS_JSONFILEHANDLER_HPP
#include <string>
#include <vector>
#include "libraries/nlohmann/json.hpp"

namespace Persistence {
    class JsonHandler {
    public:

        static std::string TEMPLATE_ARQUIVO_JSON;
        static std::string FolderPath;

        void VerificarCriacaoPasta();
        void VerificarCriacaoArquivos(std::vector<std::string>);

        nlohmann::json LerArquivo(std::string);
        void SalvarEmArquivo(std::string,nlohmann::json);


    private:
        std::string getCaminhoArquivo(std::string);
        void CriarArquivoJSONTemplate(std::string);
        bool ArquivoExiste(std::string);
        void VerificarCriacaoArquivoJSON(std::string);

    };
}

#endif //SISTEMA_PROVAS_JSONFILEHANDLER_HPP
