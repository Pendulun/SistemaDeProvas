#ifndef APPLICATION_H
#define APPLICATION_H

#include "business/gui/UserGUI.hpp"
#include "business/DAO/UsuarioDAO.hpp"
#include "business/DAO/TurmaDAO.hpp"
#include <iostream>

namespace Business{
    class Application{
        public:
            void start();
            static Application* getInstance();
            static void createNewInstanceIfPossible(UserGUI*);
            UsuarioDAO* getUsuarioDAO();
            TurmaDAO* getTurmaDAO();
            void setUsuarioDAO(UsuarioDAO*);
            void setTurmaDAO(TurmaDAO*);
            ~Application();   
        protected:
            Application(UserGUI*);
            static Application* instance;
        private:
        UsuarioDAO* usuarioDAO;
        UserGUI* userGUI;
        TurmaDAO* turmaDAO;
    };
}

#endif