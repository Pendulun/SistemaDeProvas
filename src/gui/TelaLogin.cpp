#include "gui/TelaLogin.hpp"

void limparTerminal(){
    #if defined _WIN32
        system("cls");
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined (__linux__)
        system("clear");
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
        system("clear");
    #endif 
}

namespace GUI{
    void TelaLogin::show(){

        bool sair = false;

        while(!sair){
            limparTerminal();
            std::cout<<std::endl;
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
                    std::cout<<"FAZER LOGIN!!!\n";
                    limparTerminal();
                    break;
                }
                else if (opcao.compare("2")==0){
                    limparTerminal();
                    cadastrar();
                    break;
                }
                else if(opcao.compare("3")==0){
                    sair = true;
                    limparTerminal();
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
                }
            }
        } 
    }

    void TelaLogin::cadastrar(){ 
        std::string nome;
        std::string login;
        std::string senha;
        std::string tipoUsuario;

        bool dadosCorretos = false;

        while(!dadosCorretos){
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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            std::cout<<"Digite sua senha (SEM ESPACOS): \n";
            std::cin>>senha;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            limparTerminal();

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
                    limparTerminal();
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n";
                }
            }
        }
    }
}
