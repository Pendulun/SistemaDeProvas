#ifndef __USERGUI_H__
#define __USERGUI_H__
namespace Business{
    class UserGUI{
        public:
            virtual void show() = 0;
            virtual ~UserGUI() = 0;
    };
}
#endif