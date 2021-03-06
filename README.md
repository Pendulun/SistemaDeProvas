# SistemaDeProvas
Trabalho da matéria Engenharia de Software na UFMG

O objetivo desse trabalho é desenvolver um sistema simples onde um professor conseguirá cadastrar uma prova de múltipla escolha e, depois, os alunos respondem essa prova recebendo a sua nota. Além disso, o professor conseguirá ver a pontuação final de cada aluno.

O Sistema será desenvolvido na linguagem C++, terá uma interface no terminal e, como forma de persistência de dados, usaremos arquivos JSON.

Integrantes do grupo:
- Daniel Souza de Campos (Pendulun) (Frontend + Regras de Negócio)
- Felipe Machado Cordeiro (felipemcord) (Persistência)
- Letícia da Silva Macedo Alves (leticiasma) (Frontend)
- Marcos Vinícius de Carvalho Ribeiro (marcosmoade) (Regras de Negócio)

Quadro de tarefas:
https://github.com/Pendulun/SistemaDeProvas/projects/1

## Backlog do Produto

- Eu, como Professor, quero poder criar uma Turma nova
- Eu, como Aluno, quero poder me cadastrar em uma Turma
- Eu, como Professor, quero poder criar Provas e disponibilizá-la em uma Turma
- Eu, como Professor, quero poder criar uma Prova com base em outras Provas já criadas
- Eu, como Professor, quero poder controlar quando a prova pode ser realizada pelos meus Alunos
- Eu, como Aluno, quero poder ver as provas disponíveis para serem feitas nas minhas Turmas
- Eu, como Aluno, quero poder olhar quais conteúdos devo estudar para as Provas
- Eu, como Professor, quero poder controlar quando os Alunos podem ver a nota deles na Prova
- Eu, como Professor, quero poder ver as notas dos Alunos nas minhas Provas
- Eu, como Aluno, quero poder ver as notas das minhas Provas assim que possível
- Eu, como Aluno, quero poder ver a correção da minha tentativa após a liberação da mesma
- Eu, como Aluno, quero poder ver todas as minhas Provas feitas
- Eu, como Usuário, quero poder criar uma conta
- Eu, como Usuário, quero poder alterar o meu perfil
- Eu, como Professor, quero pode aleatorizar a ordem das Questões das Provas e suas Alternativas
- Eu, como Professor, quero definir um tempo máximo para realização das Provas

## Backlog da Sprint

- Eu, como Usuário, quero poder criar uma conta e acessar o sistema com ela
  - Desenvolver uma interface de cadastro e login de usuário (Letícia)
  - Implementar lógica de cadastro e login de usuário (Daniel)
  - Persistir um Usuário (Professor ou Aluno) (Felipe)
- Eu, como Professor, quero poder criar uma Turma nova
  - Desenvolver uma interface para cadastro de Turma nova (Letícia)
  - Desenvolver uma interface com menu para professores (Daniel)
  - Implementar lógica para cadastro de Turma nova (Daniel)
  - Persistir Turma nova (Felipe)
- Eu, como Aluno, quero poder me cadastrar em uma Turma
  - Desenvolver uma interface de cadastro em Turma (Letícia)
  - Desenvolver uma interface com menu para Alunos (Daniel)
  - Implementar lógica de cadastro de Aluno em Turma (Daniel)
  - Persistir o cadastro do aluno em uma Turma (Felipe)
- Eu, como Professor, quero poder criar Provas e disponibilizá-la em uma Turma
  - Desenvolver uma interface de criação de Provas (Letícia)
  - Implementar a lógica de criação de Provas (Marcos)
  - Persistir uma nova Prova em uma conta de Professor (Felipe)
- Eu, como Professor, quero poder criar uma Prova com base em outras Provas já criadas
  - Desenvolver interface que permita copiar uma Prova e postá-la em outra Turma (Daniel)
  - Implementar lógica de cópia de provas (Marcos)
  - Persistir uma Prova postada em uma Turma (Felipe)
- Eu, como Professor, quero poder controlar quando a prova pode ser realizada pelos meus Alunos
  - Desenvolver interface que permita escolher quando uma prova postada pode ser resolvida (Daniel)
  - Implementar lógica de disponibilização de provas em uma Turma (Marcos)
- Eu, como Professor, quero poder controlar quando os Alunos podem ver a nota deles na Prova
  - Desenvolver interface que permita controle de visualização de notas pelo professor (Daniel)
  - Implementar lógica de controle de visualização de notas (Daniel)
- Eu, como Aluno, quero poder ver as provas disponíveis para serem feitas nas minhas Turmas
  - Desenvolver interface que permite o Aluno ver as provas disponíveis para serem feitas (Letícia)
  - Implementar lógica de recuperação de Provas disponíveis (Marcos)
  - Persistir uma Prova resolvida por um Aluno (Felipe)
- Eu, como Aluno, quero poder olhar quais conteúdos devo estudar para as Provas
  - Desenvolver interface que permite o Professor informar assunto da prova e o Aluno ver esse assunto (Letícia)
  - Implementar lógica de cadastro e pesquisa de assunto de Prova (Marcos)
- Eu, como Professor, quero poder ver as notas dos Alunos nas minhas Provas
  - Desenvolver interface que permite o Professor ver as notas dos alunos em uma Prova específica (Letícia)
  - Implementar lógica de pesquisa de notas de Alunos em uma Prova (Marcos)
- Eu, como Aluno, quero poder ver as notas das minhas Provas assim que possível
  - Desenvolver interface que permite o Aluno ver as notas de suas provas feitas (Letícia)
  - Implementar lógica de pesquisa de notas de Provas de um Aluno (Marcos)
- Eu, como Aluno, quero poder ver a correção da minha tentativa após a liberação da mesma
  - Desenvolver interface que permite o Aluno ver a revisão de uma Prova (Letícia)
  - Implementar lógica de correção e revisão de uma Prova (Marcos)
- Eu, como Aluno, quero poder ver todas as minhas Provas feitas
  - Desenvolver interface que permite o Aluno todas as Provas feitas (Letícia)
  - Implementar lógica de pesquisa de Provas de um Aluno (Marcos)
- Eu, como Usuário, quero poder alterar o meu perfil
  - Desenvolver interface que permita o usuário alterar o seu perfil (Letícia)
  - Implementar lógica de alteração de perfil (Marcos)

## Arquitetura Básica

![Arquitetura básica do sistema](Diagramas/arquiteturaBasica.png)

## Fluxo Usuários

![Fluxo dos usuários](Diagramas/FluxoUsuários.png)
