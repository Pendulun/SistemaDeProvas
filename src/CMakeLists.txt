# CMakeList.txt : CMake project for SistemaDeProvasCPP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SistemaDeProvasCPP "SistemaDeProvasCPP.cpp" "SistemaDeProvasCPP.h" "DAO/AlunoDAO.cpp" "DAO/Headers/AlunoDAO.h" "DAO/Headers/BaseDAO.h" "Modelo/Aluno.cpp" "Modelo/Materia.cpp" "DAO/Headers/MateriaDAO.h" "Modelo/Professor.cpp" "Modelo/ProvaDaMateria.cpp" "Modelo/Alternativa.cpp" "Modelo/ProvaResolvida.cpp" "Modelo/Questao.cpp")

# TODO: Add tests and install targets if needed.
