#include "gui/TelaLogin.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    void TelaLogin::show(){

        TerminalUteis util;

        bool sair = false;
        bool loginSucesso = false;

        while(!sair && !loginSucesso){
            util.limparTerminal();
            std::cout<<"---------------------------------\n";
            std::cout<<"BEM VINDO AO SISTEMA DE PROVAS!!!\n";
            std::cout<<"---------------------------------\n\n";
            std::cout<<"Escolha o numero da opcao desejada:\n";
            std::cout<<"1 - Fazer Login\n";
            std::cout<<"2 - Cadastrar\n";
            std::cout<<"3 - Sair\n";

            std::string opcao;

            while(true){
                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    fazLogin();
                    loginSucesso = true;
                    break;
                }
                else if (opcao.compare("2")==0){
                    util.limparTerminal();
                    cadastrar();
                    break;
                }
                else if(opcao.compare("3")==0){
                    sair = true;
                    util.limparTerminal();
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
                }
            }
        } 
    }

    void TelaLogin::fazLogin(){

        TerminalUteis util;

        bool voltar = false;
        bool dadosCorretos = false;

        while(!voltar && !dadosCorretos){
            std::cout<<"-------------------\n";
            std::cout<<"LOGIN DE USUARIO\n";
            std::cout<<"-------------------\n\n"; 
            while(!dadosCorretos){
                std::string login;
                std::string senha;

                std::cout<<"Digite seu login: \n";
                std::cin>>login;
                util.limparEntrada();

                std::cout<<"Digite sua senha: \n";
                std::cin>>senha;
                util.limparEntrada();

                //TODO - Tentar encontrar o usuário na base de dados
                try{
                    Business::ManterUsuario manterUsuario;
                    this->user = manterUsuario.login(login, senha);
                    dadosCorretos=true;
                } catch (const Business::UserNotFoundException& e){
                    std::cout<<e.what()<<std::endl;
                    dadosCorretos = false;
                } 

                if(dadosCorretos){
                    util.limparTerminal();
                    std::cout<<"ENTROU NO SISTEMA!!! \n";
                }
                else{
                    util.limparTerminal();
                    std::cout<<"Login invalido. Escolha a opcao:\n";
                    std::cout<<"1 - Tentar login novamente\n";
                    std::cout<<"2 - Voltar \n";

                    std::string opcao;

                    while(true){
                        std::cin>>opcao;

                        if(opcao.compare("1")==0){
                            util.limparTerminal();
                            break;
                        }
                        else if (opcao.compare("2")==0){
                            voltar = true;
                            dadosCorretos = true;
                            break;
                        }
                        else{
                            std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
                        }
                    }
                }
            }
        }
    }

    void TelaLogin::cadastrar(){ 

        TerminalUteis util;

        std::string nome;
        std::string login;
        std::string senha;
        std::string opcaoTipoUsuario;
        Modelo::TipoUsuario tipoUsuario;

        bool dadosCorretos = false;

        while(!dadosCorretos){
            std::cout<<"-------------------\n";
            std::cout<<"CADASTRO DE USUARIO\n";
            std::cout<<"-------------------\n\n";

            std::cout<<"Escolha a opcao: \n";
            std::cout<<"1 - Sou aluno \n";
            std::cout<<"2 - Sou professor \n";        

            while(true){
                std::cin>>opcaoTipoUsuario;

                if(opcaoTipoUsuario.compare("1")==0){
                    tipoUsuario = Modelo::TipoUsuario::ALUNO;
                    break;
                }
                else if (opcaoTipoUsuario.compare("2")==0){
                    tipoUsuario = Modelo::TipoUsuario::PROFESSOR;
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
                }
            }   

            std::cout<<"Digite seu nome completo: \n";
            std::cin.ignore();
            std::getline(std::cin, nome);

            std::cout<<"Digite seu login (SEM ESPACOS): \n";
            std::cin>>login;
            util.limparEntrada();

            std::cout<<"Digite sua senha (SEM ESPACOS): \n";
            std::cin>>senha;
            util.limparEntrada();

            util.limparTerminal();

            std::cout<<"SUAS INFORMACOES SAO:\n\n";
            if(opcaoTipoUsuario.compare("1")==0){
                std::cout<<"Tipo de usuario: ALUNO\n";
            }
            else{
                std::cout<<"Tipo de usuario: PROFESSOR\n";
            }
            std::cout<<"Nome: "<<nome<<"\n";
            std::cout<<"Login: "<<login<<"\n";
            std::cout<<"Senha: "<<senha<<"\n\n";

            std::cout<<"Os dados estao corretos?\n";
            std::cout<<"1 - Sim\n";
            std::cout<<"2 - Nao\n";

            std::string opcao;
            
            while(true){
                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    std::cout<<"DADOS CORRETOS!!!\n";
                    dadosCorretos = true;
                    //TODO - CADASTRO NO BANCO
                    Business::ManterUsuario manterUsuario;
                    if(manterUsuario.cadastrarUsuario(nome, login, senha, tipoUsuario)){
                        std::cout<<"Cadastro realizado com sucesso!\n";
                    }
                    else{
                        std::cout<<"Nao foi possivel concluir o cadastro.\n";
                    }
                    break;
                }
                else if (opcao.compare("2")==0){
                    util.limparTerminal();
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
                }
            }
        }
    }

    Modelo::Usuario* TelaLogin::getUser(){
        return this->user;
    }

    TelaLogin::~TelaLogin(){
        delete user;
    }
}