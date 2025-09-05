
#include "Curso.h"
#include <iostream>

Curso::Curso(): codigo_(0), nombre_(""), maxEstudiantes_(0), carrera_(""), profesor_("") {}

Curso::Curso(int codigo, const string& nombre, int maxEstudiantes, const string& carrera, const string& profesor):
codigo_(codigo), nombre_(nombre), maxEstudiantes_(maxEstudiantes), carrera_(carrera), profesor_(profesor) {}

int Curso::codigo() const { return codigo_; }
const string& Curso::nombre() const { return nombre_; }
int Curso::maxEstudiantes() const { return maxEstudiantes_; }
const string& Curso::carrera() const { return carrera_; }
const string& Curso::profesor() const { return profesor_; }

void Curso::setNombre(const string& nombre) { nombre_ = nombre; }
void Curso::setMaxEstudiantes(int max) { if (max>0) maxExtudiantes_=max;}
void Curso::setCarrera(const string& carr) { carrera_ = carr; }
void Curso::setProfesor(const string& prof) { profesor_ = prof; }

void Curso::imprimir() const {
    cout << "-Curso " << codigo_ << "- " << nombre_ << " | Carrera: " << carrera_ << " | Profeso: " << profesor_ << " | Cupo: " << maxEstudiantes_ << "\n";
}