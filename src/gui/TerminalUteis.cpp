#include "gui/TerminalUteis.hpp"

namespace GUI{

    void TerminalUteis::limparTerminal(){
        #if defined _WIN32
            system("cls");
        #elif defined (__LINUX__) || defined(__gnu_linux__) || defined (__linux__)
            system("clear");
        #elif defined (__APPLE__)
            system("clear");
        #endif
    }

    void TerminalUteis::limparEntrada(){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    void TerminalUteis::limparTerminalEEntrada(){
        limparTerminal();
        limparEntrada();
    }

}

