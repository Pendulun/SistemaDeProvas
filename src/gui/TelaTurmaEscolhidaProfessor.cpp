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

    void TelaTurmaEscolhidaProfessor::cadastrarProva(){
        TerminalUteis util;
        util.limparTerminal();

        int inicio;
        int fim;
        std::string nome;

        bool adicionando = true;

        //Se der tempo, dar opcao de reutilizar prova
        std::cout<<"Digite o dia de inicio (um numero inteiro): \n";
        std::cin>>inicio;
        std::cout<<"Digite o dia de termino (um numero inteiro): \n";
        std::cin>>fim;
        std::cout<<"Digite o titulo da prova: \n";
        std::cin.ignore();
        std::getline(std::cin, nome);

        Modelo::Prova prova(inicio, fim, nome);

        util.limparTerminal();

        std::string enunciado;
        std::string alternativa;
        std::string alternativas[4];
        int alternativaCerta;

        while(adicionando){
            util.limparTerminal();

            std::cout<<"Digite o enunciado da questao: \n";
            std::getline(std::cin, enunciado);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 1: \n";
            std::getline(std::cin, alternativa);
            alternativas[0] = alternativa;
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 2: \n";
            std::getline(std::cin, alternativas[1]);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 3: \n";
            std::getline(std::cin, alternativas[2]);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 4: \n";
            std::getline(std::cin, alternativas[3]);
            std::cout<<"\n";

            std::cout<<"Digite o numero da alternativa correta (1, 2, 3 ou 4): \n";
            std::cin>>alternativaCerta;

            Questao questao(enunciado, alternativas[0], alternativas[1], alternativas[2], alternativas[3], alternativaCerta);
            prova.InsertQuestao(questao);

            util.limparTerminal();
            std::cout<<"Questao adicionada com sucesso. Adicionar outra questao?\n";
            std::cout<<"1 - Sim\n";
            std::cout<<"2 - Nao\n";

            std::string opcao;

            while(true){
                std::cin>>opcao;
                util.limparEntrada();

                if(opcao.compare("1")==0){
                    break;
                }
                else if (opcao.compare("2")==0){
                    util.limparTerminal();
                    std::cout<<"Prova criada com sucesso!!\n\n";
                    //TODO - Persistir prova
                    adicionando = false;            
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }
        }
            
        prova.mostrarProva();

        std::string opcao;

        while(true){
            std::cout<<"Digite 1 para voltar ao menu principal.\n";

            std::cin>>opcao;
            util.limparEntrada();

            if(opcao.compare("1")==0){
                util.limparTerminal();
                break;
            }
            else{
                std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
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
                    cadastrarProva();
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