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
                std::cout<<"Ir para provas\n";
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