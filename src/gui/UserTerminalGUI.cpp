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
                    delete telaLogin;
                    sistemaUsuario->show();
                    delete sistemaUsuario;
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
            Business::ManterProfessor manterProfessor;
            Modelo::Professor* professor = manterProfessor.pesquisarProfessor(user->getId());
            return new SistemaProfessor(professor);
        }else if(user->isAluno()){
            Business::ManterAluno manterAluno;
            Modelo::Aluno* aluno = manterAluno.pesquisarAluno(user->getId());
            return new SistemaAluno(aluno);
        }else{
            return nullptr;
        }
    }

    UserTerminalGUI::~UserTerminalGUI(){
        std::cout << "Destroying UserTerminalGUI\n";
    }
}