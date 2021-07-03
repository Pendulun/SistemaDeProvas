#include "gui/TelaTurmaProfessor.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{

    void TelaTurmaProfessor::show(){

            //TerminalUteis util;

            std::cout<<"------\n";
            std::cout<<"TURMAS\n";
            std::cout<<"------\n\n";

            std::string opcao;

            std::cout<<"Escolha a opcao:\n";
            std::cout<<"1 - Cadastrar nova turma\n";
            std::cout<<"2 - Ver turmas existentes\n";
            std::cout<<"3 - Voltar\n";

            while(true){

                std::cin>>opcao;

                if(opcao==1){
                    cadastrarTurma();
                    break;
                }
                else if(opcao==2){
                    listarTurmas();
                    break;
                }
                else if(opcao==3){
                    break;
                }
                else{
                    std::cout<<"Opcao invalida. Digite novamente.\n";
                }
            }
    }

    void TelaTurmaProfessor::cadastrarTurma(){

        TerminalUteis util;

        util.limparTerminal();

        std::cout<<"----------------------\n";
        std::cout<<"CADASTRO DE NOVA TURMA\n";
        std::cout<<"----------------------\n\n";

        std::string nomeTurma;

        std::cout<<"Digite o nome da turma:\n";

        std::cin>>nomeTurma;

        //TODO - Manter turma

        if(true){
            util.limparTerminal();

            std::cout<<"Turma cadastrada com sucesso!\n";
        }
        else{
            util.limparTerminal();

            std::cout<<"Erro ao cadastrar turma.\n";
        }
    }

    void TelaTurmaProfessor::listarTurmas(){

        TerminalUteis util;

        util.limparTerminal();

        std::string opcao;

        std::cout<<"-----------------\n";
        std::cout<<"TURMAS EXISTENTES\n";
        std::cout<<"-----------------\n\n";

        std::cout<<"Escolha a opcao para acessar a turma desejada:\n";
        //TODO - Receber turmas do banco de dados

        int numTurmas = 5;

        for(int i=1; i<=numTurmas; i++){
            std::cout<<i<<" - "<<"Turma "<<i<<std::endl;
        }

        while(true){
            std::cin>>opcao;

            if(opcao>1 && opcao<numTurmas){
                //TODO - Acessar a turma escolhida
                break;
            }
            else{
                std::cout<<"Opcao invalida. Digite novamente.\n";
            }
        }
    }

}