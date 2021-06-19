#ifndef __USERTERMINALGUI_H__
#define __USERTERMINALGUI_H__
#include <iostream>
#include "business/gui/UserGUI.hpp"

namespace GUI{
    class UserTerminalGUI :public Business::UserGUI{
        public:
            void show() override;
            ~UserTerminalGUI() override;
    };
}
#endif