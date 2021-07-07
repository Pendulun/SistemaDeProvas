#include "gui/TelaTurmasProfessor.hpp"

namespace GUI{
    TelaTurmasProfessor::TelaTurmasProfessor(Modelo::Professor* professor){
        this->professor = professor;
    } 

    void TelaTurmasProfessor::show(){
        bool voltar = false;
        while(!voltar){
            this->mostrarCabecalhoMenuInicial();
            OpcoesMenuTurmasProfessor opcaoEscolhida;
            opcaoEscolhida = this->mostrarOpcoesMenu();
            if(opcaoEscolhida != OpcoesMenuTurmasProfessor::VOLTAR){
                mapeiaEntrada(opcaoEscolhida);
            }else if(opcaoEscolhida == OpcoesMenuTurmasProfessor::OPERRADA){
                //roda o while de novo
            }
            else if(opcaoEscolhida == OpcoesMenuTurmasProfessor::VOLTAR){
                voltar = true;
            }
        }
       
    }

    void TelaTurmasProfessor::mostrarCabecalhoMenuInicial(){
        std::cout<<"------------------------\n";
        std::cout<<"Tela de Turmas Professor\n";
        std::cout<<"------------------------\n";
    }

    TelaTurmasProfessor::OpcoesMenuTurmasProfessor TelaTurmasProfessor::mostrarOpcoesMenu(){
        std::string opcaoEscolhida = "";
        std::cout<<"Escolha o numero da opcao desejada:\n";
        std::cout<<OpcoesMenuTurmasProfessor::CADASTRAR<<" - Cadastrar Turma\n";
        std::cout<<OpcoesMenuTurmasProfessor::LISTAR<<" - Listar Turmas\n";
        std::cout<<OpcoesMenuTurmasProfessor::VOLTAR<<" - Voltar\n";
        std::cin>>opcaoEscolhida;
        GUI::TerminalUteis terminalUtil;
        terminalUtil.limparTerminalEEntrada();
        if(opcaoEscolhida.compare(std::to_string(OpcoesMenuTurmasProfessor::CADASTRAR))==0){
            return OpcoesMenuTurmasProfessor::CADASTRAR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcoesMenuTurmasProfessor::LISTAR))==0){
            return OpcoesMenuTurmasProfessor::LISTAR;
        }else if(opcaoEscolhida.compare(std::to_string(OpcoesMenuTurmasProfessor::VOLTAR))==0){
            return OpcoesMenuTurmasProfessor::VOLTAR;
        }else{
            return OpcoesMenuTurmasProfessor::OPERRADA;
        }
    }

    void TelaTurmasProfessor::mapeiaEntrada(OpcoesMenuTurmasProfessor opcaoEscolhida){
        switch (opcaoEscolhida)
            {
            case OpcoesMenuTurmasProfessor::CADASTRAR :
            {
                this->cadastrarNovaTurma();
                break;
            }
            case OpcoesMenuTurmasProfessor::LISTAR :
            {
                listarTurmasProfessor();
                break;
            }
            default:
                break;
            }
    }

    void TelaTurmasProfessor::listarTurmasProfessor(){
        TerminalUteis util;
        util.limparTerminal();

        Business::ManterTurma manterTurma;
        std::list<Modelo::Turma> turmasProfessor = manterTurma.pesquisarTurmas(this->professor->getTurmas());

        bool voltar = false;

        while(!voltar){

            std::cout<<"-------------------\n";
            std::cout<<"TURMAS DO PROFESSOR\n";
            std::cout<<"-------------------\n\n";

            if(turmasProfessor.size()==0){
                std::cout<<"Professor sem turmas cadastradas.\n\n";
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
                for (std::list<Modelo::Turma>::iterator it=turmasProfessor.begin(); it != turmasProfessor.end(); ++it){
                    std::cout<<i<<" - "<<(*it).getNome()<<std::endl;
                    i++;
                }

                std::cout<<i<<" - Voltar\n";

                int opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao>0 && opcao<=turmasProfessor.size()){
                        util.limparTerminal();

                        Modelo::Turma turmaEscolhida;

                        int j = 1;
                        for (std::list<Modelo::Turma>::iterator it=turmasProfessor.begin(); it != turmasProfessor.end(); ++it){
                            if(j == opcao){
                                turmaEscolhida = *it;
                                break;
                            }
                            j++;
                        }

                        util.limparTerminal();

                        TelaTurmaEscolhidaProfessor telaTurmaEscolhidaProfessor(turmaEscolhida);
                        telaTurmaEscolhidaProfessor.show();

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

    void TelaTurmasProfessor::cadastrarNovaTurma(){
        std::string nomeTurma = "";
        bool voltar = false;
        while(!voltar){
            this->mostrarCabecalhoCadastroNovaTurma();
            std::cout<<"Digite o nome da nova turma ou \""<<OpcoesMenuTurmasProfessor::VOLTAR<<"\" para voltar\n";
            std::getline(std::cin, nomeTurma);
            GUI::TerminalUteis terminalUtil;
            terminalUtil.limparTerminalEEntrada();

            if(nomeTurma.compare(std::to_string(OpcoesMenuTurmasProfessor::VOLTAR))!=0){
                if(this->confirmarNomeNovaTurma(nomeTurma)){
                    Modelo::Turma turma;
                    turma.setNome(nomeTurma);

                    Business::ManterTurma manterTurma;
                    bool cadastrou = manterTurma.cadastrarTurma(turma, this->professor);

                    if(cadastrou){
                        std::cout<<"Turma cadastrada com sucesso!\n";
                    }
                    else{
                        std::cout<<"Nao foi possivel cadastrar a turma.\n";
                    }

                    voltar = true;
                }else{
                    //roda o while de novo
                }
            }else{
                voltar=true;
            }
        }
    }

    void TelaTurmasProfessor::mostrarCabecalhoCadastroNovaTurma(){
        std::cout<<"----------------------\n";
        std::cout<<"Cadastro de nova Turma\n";
        std::cout<<"----------------------\n";
    }

    bool TelaTurmasProfessor::confirmarNomeNovaTurma(std::string nomeTurma){
        bool resposta = false;
        while(true){
            GUI::TerminalUteis terminalUtil;
            terminalUtil.limparTerminal();
            std::string opcao="";
            std::cout<<"Tem certeza que deseja cadastrar uma nova turma de nome: "<<nomeTurma<<" ?\n";
            std::cout<<"1 - Sim\n";
            std::cout<<"2 - Nao\n";
            std::cin>>opcao;
            terminalUtil.limparTerminalEEntrada();
            if(opcao.compare("1")==0){
                resposta=true;
                break;
            }else if(opcao.compare("2")==0){
                resposta=false;
                break;
            }else{
                //roda o while mais uma vez
            }
        }

        return resposta;
    }
}