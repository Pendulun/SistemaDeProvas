#include "gui/UserTerminalGUI.hpp"

namespace GUI{
    void UserTerminalGUI::show(){
        std::cout<< "Showing GUI\n";
        std::cout<< "Closing GUI\n";
    }

    UserTerminalGUI::~UserTerminalGUI(){
        std::cout<<"Destroying UserTerminalGUI\n";
    }
}