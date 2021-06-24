#include "business/application.hpp"
#include <string>

namespace Business{

    Application* Application::instance = nullptr;

    void Application::start(){
        std::cout<<"Starting Application\n";
        if (this->userGUI == nullptr){
            std::cout<<"Cant show GUI\n";
        }else{
            this->userGUI->show();
        }
        std::cout<<"Closing Application\n";
    }

    void Application::createNewInstanceIfPossible(UserGUI* userGUI){
        if(Application::instance == nullptr){
            Application::instance = new Application(userGUI);;
        }
    }

    Application* Application::getInstance(){
        return Application::instance;
    }

    Application::Application(Business::UserGUI* userGUI){
        this->userGUI = userGUI;
    }

    Application::~Application(){
        std::cout<<"Destroying Application\n";
        if(this->userGUI){
            delete this->userGUI;
            std::cout<<"Destroyed userGUI\n";
        }  
    }
}