#include "gui/SistemaProfessor.hpp"

namespace GUI{

    SistemaProfessor::SistemaProfessor(Modelo::Professor* professor){
        this->professor = professor;
    }


    void SistemaProfessor::show(){
        OpcaoMenuInicial opcaoEscolhida;
        while(opcaoEscolhida != OpcaoMenuInicial::SAIR){
            this->mostrarSaudacoes();
            opcaoEscolhida = this->mostrarOpcoesMenu();
            switch (opcaoEscolhida)
            {
            case SistemaProfessor::OpcaoMenuInicial::TURMAS:
                std::cout<<"Ir para turmas\n";
                break;
            case SistemaProfessor::OpcaoMenuInicial::PROVAS:
                std::cout<<"Ir para provas\n";
                break;
            case SistemaProfessor::OpcaoMenuInicial::PERFIL :
                std::cout<<"Ir para perfil\n";
                break;
            case SistemaProfessor::OpcaoMenuInicial::SAIR:
                std::cout<<"Ir para sair\n";
                break;
            default:
                break;
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
        }
    }
    

    SistemaProfessor::~SistemaProfessor(){
        std::cout<<"Destruindo Sistema Professor"<<std::endl;
        delete this->professor;
    }
}