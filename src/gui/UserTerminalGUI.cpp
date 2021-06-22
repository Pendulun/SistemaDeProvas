#include "gui/UserTerminalGUI.hpp"
#include <string>

namespace GUI
{
    void UserTerminalGUI::show(){
        TelaLogin telaLogin;
        telaLogin.show();

        

        /*std::cout << "Showing GUI\n";
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1 - Create Prova" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        int option;
        std::cin >> option;
        while (option != 0)
        {

            switch (option)
            {
            case 1:
                CreateProva();
                break;
            }
        }*/
        std::cout << "Closing GUI\n";
    }

    Prova* UserTerminalGUI::CreateProva(){
        std::cout << "Entre um nome para essa Prova:" << std::endl;
        string name;
        std::cin >> name;
        Prova *t = new Prova(name);
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

    void UserTerminalGUI::addQuestao(Prova *t){
        Questao q=Questao("a","1","2","3","4",1);
        t->InsertQuestao(q);
    }

    UserTerminalGUI::~UserTerminalGUI(){
        std::cout << "Destroying UserTerminalGUI\n";
    }
}