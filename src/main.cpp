#include "business/application.hpp"
#include "gui/UserTerminalGUI.hpp"

Business::Application* config(){
    GUI::UserTerminalGUI* userTerminal = new GUI::UserTerminalGUI();
    return new Business::Application(userTerminal);
}


int main(int argc, char *argv[]){
    Business::Application* app = nullptr;
    app = config();
    app->start();
    delete app;
    return 0;  
}

