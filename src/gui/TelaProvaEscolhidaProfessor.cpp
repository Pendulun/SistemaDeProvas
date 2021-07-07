#include "gui/TelaProvaEscolhidaProfessor.hpp"

namespace GUI{
    TelaProvaEscolhidaProfessor::TelaProvaEscolhidaProfessor(int idTurma, Modelo::Prova prova){
        this->prova = prova;
        this->idTurma = idTurma;
    }

    void TelaProvaEscolhidaProfessor::show(){
        bool sair = false;
        while(!sair){
            OpcaoMenuProvaEscolhidaProfessor opcaoEscolhida;
            this->mostrarSaudacoes();
            opcaoEscolhida = this->mostrarOpcoesMenu();
            if(opcaoEscolhida == TelaProvaEscolhidaProfessor::OpcaoMenuProvaEscolhidaProfessor::VOLTAR){
                sair=true;
            }else if(opcaoEscolhida == TelaProvaEscolhidaProfessor::OpcaoMenuProvaEscolhidaProfessor::OPERRADA){
                //roda o while de novo
            }else{
                this->mapeiaEntrada(opcaoEscolhida);
            }
        }
    }

    void TelaProvaEscolhidaProfessor::mostrarSaudacoes(){
        std::cout<<"------------------------------------------\n";
        std::cout<<"TELA DA PROVA "<<this->prova.getNome()<<std::endl;
        std::cout<<"------------------------------------------\n";
    }

    TelaProvaEscolhidaProfessor::OpcaoMenuProvaEscolhidaProfessor TelaProvaEscolhidaProfessor::mostrarOpcoesMenu(){
        GUI::TerminalUteis util;
        util.limparTerminal();
        std::string opcaoEscolhida = "";
        std::cout<<"Escolha o numero da opcao desejada:\n";
        
        std::cout<<OpcaoMenuProvaEscolhidaProfessor::EDITAR<<" - Editar\n";
        if(this->prova.getStatus()==Modelo::Status::OPEN){
            std::cout<<OpcaoMenuProvaEscolhidaProfessor::DISPONIVEL<<" - Fechar Prova para os Alunos\n";
        }else if(this->prova.getStatus()==Modelo::Status::PENDING){
            std::cout<<OpcaoMenuProvaEscolhidaProfessor::DISPONIVEL<<" - Disponibilizar Prova para os Alunos\n";
        }

        if(this->prova.isNotasLiberadas()){
            std::cout<<OpcaoMenuProvaEscolhidaProfessor::LIBERARNOTAS<<" - Nao Liberar Notas para alunos visualizarem\n";
        }else{
            std::cout<<OpcaoMenuProvaEscolhidaProfessor::LIBERARNOTAS<<" - Liberar Notas para alunos visualizarem\n";
        }
        
        

        std::cout<<OpcaoMenuProvaEscolhidaProfessor::RECORRIGIR<<" - Re-Corrigir\n";
        std::cout<<OpcaoMenuProvaEscolhidaProfessor::VOLTAR<<" - Voltar\n";
        std::cin>>opcaoEscolhida;
        GUI::TerminalUteis terminalUtil;
        terminalUtil.limparEntrada();
        terminalUtil.limparTerminal();
        if(opcaoEscolhida.compare(std::to_string(OpcaoMenuProvaEscolhidaProfessor::EDITAR))==0){
            return OpcaoMenuProvaEscolhidaProfessor::EDITAR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuProvaEscolhidaProfessor::LIBERARNOTAS))==0){
            return OpcaoMenuProvaEscolhidaProfessor::LIBERARNOTAS;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuProvaEscolhidaProfessor::RECORRIGIR))==0){
            return OpcaoMenuProvaEscolhidaProfessor::RECORRIGIR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuProvaEscolhidaProfessor::VOLTAR))==0){
            return OpcaoMenuProvaEscolhidaProfessor::VOLTAR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuProvaEscolhidaProfessor::DISPONIVEL))==0){
            return OpcaoMenuProvaEscolhidaProfessor::DISPONIVEL;
        }else{
            return OpcaoMenuProvaEscolhidaProfessor::OPERRADA;
        }
    }

void TelaProvaEscolhidaProfessor::mapeiaEntrada(TelaProvaEscolhidaProfessor::OpcaoMenuProvaEscolhidaProfessor opcaoEscolhida){
        TerminalUteis util;

        switch (opcaoEscolhida)
            {
            case OpcaoMenuProvaEscolhidaProfessor::EDITAR:
            {
                std::cout<<"Ir para Tela de edicao de prova\n";
                break;
            }
            case OpcaoMenuProvaEscolhidaProfessor::DISPONIVEL:
            {
                if(this->prova.getStatus()==Modelo::Status::OPEN){
                    std::cout<<"Tem certeza que fechar a prova para os Alunos?\n";
                }else if(this->prova.getStatus()==Modelo::Status::PENDING){
                    std::cout<<"Tem certeza que quer disponibilizar a prova para os Alunos?\n";
                }
                
                std::cout<<"1 - Sim\n";
                std::cout<<"2 - Nao\n";

                while(true){
                    std::string opcao = "";
                    std::cin>>opcao;

                    if(opcao.compare("1")==0){
                        if(this->prova.getStatus()==Modelo::Status::OPEN){
                            this->prova.setStatus(Modelo::Status::PENDING);
                        }else if(this->prova.getStatus()==Modelo::Status::PENDING){
                            this->prova.setStatus(Modelo::Status::OPEN);
                        }
                        Business::ManterTurma manterTurma;
                        manterTurma.atualizarProvaEmTurma(this->idTurma, this->prova);
                        
                        break;
                    }else if(opcao.compare("2")==0){
                        break;
                    }else{
                        std::cout<<"Opcao invalida! Tente novamente.\n";
                    }
                }
                break;
            }
            case OpcaoMenuProvaEscolhidaProfessor::LIBERARNOTAS:
            {
                if(this->prova.isNotasLiberadas()){
                    std::cout<<"Tem certeza que nao quer liberar os alunos para verem suas notas na prova?\n";
                }else{
                    std::cout<<"Tem certeza que quer liberar os alunos para verem suas notas na prova?\n";
                }
                
                std::cout<<"1 - Sim\n";
                std::cout<<"2 - Nao\n";

                while(true){
                    std::string opcao = "";
                    std::cin>>opcao;

                    if(opcao.compare("1")==0){
                        if(this->prova.isNotasLiberadas()){
                            this->prova.setNotasLiberadas(false);
                            Business::ManterTurma manterTurma;
                            manterTurma.atualizarProvaEmTurma(this->idTurma, this->prova);
                        }else{
                            this->prova.setNotasLiberadas(true);
                        }
                        
                        break;
                    }else if(opcao.compare("2")==0){
                        break;
                    }else{
                        std::cout<<"Opcao invalida! Tente novamente.\n";
                    }
                }
                break;
            }
            case OpcaoMenuProvaEscolhidaProfessor::RECORRIGIR:
            {
                std::cout<<"Tem certeza que quer recorrigir as provas dos alunos?\n";
                std::cout<<"1 - Sim\n";
                std::cout<<"2 - Nao\n";
                break;
            }
            default:
            {
                break;
            }
        }
    }
}