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

    Modelo::Prova* UserTerminalGUI::CreateProva(){
        std::cout << "Entre um nome para essa Prova:" << std::endl;
        string name;
        std::cin >> name;
        Modelo::Prova *t = new Modelo::Prova(name);
        std::cout << "Adicionar uma questão a essa prova?" << std::endl;
        std::cout << "1 - Sim" << std::endl;
        std::cout << "2 - Não" << std::endl;
        int addQuestaoToProva;
        std::cin >> addQuestaoToProva;
        while (addQuestaoToProva != 2){
            addQuestao(t);
            std::cout << "Adicionar outra questão a essa prova?" << std::endl;
            std::cout << "1 - Sim" << std::endl;
            std::cout << "2 - Não" << std::endl;
            std::cin >> addQuestaoToProva;
        }
        return t;
    }

    void UserTerminalGUI::addQuestao(Modelo::Prova *t){
        Questao q=Questao("a","1","2","3","4",1);
        t->InsertQuestao(q);
    }

    UserTerminalGUI::~UserTerminalGUI(){
        std::cout << "Destroying UserTerminalGUI\n";
    }
}