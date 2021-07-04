#ifndef APPLICATION_H
#define APPLICATION_H

#include "business/gui/UserGUI.hpp"
#include "business/DAO/UsuarioDAO.hpp"
#include "business/DAO/ProfessorDAO.hpp"
#include "business/DAO/AlunoDAO.hpp"
#include "business/DAO/TurmaDAO.hpp"
#include <iostream>

namespace Business{
    class Application{
        public:
            void start();
            static Application* getInstance();
            static void createNewInstanceIfPossible(UserGUI*);
            UsuarioDAO* getUsuarioDAO();
            ProfessorDAO* getProfessorDAO();
            AlunoDAO* getAlunoDAO();
            TurmaDAO* getTurmaDAO();
            ~Application();   
        protected:
            Application(UserGUI*);
            static Application* instance;
        private:
        UsuarioDAO* usuarioDAO;
        ProfessorDAO* professorDAO;
        AlunoDAO* alunoDAO;
        UserGUI* userGUI;
        TurmaDAO* turmaDAO;
    };
}

#endif