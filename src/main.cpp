#include "business/application.hpp"
#include "gui/UserTerminalGUI.hpp"
#include "persistence/Inicializador.hpp"
#include "persistence/DAO/UsuarioDAOJSON.hpp"
#include "persistence/DAO/TurmaDAOJSON.hpp"


void configApplicationDAOS(Business::Application* app){
    app->setUsuarioDAO(new Persistence::UsuarioDAOJSON());
    app->setTurmaDAO(new Persistence::TurmaDAOJSON());
    
}

Business::Application* config(){
    GUI::UserTerminalGUI* userTerminal = new GUI::UserTerminalGUI();
    Business::Application::createNewInstanceIfPossible(userTerminal);
    //Não inverter a order dessas duas linhas de baixo, senão o programa não funciona
    //por algum motivo
    Persistence::ConfiguracaoDAO::Configurar();
    configApplicationDAOS(Business::Application::getInstance());
    return Business::Application::getInstance();
}

int main(int argc, char *argv[]){
    Business::Application* app = config();
    app->start();
    delete app;
    return 0;  
}

