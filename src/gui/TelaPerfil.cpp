#include "gui/TelaPerfil.hpp"

namespace GUI{

    TelaPerfil::TelaPerfil(Modelo::Usuario& user){
        this->user = user;
    }   

    void TelaPerfil::show(){

        TerminalUteis util;

        bool voltar = false;

        while(!voltar){
            util.limparTerminal();

            std::cout<<"------\n";
            std::cout<<"PERFIL\n";
            std::cout<<"------\n\n";

            std::cout<<"Nome: "<<this->user.getNome()<<std::endl;
            std::cout<<"Login: "<<this->user.getLogin()<<std::endl;
            std::cout<<"Senha: "<<this->user.getSenha()<<std::endl;

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
    }

    bool TelaPerfil::alterarPerfil(){
        TerminalUteis util;
        util.limparTerminal();

        Modelo::Usuario userNovo;
        userNovo.setNome(this->user.getNome());
        userNovo.setLogin(this->user.getLogin());
        userNovo.setSenha(this->user.getSenha());

        bool voltar = false;

        while(!voltar){

            std::cout<<"-------------------\n";
            std::cout<<"ALTERACAO DE PERFIL\n";
            std::cout<<"-------------------\n\n";

            std::cout<<"Nome: "<<this->user.getNome()<<std::endl;
            std::cout<<"Login: "<<this->user.getLogin()<<std::endl;
            std::cout<<"Senha: "<<this->user.getSenha()<<std::endl;

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
                    std::cout<<"Nome atual: "<<this->user.getNome()<<std::endl;

                    std::cout<<"\nDigite o novo nome desejado: \n";
                    std::cin.ignore();
                    std::getline(std::cin, alteracao);

                    userNovo.setNome(alteracao);
                    util.limparTerminal();
                    break;
                    //return false;
                }
                else if (opcao.compare("2")==0){
                    util.limparTerminal();
                    std::cout<<"Login atual: "<<this->user.getLogin()<<std::endl;
                    
                    std::cout<<"\nDigite o novo login desejado (SEM ESPACOS): \n";
                    std::cin>>alteracao;

                    userNovo.setLogin(alteracao);
                    util.limparTerminal();
                    break;
                    //return false;
                }
                else if (opcao.compare("3")==0){
                    util.limparTerminal();
                    std::cout<<"Senha atual: "<<this->user.getSenha()<<std::endl;
                    
                    std::cout<<"\nDigite a nova senha desejada (SEM ESPACOS): \n";
                    std::cin>>alteracao;

                    userNovo.setSenha(alteracao);
                    util.limparTerminal();
                    break;
                    //return false;
                }
                else if (opcao.compare("4")==0){
                    util.limparTerminal();

                    voltar = true;
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }  

            if(!voltar){
                Business::ManterUsuario manterUsuario;
                bool atualizou = manterUsuario.atualizarUsuario(this->user, userNovo);

                if(atualizou){
                    std::cout<<"Perfil atualizado com sucesso!\n";
                }
                else{
                    std::cout<<"Nao foi possivel atualizar o perfil.\n";
                }
            }

        }
        
    }

}
