#include "business/application.hpp"


void config(Business::Application* app){
    //cria um novo app passando uma classe concreta de UserGUI e 
    //classes concretas de DAO's. Para isso, deve ter um construtor equivalente
}


int main(int argc, char *argv[]){
    Business::Application* app;
    config(app);
    app->start();
    delete app;
    return 0;  
}

