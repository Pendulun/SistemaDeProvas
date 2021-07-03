#ifndef APPLICATION_H
#define APPLICATION_H

#include "business/gui/UserGUI.hpp"
#include "business/DAO/UsuarioDAO.hpp"
#include "business/DAO/ProfessorDAO.hpp"
#include <iostream>

namespace Business{
    class Application{
        public:
            void start();
            static Application* getInstance();
            static void createNewInstanceIfPossible(UserGUI*);
            UsuarioDAO* getUsuarioDAO();
            ProfessorDAO* getProfessorDAO();
            ~Application();   
        protected:
            Application(UserGUI*);
            static Application* instance;
        private:
        UsuarioDAO* usuarioDAO;
        ProfessorDAO* professorDAO;
        UserGUI* userGUI;
    };
}

#endif