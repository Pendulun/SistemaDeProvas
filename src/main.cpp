#include "business/application.hpp"
#include "gui/UserTerminalGUI.hpp"
#include "persistence/Inicializador.hpp"

Business::Application* config(){
    GUI::UserTerminalGUI* userTerminal = new GUI::UserTerminalGUI();
    Business::Application::createNewInstanceIfPossible(userTerminal);
    //Passa para a instância do Application os DAOS de JSON
    Persistence::ConfiguracaoDAO::Configurar();
    return Business::Application::getInstance();
}


int main(int argc, char *argv[]){
    Business::Application* app = config();
    app->start();
    delete app;
    return 0;  
}

