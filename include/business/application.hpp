#ifndef APPLICATION_H
#define APPLICATION_H

#include "business/gui/UserGUI.hpp"
#include "business/DAO/UsuarioDAO.hpp"
#include <iostream>

namespace Business{
    class Application{
        public:
            void start();
            static Application* getInstance();
            static void createNewInstanceIfPossible(UserGUI*);
            UsuarioDAO* getUsuarioDAO();
            ~Application();   
        protected:
            Application(UserGUI*);
            static Application* instance;
        private:
        UsuarioDAO* usuarioDAO;
        UserGUI* userGUI;
    };
}

#endif