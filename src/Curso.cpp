
#include "Curso.h"
#include <iostream>

Curso::Curso()
    : id_(-1), nombre_(), maxEstudiantes_(0), carrera_(), profesor_() {}

Curso::Curso(int id,const std::string& nombre,int maxEstudiantes,const std::string& carrera,const std::string& profesor):
      id_(id),
      nombre_(nombre),
      maxEstudiantes_(maxEstudiantes),
      carrera_(carrera),
      profesor_(profesor) {}

int  Curso::getId() const                 { return id_; }
const std::string& Curso::getNombre() const   { return nombre_; }
int  Curso::getMaxEstudiantes() const     { return maxEstudiantes_; }
const std::string& Curso::getCarrera() const  { return carrera_; }
const std::string& Curso::getProfesor() const { return profesor_; }

void Curso::setNombre(const std::string& nombre){ nombre_ = nombre; }
void Curso::setMaxEstudiantes(int maxEstudiantes){ if (maxEstudiantes > 0) maxEstudiantes_ = maxEstudiantes; }
void Curso::setCarrera(const std::string& carrera){ carrera_ = carrera; }
void Curso::setProfesor(const std::string& profesor){ profesor_ = profesor; }

void Curso::mostrarInformacion() const{
    std::cout << "Id: " << id_ << std::endl;
    std::cout << "Nombre: " << nombre_ << std::endl;
    std::cout << "Maximo Estudiantes: " << maxEstudiantes_ << std::endl;
    std::cout << "Carrera: " << carrera_ << std::endl;
    std::cout << "Profesor: " << profesor_  << std::endl;
    std::cout << std::endl;
}