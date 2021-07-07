#include "gui/TelaTurmaEscolhidaAluno.hpp"

namespace GUI{

    TelaTurmaEscolhidaAluno::TelaTurmaEscolhidaAluno (Modelo::Turma turma){
        this->turma = turma;
    }

    void TelaTurmaEscolhidaAluno::show(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"---------------------------------------\n";
            std::cout<<"TELA DA TURMA "<<this->turma.getNome()<<std::endl;
            std::cout<<"---------------------------------------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Provas realizadas\n";
            std::cout<<"2 - Provas disponiveis para responder\n";
            std::cout<<"3 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    //std::cout<<"Tela de ver provas realizadas\n";
                    verProvasRealizadas();
                    break;
                }else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    //std::cout<<"Tela de ver provas disponiveis para responder\n";
                    verProvasDisponiveis();
                    break;
                }else if(opcao.compare("3")==0){
                    voltar = true;
                    util.limparTerminal();
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }

            }
        }
    }

    void TelaTurmaEscolhidaAluno::verProvasRealizadas(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"-----------------\n";
            std::cout<<"PROVAS REALIZADAS\n";
            std::cout<<"-----------------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Escolher prova\n";
            std::cout<<"2 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    listarProvasRealizadas();
                    break;
                }
                else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    voltar = true;
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }
        }
    }

    void TelaTurmaEscolhidaAluno::listarProvasRealizadas(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"-----------------\n";
            std::cout<<"PROVAS REALIZADAS\n";
            std::cout<<"-----------------\n\n";

            if(this->turma.getProvas().size()==0){ //Esse é o vetor todo... Teria que ser só as realizadas.
                std::cout<<"Aluno sem provas realizadas.\n\n";
                std::cout<<"Digite 1 para voltar.\n";

                std::string opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao.compare("1")==0){
                        util.limparTerminal();
                        voltar = true;
                        break;
                    }
                    else{
                        std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }
            }
            else{

                std::cout<<"Escolha a prova:\n\n";

                int i = 1;
                for(Modelo::Prova prova : this->turma.getProvas()){
                    std::cout<<i<<" - "<<prova.getNome()<<std::endl;
                    i++;
                }
                std::cout<<i<<" - Voltar\n"; 

                int opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao>0 && opcao<=this->turma.getProvas().size()){
                        util.limparTerminal();

                        Modelo::Prova provaEscolhida("Nome");

                        int j = 1;
                        for(Modelo::Prova prova : this->turma.getProvas()){
                            if(j == opcao){
                                provaEscolhida = prova;
                                break;
                            }
                            j++;
                        }

                        util.limparTerminal();

                        std::cout<<"Vai para TelaProvaEscolhidaAluno\n";
                        //TelaProvaEscolhidaProfessor telaProvaEscolhidaProfessor(provaEscolhida);
                        //telaProvaEscolhidaProfessor.show();

                        break;
                    }
                    else if(opcao == i){
                        voltar = true;

                        util.limparTerminal();
                        break;
                    }
                    else{
                        std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }     

            }      

        }

    }

    void TelaTurmaEscolhidaAluno::verProvasDisponiveis(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"------------------\n";
            std::cout<<"PROVAS DISPONIVEIS\n";
            std::cout<<"------------------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Escolher prova\n";
            std::cout<<"2 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    listarProvasDisponiveis();
                    break;
                }
                else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    voltar = true;
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }
        }
    }

    void TelaTurmaEscolhidaAluno::listarProvasDisponiveis(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"------------------\n";
            std::cout<<"PROVAS DISPONIVEIS\n";
            std::cout<<"------------------\n\n";

            if(this->turma.getProvas().size()==0){ //Esse é o vetor todo... Teria que ser só as disponíveis.
                std::cout<<"Aluno sem provas disponiveis para responder.\n\n";
                std::cout<<"Digite 1 para voltar.\n";

                std::string opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao.compare("1")==0){
                        util.limparTerminal();
                        voltar = true;
                        break;
                    }
                    else{
                        std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }
            }
            else{

                std::cout<<"Escolha a prova:\n\n";

                int i = 1;
                for(Modelo::Prova prova : this->turma.getProvas()){
                    std::cout<<i<<" - "<<prova.getNome()<<std::endl;
                    i++;
                }
                std::cout<<i<<" - Voltar\n"; 

                int opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao>0 && opcao<=this->turma.getProvas().size()){
                        util.limparTerminal();

                        Modelo::Prova provaEscolhida("Nome");

                        int j = 1;
                        for(Modelo::Prova prova : this->turma.getProvas()){
                            if(j == opcao){
                                provaEscolhida = prova;
                                break;
                            }
                            j++;
                        }

                        util.limparTerminal();

                        std::cout<<"Vai para TelaProvaEscolhidaAluno\n";
                        //TelaProvaEscolhidaProfessor telaProvaEscolhidaProfessor(provaEscolhida);
                        //telaProvaEscolhidaProfessor.show();

                        break;
                    }
                    else if(opcao == i){
                        voltar = true;

                        util.limparTerminal();
                        break;
                    }
                    else{
                        std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }     

            }      

        }

    }
}