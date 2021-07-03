#ifndef SISTEMA_PROVAS_USUARIODAOJSON_HPP
#define SISTEMA_PROVAS_USUARIODAOJSON_HPP
#include <string>
#include "business/DAO/UsuarioDAO.hpp"
#include "business/Modelo/usuario.hpp"
#include "persistence/DAO/JSONFileHandler.hpp"
#include "JSONObject.hpp"

namespace Persistence {
    class UsuarioDAOJSON : public Business::UsuarioDAO {
    public:
        UsuarioDAOJSON();

        static std::string ARQUIVO_USUARIOS;

        bool loginExiste(std::string);
        bool cadastrar(Modelo::Usuario ) override;
        bool login(std::string, std::string);
        ~UsuarioDAOJSON();

    private:
        JSONObject* jsonObject;
    };
}


#endif //SISTEMA_PROVAS_USUARIODAOJSON_HPP
