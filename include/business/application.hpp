#ifndef APPLICATION_H
#define APPLICATION_H

#include "business/gui/UserGUI.hpp"
#include <iostream>

namespace Business{
    class Application{
        public:
            void start();
            static Application* getInstance();
            static void createNewInstanceIfPossible(UserGUI*);
            ~Application();   
        protected:
            Application(UserGUI*);
            static Application* instance;
        private:
            UserGUI* userGUI;
    };
}

#endif