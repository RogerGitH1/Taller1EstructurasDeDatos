
#include "Curso.h"
#include <iostream>

Curso::Curso(): id_(0), nombre_(""), maxEstudiantes_(0), carrera_(""), profesor_("") {}

Curso::Curso(int id, const string& nombre, int maxEstudiantes, const string& carrera, const string& profesor):
id_(id), nombre_(nombre), maxEstudiantes_(maxEstudiantes), carrera_(carrera), profesor_(profesor) {}

int Curso::getId() const { return id_; }
const string& Curso::getNombre() const { return nombre_; }
int Curso::getMaxEstudiantes() const { return maxEstudiantes_;}
const string& Curso::getCarrera() const { return carrera_; }
//const string& Curso::profesor() const { return profesor_; }

void Curso::setNombre(const string& nombre) { nombre_ = nombre; }
void Curso::setMaxEstudiantes(int max) { if (max>0) maxEstudiantes_=max;}
void Curso::setCarrera(const string& carr) { carrera_ = carr; }
void Curso::setProfesor(const string& prof) { profesor_ = prof; }

void Curso::mostrarInformacion() const {
    cout << "-Curso " << id_ << "- " << nombre_ << " | Carrera: " << carrera_ << " | Profeso: " << profesor_ << " | Cupo: " << maxEstudiantes_ << "\n";
}