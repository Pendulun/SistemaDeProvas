#ifndef __USERTERMINALGUI_H__
#define __USERTERMINALGUI_H__
#include <iostream>
#include "business/gui/UserGUI.hpp"
#include "gui/TelaLogin.hpp"

namespace GUI{
    class UserTerminalGUI :public Business::UserGUI{
        public:
            void show() override;
            ~UserTerminalGUI() override;
        private:
            Prova *CreateProva();
            void addQuestao(Prova *t);
    };
}
#endif