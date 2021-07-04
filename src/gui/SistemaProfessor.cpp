#include "gui/SistemaProfessor.hpp"

namespace GUI{

    SistemaProfessor::SistemaProfessor(Modelo::Professor* professor){
        this->professor = professor;
    }


    void SistemaProfessor::show(){
        bool sair = false;
        while(!sair){
            OpcaoMenuInicial opcaoEscolhida;
            this->mostrarSaudacoes();
            opcaoEscolhida = this->mostrarOpcoesMenu();
            if(opcaoEscolhida == SistemaProfessor::OpcaoMenuInicial::SAIR){
                sair=true;
            }else if(opcaoEscolhida == SistemaProfessor::OpcaoMenuInicial::OPERRADA){
                //roda o while de novo
            }else{
                mapeiaEntrada(opcaoEscolhida);
            }
        }
    }

    void SistemaProfessor::mostrarSaudacoes(){
        std::cout<<"------------------------------------------\n";
        std::cout<<"BEM-VINDO "<<this->professor->getNome()<<"\n";
        std::cout<<"------------------------------------------\n";
    }

    SistemaProfessor::OpcaoMenuInicial SistemaProfessor::mostrarOpcoesMenu(){
        std::string opcaoEscolhida = "";
        std::cout<<"Escolha o numero da opcao desejada:\n";
        std::cout<<OpcaoMenuInicial::TURMAS<<" - Turmas\n";
        std::cout<<OpcaoMenuInicial::PROVAS<<" - Provas Base\n";
        std::cout<<OpcaoMenuInicial::PERFIL<<" - Perfil\n";
        std::cout<<OpcaoMenuInicial::SAIR<<" - Sair\n";
        std::cin>>opcaoEscolhida;
        GUI::TerminalUteis terminalUtil;
        terminalUtil.limparEntrada();
        terminalUtil.limparTerminal();
        if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicial::TURMAS))==0){
            return OpcaoMenuInicial::TURMAS;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicial::PROVAS))==0){
            return OpcaoMenuInicial::PROVAS;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicial::PERFIL))==0){
            return OpcaoMenuInicial::PERFIL;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicial::SAIR))==0){
            return OpcaoMenuInicial::SAIR;
        }else{
            return OpcaoMenuInicial::OPERRADA;
        }
    }
    
    void SistemaProfessor::mapeiaEntrada(SistemaProfessor::OpcaoMenuInicial opcaoEscolhida){
        TerminalUteis util;

        switch (opcaoEscolhida)
            {
            case OpcaoMenuInicial::TURMAS:
            {
                TelaTurmasProfessor telaTurmasProfessor(this->professor);
                telaTurmasProfessor.show();
                break;
            }
            case OpcaoMenuInicial::PROVAS:
            {   
                util.limparTerminal();

                std::cout<<"------\n";
                std::cout<<"CADASTRO DE PROVAS\n";
                std::cout<<"------\n\n";

                std::cout<<"Escolha a opcao: \n";
                std::cout<<"1 - Cadastrar nova prova\n";
                std::cout<<"2 - Voltar\n";

                std::string opcao;

                while(true){
                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao.compare("1")==0){
                        cadastrarProva();
                        break;
                    }
                    else if (opcao.compare("2")==0){
                        util.limparTerminal();
                        break;
                    }
                    else{
                         std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }                                                
                break;
            }
            case OpcaoMenuInicial::PERFIL:
            {   
                bool voltar = false;

                while(!voltar){
                    util.limparTerminal();
                    std::cout<<"------\n";
                    std::cout<<"PERFIL\n";
                    std::cout<<"------\n\n";

                    std::cout<<"Nome: "<<this->professor->getNome()<<std::endl;
                    std::cout<<"Login: "<<this->professor->getLogin()<<std::endl;
                    std::cout<<"Senha: "<<this->professor->getSenha()<<std::endl;

                    std::cout<<"\nDigite a opcao desejada:\n";
                    std::cout<<"1 - Alterar dados do perfil\n";
                    std::cout<<"2 - Voltar\n\n";

                    std::string opcao;

                    while(true){
                        std::cin>>opcao;
                        util.limparEntrada();

                        if(opcao.compare("1")==0){
                            voltar = alterarPerfil();
                            break;
                        }
                        else if (opcao.compare("2")==0){
                            util.limparTerminal();
                            voltar = true;
                            break;
                        }
                        else{
                            std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                        }
                    }                
                }
                break;
            }
            default:
                break;
            }
    }

void SistemaProfessor::cadastrarProva(){
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

bool SistemaProfessor::alterarPerfil(){
        TerminalUteis util;
        util.limparTerminal();

        std::cout<<"-------------------\n";
        std::cout<<"ALTERACAO DE PERFIL\n";
        std::cout<<"-------------------\n\n";

        std::cout<<"Nome: "<<this->professor->getNome()<<std::endl;
        std::cout<<"Login: "<<this->professor->getLogin()<<std::endl;
        std::cout<<"Senha: "<<this->professor->getSenha()<<std::endl;

        std::cout<<"\nDigite a opcao desejada:\n";
        std::cout<<"1 - Alterar nome\n";
        std::cout<<"2 - Alterar login\n";
        std::cout<<"3 - Alterar senha\n";
        std::cout<<"4 - Voltar\n\n";

        std::string opcao;
        std::string alteracao;

        while(true){

            std::cin>>opcao;

            if(opcao.compare("1")==0){
                util.limparTerminal();
                std::cout<<"Nome atual: "<<this->professor->getNome()<<std::endl;

                std::cout<<"\nDigite o novo nome desejado: \n";
                std::cin.ignore();
                std::getline(std::cin, alteracao);

                this->professor->setNome(alteracao);
                util.limparTerminal();

                return false;
            }
            else if (opcao.compare("2")==0){
                util.limparTerminal();
                std::cout<<"Login atual: "<<this->professor->getLogin()<<std::endl;
                
                std::cout<<"\nDigite o novo login desejado (SEM ESPACOS): \n";
                std::cin>>alteracao;

                this->professor->setLogin(alteracao);
                util.limparTerminal();

                return false;
            }
            else if (opcao.compare("3")==0){
                util.limparTerminal();
                std::cout<<"Senha atual: "<<this->professor->getSenha()<<std::endl;
                
                std::cout<<"\nDigite a nova senha desejada (SEM ESPACOS): \n";
                std::cin>>alteracao;

                this->professor->setSenha(alteracao);
                util.limparTerminal();

                return false;
            }
            else if (opcao.compare("4")==0){
                util.limparTerminal();
                return false;
            }
            else{
                std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
            }
        }          
        
    }

    SistemaProfessor::~SistemaProfessor(){
        std::cout<<"Destruindo Sistema Professor"<<std::endl;
        delete this->professor;
    }
}