#include "business/fachadas/manterProfessor.hpp"

namespace Business{
    Modelo::Professor* ManterProfessor::pesquisarProfessor(int idProfessor){
        Application* app = Application::getInstance();
        // TODO - Pegar do banco
        Modelo::Professor* dummyProfessor = new Modelo::Professor(idProfessor, Modelo::TipoUsuario::PROFESSOR);
        return dummyProfessor;
    }

}