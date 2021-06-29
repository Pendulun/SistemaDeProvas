//
// Created by felip on 28/06/2021.
//

#ifndef SISTEMA_PROVAS_INICIALIZADOR_HPP
#define SISTEMA_PROVAS_INICIALIZADOR_HPP
#include <string>

namespace Persistence {
    extern std::string TEMPLATE_ARQUIVO_JSON;
    extern std::string ARQUIVO_USUARIOS;
    extern std::string ARQUIVO_TURMAS;
    extern std::string FolderPath;
    class ConfiguracaoDAO {
    public:
        static void Configurar();
        std::string GetConnectionString();
    private:
    };
}

#endif //SISTEMA_PROVAS_INICIALIZADOR_HPP
