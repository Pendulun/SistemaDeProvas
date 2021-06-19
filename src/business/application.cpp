#include "business/application.hpp"

namespace Business{

    void Application::start(){
        std::cout<<"Starting Application\n";
        if (this->userGUI == nullptr){
            std::cout<<"Cant show GUI\n";
        }else{
            this->userGUI->show();
        }
        std::cout<<"Closing Application\n";
    }

    Application::Application(Business::UserGUI* userGUI){
        this->userGUI = userGUI;
    }

    Application::Application(){
        this->userGUI= nullptr;
    }

    Application::~Application(){
        std::cout<<"Destroying Application\n";
        delete this->userGUI;
    }
}