#versão mínima do cmake
cmake_minimum_required(VERSION 3.0)

#nome do projeto
project(sistema_provas)

# Define a versão do C++ para C++ 17
set(CMAKE_CXX_STANDARD 17)
# Aqui adicionamos TODOS os arquivos .cpp do projeto
add_executable(sistema_provas 
    src/main.cpp
    src/business/application.cpp
    src/business/gui/UserGUI.cpp
    src/business/DAO/BaseDAO.cpp
    src/business/DAO/UsuarioDAO.cpp
    src/business/DAO/ProfessorDAO.cpp
    src/business/DAO/AlunoDAO.cpp
    src/business/DAO/TurmaDAO.cpp
    src/business/fachadas/manterUsuario.cpp
    src/business/fachadas/manterAluno.cpp
    src/business/fachadas/manterProfessor.cpp
    src/business/fachadas/manterTurma.cpp
    src/business/fachadas/excecoes/UserNotFoundException.cpp
    src/business/fachadas/excecoes/AlunoNotFoundException.cpp
    src/business/fachadas/excecoes/ProfessorNotFoundException.cpp
    src/business/fachadas/excecoes/TurmaNotFoundException.cpp
    src/business/Modelo/prova.cpp
    src/business/Modelo/questao.cpp
    src/business/Modelo/usuario.cpp
    src/business/Modelo/aluno.cpp
    src/business/Modelo/professor.cpp
    src/business/Modelo/turma.cpp
    src/gui/UserTerminalGUI.cpp
    src/gui/TelaLogin.cpp
    src/gui/TelaTurmasProfessor.cpp
    src/gui/SistemaUsuario.cpp
    src/gui/SistemaAluno.cpp
    src/gui/SistemaProfessor.cpp
    src/gui/TerminalUteis.cpp
    src/persistence/DAO/UsuarioDAOJSON.cpp
    src/persistence/Inicializador.cpp
    src/persistence/DAO/JSONFileHandler.cpp
    src/persistence/DAO/JSONObject.cpp
    src/persistence/DAO/TurmaDAOJSON.cpp)
#Aqui está indicado aonde estarão os arquivos .hpp do projeto, não é necessário mudar
target_include_directories(sistema_provas 
    PUBLIC ${PROJECT_SOURCE_DIR}/include/)