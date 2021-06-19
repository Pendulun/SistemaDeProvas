#ifndef APPLICATION_H
#define APPLICATION_H
#include "business/gui/UserGUI.hpp"
#include <iostream>
namespace Business{
    class Application{
        public:
            void start();
            Application(GUI::UserGUI& userGUI);
            Application();
            ~Application();
        private:
            GUI::UserGUI* userGUI;
    };
}

#endif