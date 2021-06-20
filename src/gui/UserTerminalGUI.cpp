#include "gui/UserTerminalGUI.hpp"
#include <string>

namespace GUI
{
    void UserTerminalGUI::show(){
        std::cout << "Showing GUI\n";
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1 - Create Test" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        int option;
        std::cin >> option;
        while (option != 0)
        {

            switch (option)
            {
            case 1:
                CreateTest();
                break;
            }
        }
        std::cout << "Closing GUI\n";
    }

    Test* UserTerminalGUI::CreateTest(){
        std::cout << "Enter a name for this Test:" << std::endl;
        string name;
        std::cin >> name;
        Test *t = new Test(name);
        std::cout << "Add a question to this test?" << std::endl;
        std::cout << "1 - Yes" << std::endl;
        std::cout << "2 - No" << std::endl;
        int addQuestionToTest;
        std::cin >> addQuestionToTest;
        while (addQuestionToTest != 2){
            addQuestion(t);
            std::cout << "Add another question to this test?" << std::endl;
            std::cout << "1 - Yes" << std::endl;
            std::cout << "2 - No" << std::endl;
            std::cin >> addQuestionToTest;
        }
        return t;
    }

    void UserTerminalGUI::addQuestion(Test *t){
        string placeholder;
        std::cout<<"Type the placeholder:"<<std::endl;
        std::cin>>placeholder;
        Question q=Question(placeholder);
        t->InsertQuestion(q);
    }

    UserTerminalGUI::~UserTerminalGUI(){
        std::cout << "Destroying UserTerminalGUI\n";
    }
}