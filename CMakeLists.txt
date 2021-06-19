#versão mínima do cmake
cmake_minimum_required(VERSION 3.0)

#nome do projeto
project(sistema_provas)

# Define a versão do C++ para C++ 11
set(CMAKE_CXX_STANDARD 11)

# Aqui adicionamos TODOS os arquivos .cpp do projeto
add_executable(sistema_provas 
    src/main.cpp
    src/business/application.cpp
    src/business/gui/UserGUI.cpp
    src/gui/UserTerminalGUI.cpp)
#Aqui está indicado aonde estarão os arquivos .hpp do projeto, não é necessário mudar
target_include_directories(sistema_provas 
    PUBLIC ${PROJECT_SOURCE_DIR}/include/)