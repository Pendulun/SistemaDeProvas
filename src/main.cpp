#include "business/application.hpp"
#include "gui/UserTerminalGUI.hpp"
#include "persistence/Inicializador.hpp"
#include "persistence/DAO/UsuarioDAOJSON.hpp"

Business::Application* config(){
    GUI::UserTerminalGUI* userTerminal = new GUI::UserTerminalGUI();
    Business::Application::createNewInstanceIfPossible(userTerminal);
    //Passa para a instância do Application os DAOS de JSON
    Persistence::ConfiguracaoDAO::Configurar();
    return Business::Application::getInstance();
}

void configApplicationDAOS(Business::Application* app){
    //app->setUsuarioDAO(new Persistence::UsuarioDAOJSON());
    
}


int main(int argc, char *argv[]){
    Business::Application* app = config();
    app->start();
    delete app;
    return 0;  
}

