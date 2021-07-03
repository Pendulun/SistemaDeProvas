#include "gui/TelaLogin.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    void TelaLogin::show(){

        TerminalUteis util;

        bool sair = false;
        bool loginSucesso = false;

        bool cadastrou = false; 

        while(!sair && !loginSucesso){
            
            if(!cadastrou){
                util.limparTerminal();
            }
            
            std::cout<<"---------------------------------\n";
            std::cout<<"BEM VINDO AO SISTEMA DE PROVAS!!!\n";
            std::cout<<"---------------------------------\n\n";
            std::cout<<"Escolha o numero da opcao desejada:\n";
            std::cout<<"1 - Fazer Login\n";
            std::cout<<"2 - Cadastrar\n";
            std::cout<<"3 - Sair\n\n";

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
                    cadastrou = cadastrar();
                    break;
                }
                else if(opcao.compare("3")==0){
                    sair = true;
                    util.limparTerminal();
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
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

    bool TelaLogin::cadastrar(){ 

        TerminalUteis util;

        bool voltar = false;

        std::string nome;
        std::string login;
        std::string senha;
        std::string opcaoTipoUsuario;
        Modelo::TipoUsuario tipoUsuario;

        bool dadosCorretos = false;
        bool cadastrou = false;

        while(!dadosCorretos && !voltar){
            std::cout<<"-------------------\n";
            std::cout<<"CADASTRO DE USUARIO\n";
            std::cout<<"-------------------\n\n";

            std::cout<<"Escolha a opcao: \n";
            std::cout<<"1 - Sou aluno \n";
            std::cout<<"2 - Sou professor \n"; 
            std::cout<<"3 - Voltar \n\n";       

            while(!cadastrou){

                std::cin>>opcaoTipoUsuario;

                if(opcaoTipoUsuario.compare("1")==0){
                    tipoUsuario = Modelo::TipoUsuario::ALUNO;

                    pedirDados(nome, login, senha);
                    util.limparTerminal();

                    bool checagem = checarDados(tipoUsuario, nome, login, senha);

                    if (checagem){
                        cadastrou = true;
                        dadosCorretos = true;
                    }
                    else{
                        break;
                    }
                }
                else if (opcaoTipoUsuario.compare("2")==0){
                    tipoUsuario = Modelo::TipoUsuario::PROFESSOR;

                    pedirDados(nome, login, senha);
                    util.limparTerminal();

                    bool checagem = checarDados(tipoUsuario, nome, login, senha);

                    if (checagem){
                        cadastrou = true;
                        dadosCorretos = true;
                    }
                    else{
                        break;
                    }
                }
                else if (opcaoTipoUsuario.compare("3")==0){
                    voltar = true;
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }
        }

        return cadastrou;
    }

    void TelaLogin::pedirDados(std::string& nome, std::string& login, std::string& senha){

        TerminalUteis util;

        util.limparTerminal();

        std::cout<<"\nDigite seu nome completo: \n";
        std::cin.ignore();
        std::getline(std::cin, nome);

        std::cout<<"\nDigite seu login (SEM ESPACOS): \n";
        std::cin>>login;
        util.limparEntrada();

        std::cout<<"\nDigite sua senha (SEM ESPACOS): \n";
        std::cin>>senha;
        util.limparEntrada();
    }

    bool TelaLogin::checarDados(Modelo::TipoUsuario& opcaoTipoUsuario, std::string& nome, std::string& login, std::string& senha){
        
        TerminalUteis util;

        std::cout<<"SUAS INFORMACOES SAO:\n\n";

        if(opcaoTipoUsuario==Modelo::TipoUsuario::ALUNO){
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
        std::cout<<"2 - Nao\n\n";

        std::string opcao;
                    
        while(true){
            std::cin>>opcao;

            if(opcao.compare("1")==0){
                //cadastrou = true;
                //TODO - CADASTRO NO BANCO
                Business::ManterUsuario manterUsuario;

                if(manterUsuario.cadastrarUsuario(nome, login, senha, opcaoTipoUsuario)){
                    util.limparTerminal();
                    std::cout<<"Cadastro realizado com sucesso!\n\n";

                    return true;
                }
                else{
                    util.limparTerminal();
                    std::cout<<"Nao foi possivel concluir o cadastro.\n";

                    return false;
                }
                break;
            }
            else if (opcao.compare("2")==0){
                util.limparTerminal();
                std::cout<<"Para tentar cadastrar novamente, selecione a opcao 2.\n\n";

                break;
            }
            else{
                std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
            }
        }
        return true;
    }

    Modelo::Usuario* TelaLogin::getUser(){
        return this->user;
    }

    TelaLogin::~TelaLogin(){
        delete user;
    }
}