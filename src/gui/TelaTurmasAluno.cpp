#include "gui/TelaTurmasAluno.hpp"

namespace GUI{
    TelaTurmasAluno::TelaTurmasAluno(Modelo::Aluno* aluno){
        this->aluno = aluno;
    } 

    void TelaTurmasAluno::show(){
        bool voltar = false;
        while(!voltar){
            this->mostrarCabecalhoMenuInicial();
            OpcoesMenuTurmasAluno opcaoEscolhida;
            opcaoEscolhida = this->mostrarOpcoesMenu();

            if(opcaoEscolhida == OpcoesMenuTurmasAluno::OPERRADA){
                //roda o while de novo
            }else if(opcaoEscolhida == OpcoesMenuTurmasAluno::VOLTAR){
                voltar = true;
            }else{
                mapeiaEntrada(opcaoEscolhida);
            } 
            
        }
       
    }

    void TelaTurmasAluno::mostrarCabecalhoMenuInicial(){
        std::cout<<"--------------------\n";
        std::cout<<"Tela de Turmas Aluno\n";
        std::cout<<"--------------------\n";
    }

    TelaTurmasAluno::OpcoesMenuTurmasAluno TelaTurmasAluno::mostrarOpcoesMenu(){
        std::string opcaoEscolhida = "";
        std::cout<<"Escolha o numero da opcao desejada:\n";
        std::cout<<OpcoesMenuTurmasAluno::CADASTRAR<<" - Cadastrar em uma Turma\n";
        std::cout<<OpcoesMenuTurmasAluno::LISTAR<<" - Listar Turmas\n";
        std::cout<<OpcoesMenuTurmasAluno::VOLTAR<<" - Voltar\n";
        std::cin>>opcaoEscolhida;
        GUI::TerminalUteis terminalUtil;
        terminalUtil.limparTerminalEEntrada();
        if(opcaoEscolhida.compare(std::to_string(OpcoesMenuTurmasAluno::CADASTRAR))==0){
            return OpcoesMenuTurmasAluno::CADASTRAR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcoesMenuTurmasAluno::LISTAR))==0){
            return OpcoesMenuTurmasAluno::LISTAR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcoesMenuTurmasAluno::VOLTAR))==0){
            return OpcoesMenuTurmasAluno::VOLTAR;
        }else{
            return OpcoesMenuTurmasAluno::OPERRADA;
        }
    }

    void TelaTurmasAluno::mapeiaEntrada(OpcoesMenuTurmasAluno opcaoEscolhida){
        switch (opcaoEscolhida) 
            {
            case OpcoesMenuTurmasAluno::CADASTRAR :
            {
                this->cadastrarEmNovaTurma();
                break;
            }
            case OpcoesMenuTurmasAluno::LISTAR :
            {
                listarTurmasAluno();
                break;
            }
            default:
                break;
            }
    }

    void TelaTurmasAluno::mostrarCabecalhoCadastroNovaTurma(){
        std::cout<<"----------------------\n";
        std::cout<<"Cadastro em nova Turma\n";
        std::cout<<"----------------------\n";
    }

    void TelaTurmasAluno::listarTurmasAluno(){
        TerminalUteis util;
        util.limparTerminal();

        Business::ManterTurma manterTurma;
        std::list<Modelo::Turma> turmasAluno = manterTurma.pesquisarTurmas(this->aluno->getTurmas());

        bool voltar = false;

        while(!voltar){

            std::cout<<"---------------\n";
            std::cout<<"TURMAS DO ALUNO\n";
            std::cout<<"---------------\n\n";

            if(turmasAluno.size()==0){
                std::cout<<"Aluno nao cadastrado em nenhuma turma.\n\n";
                std::cout<<"Digite 1 para voltar.\n";

                std::string opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao.compare("1")==0){
                        util.limparTerminal();
                        voltar = true;
                        break;
                    }
                    else{
                        std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }
            }
            else{
                std::cout<<"Escolha a turma:\n\n";

                int i = 1;
                for (std::list<Modelo::Turma>::iterator it=turmasAluno.begin(); it != turmasAluno.end(); ++it){
                    std::cout<<i<<" - "<<(*it).getNome()<<std::endl;
                    i++;
                }

                std::cout<<i<<" - Voltar\n";

                int opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao>0 && opcao<=turmasAluno.size()){
                        util.limparTerminal();

                        Modelo::Turma turmaEscolhida;

                        int j = 1;
                        for (std::list<Modelo::Turma>::iterator it=turmasAluno.begin(); it != turmasAluno.end(); ++it){
                            if(j == opcao){
                                turmaEscolhida = *it;
                                break;
                            }
                            j++;
                        }

                        util.limparTerminal();

                        TelaTurmaEscolhidaAluno telaTurmaEscolhidaAluno(turmaEscolhida);
                        telaTurmaEscolhidaAluno.show();

                        break;
                    }
                    else if(opcao == i){
                        voltar = true;

                        util.limparTerminal();
                        break;
                    }
                    else{
                        std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                    }
                }
            }

        }
    }
}