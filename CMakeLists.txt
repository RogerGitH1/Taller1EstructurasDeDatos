cmake_minimum_required(VERSION 3.26)

project(Taller1EstructurasDeDatos)

set(CMAKE_CXX_STANDARD 20)

# Busca todos los .cpp dentro de src/ y subcarpetas
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(taller1 ${SOURCES})

//prueba comit