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
        std::cout<<OpcaoMenuInicial::PERFIL<<" - Perfil\n";
        std::cout<<OpcaoMenuInicial::SAIR<<" - Sair\n";
        std::cin>>opcaoEscolhida;
        GUI::TerminalUteis terminalUtil;
        terminalUtil.limparEntrada();
        terminalUtil.limparTerminal();
        if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicial::TURMAS))==0){
            return OpcaoMenuInicial::TURMAS;
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
            case OpcaoMenuInicial::PERFIL:
            {   
                GUI::TelaPerfil telaPerfil(*this->professor);
                telaPerfil.show();
      
                break;
            }
            default:
                break;
            }
    }

    SistemaProfessor::~SistemaProfessor(){
        std::cout<<"Destruindo Sistema Professor"<<std::endl;
        delete this->professor;
    }
}