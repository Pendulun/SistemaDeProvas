#ifndef APPLICATION_H
#define APPLICATION_H

#include "business/gui/UserGUI.hpp"
#include <iostream>

namespace Business{
    class Application{
        public:
            void start();
            Application(UserGUI* userGUI);
            Application();
            ~Application();
        private:
            UserGUI* userGUI;
    };
}

#endif