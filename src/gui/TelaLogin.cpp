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
            std::cout<<"3 - Sair\n\n";

            std::string opcao;

            while(true){
                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    loginSucesso = fazLogin();
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
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }
        } 
    }

    bool TelaLogin::fazLogin(){

        TerminalUteis util;

        bool voltar = false;
        bool dadosCorretos = false;
        bool fezLogin = false;

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
                    fezLogin = true;
                    
                }
                else{
                    util.limparTerminal();
                    std::cout<<"Login invalido. Escolha a opcao:\n";
                    std::cout<<"1 - Tentar login novamente\n";
                    std::cout<<"2 - Voltar \n";
                    fezLogin=false;
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
        return fezLogin;
    }

    void TelaLogin::cadastrar(){ 

        TerminalUteis util;
        bool voltar = false;
        bool tentouCadastro = false;
        bool tentativaCadastroSucesso = false;
        bool cadastrou = false;
        bool opcaoInvalida = false;

        while(!voltar){
            std::string nome;
            std::string login;
            std::string senha;
            std::string opcaoTipoUsuario;
            Modelo::TipoUsuario tipoUsuario;

            util.limparTerminal();
            std::cout<<"-------------------\n";
            std::cout<<"CADASTRO DE USUARIO\n";
            std::cout<<"-------------------\n\n";

            if(tentouCadastro && tentativaCadastroSucesso){
                std::cout<<"Cadastro feito com sucesso!\n\n";
            }else if(tentouCadastro && !tentativaCadastroSucesso){
                std::cout<<"Cadastro nao completado, tente novamente!\n\n";
            }

            if(opcaoInvalida){
                std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
            }

            std::cout<<"Escolha a opcao: \n";
            std::cout<<"1 - Sou aluno \n";
            std::cout<<"2 - Sou professor \n"; 
            std::cout<<"3 - Voltar \n\n";       

            std::cin>>opcaoTipoUsuario;
            util.limparEntrada();

            if(opcaoTipoUsuario.compare("1")==0 || opcaoTipoUsuario.compare("2")==0){
                opcaoInvalida = false;

                if(opcaoTipoUsuario.compare("1")==0){
                    tipoUsuario = Modelo::TipoUsuario::ALUNO;
                }else{
                    tipoUsuario = Modelo::TipoUsuario::PROFESSOR;
                }

                pedirDados(nome, login, senha);
                util.limparTerminal();

                if (checarDados(tipoUsuario, nome, login, senha)){
                    Business::ManterUsuario manterUsuario;
                    tentouCadastro = true;
                    if(manterUsuario.cadastrarUsuario(nome, login, senha, tipoUsuario)){
                        tentativaCadastroSucesso = true;
                    }
                    else{
                        tentativaCadastroSucesso = false;
                    }
                }
                else{
                    tentativaCadastroSucesso = false;
                    tentouCadastro = false;
                }

            }
            else if (opcaoTipoUsuario.compare("3")==0){
                voltar = true;
                opcaoInvalida = false;
            }
            else{
                tentativaCadastroSucesso = false;
                tentouCadastro = false;
                opcaoInvalida=true;
            }
        }
    }

    void TelaLogin::pedirDados(std::string& nome, std::string& login, std::string& senha){

        TerminalUteis util;

        util.limparTerminal();

        std::cout<<"\nDigite seu nome completo: \n";
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
        while(true){
            util.limparTerminal();
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
            std::cin>>opcao;

            if(opcao.compare("1")==0){
                return true;
            }
            else if (opcao.compare("2")==0){
                util.limparTerminal();
                return false;
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
        if(this->user != nullptr){
            delete user;
        }
    }
}