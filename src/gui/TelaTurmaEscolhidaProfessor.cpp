#include "gui/TelaTurmaEscolhidaProfessor.hpp"

namespace GUI{

    TelaTurmaEscolhidaProfessor::TelaTurmaEscolhidaProfessor (Modelo::Turma turma){
        this->turma = turma;
    }

    void TelaTurmaEscolhidaProfessor::show(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"---------------------------------------\n";
            std::cout<<"TELA DA TURMA "<<this->turma.getNome()<<" ID: "<<this->turma.getId()<<std::endl;
            std::cout<<"---------------------------------------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Provas\n";
            std::cout<<"2 - Ver alunos\n";
            std::cout<<"3 - Alterar\n";
            std::cout<<"4 - Excluir\n";
            std::cout<<"5 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    verProvas();
                    break;
                }else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    std::cout<<"Tela de ver alunos\n";
                    break;
                }else if(opcao.compare("3")==0){
                    util.limparTerminal();
                    std::cout<<"Tela de alterar turma\n";
                    break;             
                }else if(opcao.compare("4")==0){
                    util.limparTerminal();
                    std::cout<<"Tela de excluir turma\n";
                    break;
                }else if(opcao.compare("5")==0){
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

    void TelaTurmaEscolhidaProfessor::cadastrarProva(){
        TerminalUteis util;
        util.limparTerminal();

        int inicio;
        int fim;
        std::string nome;

        bool adicionando = true;

        //Se der tempo, dar opcao de reutilizar prova
        std::cout<<"Digite o dia de inicio (um numero inteiro): \n";
        std::cin>>inicio;
        std::cout<<"Digite o dia de termino (um numero inteiro): \n";
        std::cin>>fim;
        std::cout<<"Digite o titulo da prova: \n";
        std::cin.ignore();
        std::getline(std::cin, nome);

        Modelo::Prova prova(inicio, fim, nome);

        while(true){
            std::string opcao;
            util.limparTerminal();
            std::cout<<"\nGostaria de adicionar algum assunto na lista de assuntos da prova?\n";
            std::cout<<"1-Sim\n";
            std::cout<<"2-Nao\n";
            std::cin>>opcao;

            if(opcao.compare("1")==0){
                util.limparTerminal();
                std::cout<<"\nDigite um assunto para a lista de assuntos da prova: \n";
                std::string assunto;

                std::cin.ignore(); //Isso ??s vezes d?? problema
                std::getline(std::cin, assunto);

                prova.addAssunto(assunto);
            }
            else if (opcao.compare("2")==0){
                break;
            }
            else{
                std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
            }
        }

        util.limparTerminal();
        const int NUMEROALTERNATIVAS = 4;
        std::string enunciado;
        std::string alternativa;
        std::string alternativas[NUMEROALTERNATIVAS];
        int alternativaCerta;

        util.limparEntrada();

        while(adicionando){
            util.limparTerminal();

            std::cout<<"Digite o enunciado da questao: \n";
            std::getline(std::cin, enunciado);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 1: \n";
            std::getline(std::cin, alternativas[0]);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 2: \n";
            std::getline(std::cin, alternativas[1]);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 3: \n";
            std::getline(std::cin, alternativas[2]);
            std::cout<<"\n";

            std::cout<<"Digite a alternativa 4: \n";
            std::getline(std::cin, alternativas[3]);
            std::cout<<"\n";

            while(true){
                try{
                    std::cout<<"Digite o numero da alternativa correta (1, 2, 3 ou 4): \n";
                    std::cin>>alternativaCerta;
                    util.limparEntrada();
                    if(alternativaCerta > 0 && alternativaCerta <=NUMEROALTERNATIVAS){
                        break;
                    }else{
                        std::cout<<"Valor invalido, digite novamente!\n";
                    }
                }catch(std::exception& e){
                    std::cout<<"Valor invalido, digite novamente!\n";
                }
            }

            int valorQuestao=0;

            while(true){
                try{
                    std::cout<<"Digite o valor da questao (Apenas numeros inteiros): \n";
                    std::cin>>valorQuestao;
                    util.limparEntrada();
                    if(valorQuestao > 0){
                        break;
                    }else{
                        std::cout<<"Valor invalido, digite novamente!\n";
                    }
                }catch(std::exception& e){
                    std::cout<<"Valor invalido, digite novamente!\n";
                }
            }

            Modelo::Questao questao;
            
            for(int i = 0; i<NUMEROALTERNATIVAS; i++){
                Modelo::Alternativa alternativa;
                alternativa.setTexto(alternativas[i]);
                alternativa.setNumeroAlternativa(i+1);
                questao.addAlternativa(alternativa);
            }

            questao.setEnunciado(enunciado);
            questao.setAlternativaCorreta(alternativaCerta);
            questao.setValor(valorQuestao);
            
            prova.InsertQuestao(questao);

            util.limparTerminal();
            std::cout<<"Questao adicionada com sucesso. Adicionar outra questao?\n";
            std::cout<<"1 - Sim\n";
            std::cout<<"2 - Nao\n";

            std::string opcao;

            while(true){
                std::cin>>opcao;
                util.limparEntrada();

                if(opcao.compare("1")==0){
                    break;
                }
                else if (opcao.compare("2")==0){
                    util.limparTerminal();
                                        
                    Business::ManterTurma manterTurma;
                    bool cadastroFeito = manterTurma.cadastrarProva(this->turma, prova);
                    adicionando = false;       

                    if (cadastroFeito){
                        std::cout<<"Prova criada com sucesso!!\n\n";
                    }
                    else{
                        std::cout<<"Nao foi possivel cadastrar a prova.\n\n";
                    }
                    break;
                }
                else{
                    std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
                }
            }
        }
            
        prova.mostrarProva();

        std::string opcao;

        while(true){
            std::cout<<"Digite 1 para voltar.\n";

            std::cin>>opcao;
            util.limparEntrada();

            if(opcao.compare("1")==0){
                util.limparTerminal();
                break;
            }
            else{
                std::cout<<"OPCAO INVALIDA!!! Digite novamente.\n\n";
            }
        }
    }

    void TelaTurmaEscolhidaProfessor::verProvas(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"------\n";
            std::cout<<"PROVAS\n";
            std::cout<<"------\n\n";

            std::cout<<"Escolha a opcao:\n\n";
            std::cout<<"1 - Postar prova\n";
            std::cout<<"2 - Escolher prova\n";
            std::cout<<"3 - Voltar\n\n";

            std::string opcao;

            while(true){

                std::cin>>opcao;

                if(opcao.compare("1")==0){
                    util.limparTerminal();
                    cadastrarProva();
                    break;
                }else if(opcao.compare("2")==0){
                    util.limparTerminal();
                    listarProvas();
                    break;
                }else if(opcao.compare("3")==0){
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

    void TelaTurmaEscolhidaProfessor::listarProvas(){

        bool voltar = false;

        TerminalUteis util;

        while(!voltar){

            std::cout<<"---------------------------------------\n";
            std::cout<<"PROVAS DA TURMA "<<this->turma.getNome()<<std::endl;
            std::cout<<"---------------------------------------\n\n";

            if(this->turma.getProvas().size()==0){
                std::cout<<"Turma sem provas cadastradas.\n\n";
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

                std::cout<<"Escolha a prova:\n\n";

                int i = 1;
                for(Modelo::Prova prova : this->turma.getProvas()){
                    std::cout<<i<<" - "<<prova.getNome()<<std::endl;
                    i++;
                }
                std::cout<<i<<" - Voltar\n"; 

                int opcao;

                while(true){

                    std::cin>>opcao;
                    util.limparEntrada();

                    if(opcao>0 && opcao<=this->turma.getProvas().size()){
                        util.limparTerminal();

                        Modelo::Prova provaEscolhida("Nome");

                        int j = 1;
                        for(Modelo::Prova prova : this->turma.getProvas()){
                            if(j == opcao){
                                provaEscolhida = prova;
                                break;
                            }
                            j++;
                        }

                        util.limparTerminal();
                        GUI::TelaProvaEscolhidaProfessor telaProvaEscolhida(this->turma.getId(), provaEscolhida);
                        telaProvaEscolhida.show();
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