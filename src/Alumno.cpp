
#include "Alumno.h"

#include <iostream>

Alumno::Alumno(int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso) {
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

void Alumno::mostrarInformacion() {
    std::cout << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << " Carrera: " << carrera << std::endl;
    std::cout << " Fecha: " << fechaIngreso  << std::endl;
}

int Alumno::getId() {
    return  id;
}
std::string Alumno::getNombre() {
    return nombre;
}
std::string Alumno::getApellido() {
    return apellido;
}
std::string Alumno::getCarrera() {
    return carrera;
}
std::string Alumno::getFechaIngreso() {
    return fechaIngreso;
}