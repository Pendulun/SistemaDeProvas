#include "gui/TelaTurmaProfessor.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{

    void TelaTurmaProfessor::show(){

            std::cout<<"------\n";
            std::cout<<"TURMAS\n";
            std::cout<<"------\n\n";

            std::string opcao;

            std::cout<<"Escolha a opcao:\n";
            std::cout<<"1 - Cadastrar nova turma\n";
            std::cout<<"2 - Ver turmas existentes\n";
            std::cout<<"3 - Voltar\n";

            if(opcao==1){
                cadastrarTurma();
            }
            else if(opcao==2){
                listarTurmas();
            }
            else if(opcao==3){
                
            }
            else{

            }
    }

    void TelaTurmaProfessor::cadastrarTurma(){

        util.limparTerminal();

        std::cout<<"----------------------\n";
        std::cout<<"CADASTRO DE NOVA TURMA\n";
        std::cout<<"----------------------\n\n";

        std::string nomeTurma;

        std::cout<<"Digite o nome da turma:\n";

        std::cin>>nomeTurma;

        //TODO - Manter turma

    }

}