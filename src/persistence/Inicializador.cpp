#include "persistence/Inicializador.hpp"
#include "persistence/DAO/JSONFileHandler.hpp"
#include "persistence/DAO/UsuarioDAOJSON.hpp"


namespace Persistence {
    std::string ARQUIVO_TURMAS =  "turmas.json";


    void ConfiguracaoDAO::Configurar() {
        JsonHandler jsonHandler;
        jsonHandler.VerificarCriacaoPasta();
        std::vector<std::string> arquivos = { UsuarioDAOJSON::ARQUIVO_USUARIOS, ARQUIVO_TURMAS};

        jsonHandler.VerificarCriacaoArquivos(arquivos);
    }
}
