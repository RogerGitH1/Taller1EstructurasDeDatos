
#ifndef TALLER1ESTRUCTURASDEDATOS_ALUMNO_H
#define TALLER1ESTRUCTURASDEDATOS_ALUMNO_H

#include <string>
#include "LinkedList.h"
#include "Curso.h"

class Alumno {
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;
    LinkedList<Curso> cursos;
public:
    Alumno();
    Alumno(int id, std::string nombre, std::string apellido, std::string carrera,std::string fechaIngreso);
    int getId() const;
    const std::string& getNombre() const;
    const std::string& getApellido() const;
    const std::string& getCarrera() const;
    const std::string& getFechaIngreso() const;
    void mostrarInformacion() const;
    void añadirCurso(const Curso& curso);
};

#endif //TALLER1ESTRUCTURASDEDATOS_ALUMNO_H