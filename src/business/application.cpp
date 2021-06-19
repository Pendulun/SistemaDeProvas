#include "business/application.hpp"

namespace Business{

    void Application::start(){
        std::cout<<"Starting Application\n";
    }

    Application::Application(GUI::UserGUI& userGUI){
        this->userGUI = &userGUI;
    }

    Application::Application(){}

    Application::~Application(){
        delete this->userGUI;
    }
}