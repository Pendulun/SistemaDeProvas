#ifndef __USERGUI_H__
#define __USERGUI_H__

#include "business/Modelo/prova.hpp"
#include "business/Modelo/questao.hpp"

namespace Business{
    class UserGUI{
        public:
            virtual void show() = 0;
            virtual ~UserGUI() = 0;
    };
}
#endif