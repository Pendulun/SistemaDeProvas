#include "gui/UserTerminalGUI.hpp"
#include <string>

namespace GUI
{
    void UserTerminalGUI::show(){

        while(true){
            TelaLogin* telaLogin = new TelaLogin();
            telaLogin->show();

            SistemaUsuario* sistemaUsuario = nullptr;
            Modelo::Usuario* user = telaLogin->getUser();
            
            if(user!=nullptr){
                try{
                    sistemaUsuario = configSistema(user);
                    sistemaUsuario->show();
                    delete telaLogin;
                    delete sistemaUsuario;
                    std::cout<<"Saiu delete\n";
                }catch(const Business::ProfessorNotFoundException& e){
                    std::cout<<e.what()<<std::endl;
                }catch(const Business::AlunoNotFoundException& e){
                    std::cout<<e.what()<<std::endl;
                }
            }else{
                delete telaLogin;
                break;
            }
        }
        
        std::cout << "Closing GUI\n";
    }

    GUI::SistemaUsuario* UserTerminalGUI::configSistema(Modelo::Usuario* user){
        if(user->isProfessor()){
            return new SistemaProfessor((Modelo::Professor*) user);
        }else if(user->isAluno()){
            return new SistemaAluno((Modelo::Aluno*) user);
        }else{
            return nullptr;
        }
    }

    UserTerminalGUI::~UserTerminalGUI(){
        std::cout << "Destroying UserTerminalGUI\n";
    }
}