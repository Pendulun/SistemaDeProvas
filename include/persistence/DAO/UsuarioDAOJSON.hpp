#ifndef SISTEMA_PROVAS_USUARIODAOJSON_HPP
#define SISTEMA_PROVAS_USUARIODAOJSON_HPP
#include <string>
#include "persistence/DAO/JSONFileHandler.hpp"
#include "JSONObject.hpp"
#include "business/DAO/UsuarioDAO.hpp"
#include "business/Modelo/usuario.hpp"

namespace Persistence {
    class UsuarioDAOJSON : public Business::UsuarioDAO {
    public:
        UsuarioDAOJSON();

        static std::string ARQUIVO_USUARIOS;

        bool loginExiste(std::string);
        int cadastrar(Modelo::Usuario ) override;
        Modelo::Usuario* pesquisar(int ) override;
        bool login(std::string, std::string) override;
        std::list<Modelo::Usuario> pesquisar(const std::list<int>) override;
        bool remover(Modelo::Usuario) override;
        bool atualizar(Modelo::Usuario) override;
        bool cadastrarEmTurma(Modelo::Usuario, int) override;
        ~UsuarioDAOJSON() override;

    private:
        void checkMaxId();
        int getMaxId();
        void setMaxId(int);
        void atualizarRegistro(Modelo::Usuario);
        JSONObject* jsonObject;
    };
}


#endif //SISTEMA_PROVAS_USUARIODAOJSON_HPP
