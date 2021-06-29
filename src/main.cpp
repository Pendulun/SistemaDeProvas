#include "business/application.hpp"
#include "gui/UserTerminalGUI.hpp"
#include "persistence/Inicializador.hpp"

Business::Application* config(){
    GUI::UserTerminalGUI* userTerminal = new GUI::UserTerminalGUI();
    Business::Application::createNewInstanceIfPossible(userTerminal);
    Persistence::ConfiguracaoDAO::Configurar();
    return Business::Application::getInstance();
}


int main(int argc, char *argv[]){
    Business::Application* app = config();
    app->start();
    delete app;
    return 0;  
}

