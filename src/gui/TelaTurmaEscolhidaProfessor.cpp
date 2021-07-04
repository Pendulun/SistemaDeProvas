#include "gui/TelaTurmaEscolhidaProfessor.hpp"

namespace GUI{

    TelaTurmaEscolhidaProfessor::TelaTurmaEscolhidaProfessor (Modelo::Turma turma){
        this->turma = turma;
    }

    void TelaTurmaEscolhidaProfessor::show(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"---------------------------------------\n";
            std::cout<<"TELA DA TURMA "<<this->turma.getNome()<<std::endl;
            std::cout<<"---------------------------------------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Provas\n";
            std::cout<<"2 - Ver alunos\n";
            std::cout<<"3 - Alterar\n";
            std::cout<<"4 - Excluir\n";
            std::cout<<"5 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    verProvas();
                    break;
                }else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    std::cout<<"Tela de ver alunos\n";
                    break;
                }else if(opcao.compare("3")==0){
                    util.limparTerminal();
                    std::cout<<"Tela de alterar turma\n";
                    break;             
                }else if(opcao.compare("4")==0){
                    util.limparTerminal();
                    std::cout<<"Tela de excluir turma\n";
                    break;
                }else if(opcao.compare("5")==0){
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

    void TelaTurmaEscolhidaProfessor::verProvas(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"------\n";
            std::cout<<"PROVAS\n";
            std::cout<<"------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Postar prova\n";
            std::cout<<"2 - Escolher prova\n";
            std::cout<<"3 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    std::cout<<"TELA POSTAR PROVA...\n";
                    break;
                }else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    listarProvas();
                    break;
                }else if(opcao.compare("3")==0){
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

    void TelaTurmaEscolhidaProfessor::listarProvas(){

        /*Modelo::Prova provaTesteAdicionada("Nome Prova 1");
        Modelo::Prova provaTesteAdicionada2("Nome Prova 2");
        this->turma.adicionarProva(provaTesteAdicionada);
        this->turma.adicionarProva(provaTesteAdicionada2);*/

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"---------------------------------------\n";
            std::cout<<"PROVAS DA TURMA "<<this->turma.getNome()<<std::endl;
            std::cout<<"---------------------------------------\n\n";

            if(this->turma.getProvas().size()==0){
                std::cout<<"Turma sem provas cadastradas.\n\n";
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
                        for (std::list<Modelo::Prova>::iterator it=this->turma.getProvas().begin(); it != this->turma.getProvas().end(); ++it){
                            if(j == opcao){
                                provaEscolhida = *it;
                                break;
                            }
                            j++;
                        }

                        util.limparTerminal();

                        std::cout<<"Vai para TelaProvaEscolhidaProfessor\n";
                        //TelaTurmaEscolhidaProfessor telaTurmaEscolhidaProfessor(turmaEscolhida);
                        //telaTurmaEscolhidaProfessor.show();

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