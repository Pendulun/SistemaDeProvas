#include "gui/SistemaAluno.hpp"

namespace GUI{
    void SistemaAluno::show(){
        bool sair = false;
        while(!sair){
            OpcaoMenuInicialAluno opcaoEscolhida;
            this->mostrarSaudacoes();
            opcaoEscolhida = this->mostrarOpcoesMenu();
            if(opcaoEscolhida == SistemaAluno::OpcaoMenuInicialAluno::SAIR){
                sair=true;
            }else if(opcaoEscolhida == SistemaAluno::OpcaoMenuInicialAluno::OPERRADAALUNO){
                //roda o while de novo
            }else{
                this->mapeiaEntrada(opcaoEscolhida);
            }
        }
    }

    void SistemaAluno::mapeiaEntrada(SistemaAluno::OpcaoMenuInicialAluno opcaoEscolhida){
        TerminalUteis util;

        switch (opcaoEscolhida)
            {
            case OpcaoMenuInicialAluno::TURMAS:
            {
                std::cout<<"Ir para Tela Turmas Aluno\n";
                break;
            }
            case OpcaoMenuInicialAluno::PERFIL:
            {
                
                GUI::TelaPerfil telaPerfil(*this->aluno);
                telaPerfil.show();
                break;
            }
            default:
            {
                break;
            }
        }
    }
    
    void SistemaAluno::mostrarSaudacoes(){
        std::cout<<"------------------------------------------\n";
        std::cout<<"BEM-VINDO "<<this->aluno->getNome()<<"\n";
        std::cout<<"------------------------------------------\n";
    }

    SistemaAluno::OpcaoMenuInicialAluno SistemaAluno::mostrarOpcoesMenu(){
        std::string opcaoEscolhida = "";
        std::cout<<"Escolha o numero da opcao desejada:\n";
        std::cout<<OpcaoMenuInicialAluno::TURMAS<<" - Minhas Turmas\n";
        std::cout<<OpcaoMenuInicialAluno::PERFIL<<" - Meu Perfil\n";
        std::cout<<OpcaoMenuInicialAluno::SAIR<<" - Sair\n";
        std::cin>>opcaoEscolhida;
        GUI::TerminalUteis terminalUtil;
        terminalUtil.limparEntrada();
        terminalUtil.limparTerminal();
        if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicialAluno::TURMAS))==0){
            return OpcaoMenuInicialAluno::TURMAS;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicialAluno::PERFIL))==0){
            return OpcaoMenuInicialAluno::PERFIL;
        }else if(opcaoEscolhida.compare(std::to_string(OpcaoMenuInicialAluno::SAIR))==0){
            return OpcaoMenuInicialAluno::SAIR;
        }else{
            return OpcaoMenuInicialAluno::OPERRADAALUNO;
        }
    }

    SistemaAluno::SistemaAluno(Modelo::Aluno* aluno){
        this->aluno = aluno;
    }

    SistemaAluno::~SistemaAluno(){
        std::cout<<"Destruindo Sistema Aluno"<<std::endl;
        delete this->aluno;
    }
}

