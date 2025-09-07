
#include "Alumno.h"
#include <iostream>

Alumno::Alumno(): id(-1){}

Alumno::Alumno(int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso) {
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

void Alumno::mostrarInformacion() const{
    std::cout << "Id: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << " Carrera: " << carrera << std::endl;
    std::cout << " Fecha: " << fechaIngreso  << std::endl;
    std::cout << std::endl;
}

void Alumno::añadirCurso(const Curso& curso) {
    cursos.agregarNodo(curso);
}
int Alumno::getId() const{
    return  id;
}
const std::string& Alumno::getNombre() const  {
    return nombre;
}
const std::string& Alumno::getApellido() const {
    return apellido;
}
const std::string& Alumno::getCarrera()const  {
    return carrera;
}
const std::string& Alumno::getFechaIngreso()const  {
    return fechaIngreso;
}