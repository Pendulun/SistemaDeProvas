#include "gui/TelaLogin.hpp"
#include "gui/TerminalUteis.hpp"

namespace GUI{
    void TelaLogin::show(){

        TerminalUteis util;

        bool sair = false;

        while(!sair){
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

        while(!voltar){
            std::cout<<"-------------------\n";
            std::cout<<"LOGIN DE USUARIO\n";
            std::cout<<"-------------------\n\n"; 

            bool dadosCorretos = false;

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
                dadosCorretos = false;

                if(dadosCorretos){
                    util.limparTerminal();
                    std::cout<<"ENTROU NO SISTEMA!!! \n";
                }
                else{
                    util.limparTerminal();
                    std::cout<<"Login invalido. Escolha a opcao:\n";
                    std::cout<<"1 - Tentar login novamente\n";
                    std::cout<<"2 - Voltar \n";
                }

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

    void TelaLogin::cadastrar(){ 

        TerminalUteis util;

        std::string nome;
        std::string login;
        std::string senha;
        std::string tipoUsuario;

        bool dadosCorretos = false;

        while(!dadosCorretos){
            std::cout<<"-------------------\n";
            std::cout<<"CADASTRO DE USUARIO\n";
            std::cout<<"-------------------\n\n";

            std::cout<<"Escolha a opcao: \n";
            std::cout<<"1 - Sou aluno \n";
            std::cout<<"2 - Sou professor \n";        

            while(true){
                std::cin>>tipoUsuario;

                if(tipoUsuario.compare("1")==0){
                    break;
                }
                else if (tipoUsuario.compare("2")==0){
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
            if(tipoUsuario.compare("1")==0){
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
}