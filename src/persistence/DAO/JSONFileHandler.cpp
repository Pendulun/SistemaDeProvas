//
// Created by felip on 29/06/2021.
//

#include "persistence/DAO/JSONFileHandler.hpp"
#include <utility>
#include <fstream>
#include <filesystem>
#include <fstream>

namespace Persistence {
    std::string JsonHandler::TEMPLATE_ARQUIVO_JSON =  "{}";
    std::string JsonHandler::FolderPath = "JSON";

    void JsonHandler::CriarArquivoJSONTemplate(std::string NomeArquivo) {
        std::ofstream Arquivo(NomeArquivo);
        Arquivo << TEMPLATE_ARQUIVO_JSON;
        Arquivo.close();
    }

    bool JsonHandler::ArquivoExiste(std::string NomeArquivo) {
        std::ifstream f(NomeArquivo.c_str());
        return f.good();
    }

    void JsonHandler::VerificarCriacaoArquivoJSON(std::string Path) {
        if (!ArquivoExiste(Path)){
            CriarArquivoJSONTemplate(Path);
        }
    }

    void JsonHandler::VerificarCriacaoPasta() {
        if(!std::filesystem::is_directory(FolderPath)) {
            std::filesystem::create_directory(FolderPath);
        }
    }

    void JsonHandler::VerificarCriacaoArquivos(std::vector<std::string> arquivos) {
        for (std::string arquivo : arquivos) {
            VerificarCriacaoArquivoJSON(getCaminhoArquivo(arquivo));
        }
    }

    nlohmann::json JsonHandler::LerArquivo(std::string arquivo) {
        std::ifstream ifs(getCaminhoArquivo(arquivo).c_str());
        nlohmann::json doc;
        ifs >> doc;
        return doc;
    }

    void JsonHandler::SalvarEmArquivo(std::string arquivo,nlohmann::json doc) {
        std::ofstream ofs(getCaminhoArquivo(arquivo).c_str());
        doc >> ofs;
    }

    std::string JsonHandler::getCaminhoArquivo(std::string arquivo) {
        return FolderPath + "\\" + arquivo;
    }
}
