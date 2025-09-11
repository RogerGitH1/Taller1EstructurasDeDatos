
#ifndef TALLER1ESTRUCTURASDEDATOS_ALUMNO_H
#define TALLER1ESTRUCTURASDEDATOS_ALUMNO_H

#include <string>
#include "LinkedList.h"
#include "Curso.h"
#include "Nota.h"

class Alumno {
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;
    LinkedList<Curso> cursos;
    LinkedList<Nota> notas;

public:
    Alumno();
    Alumno(int id, std::string nombre, std::string apellido, std::string carrera,std::string fechaIngreso);
    int getId() const;
    const std::string& getNombre() const;
    const std::string& getApellido() const;
    const std::string& getCarrera() const;
    const std::string& getFechaIngreso() const;

    //Muestra en consola toda la información del alumno
    void mostrarInformacion() const;

    // Inscribe al alumno en un curso y agrega el curso a una lista del alumno
    void anadirCurso(const Curso& curso);

    // Indica si el alumno está inscrito en un curso usando el id
    bool estaInscritoEn(int idCurso) const;

    // Registra una nueva nota para un curso específico
    void agregarNota(int cursoId, float nota);

    // Calcula el promedio del alumno en un curso específico, mediante el id del curso
    float promedioEnCurso(int cursoId) const;

    // Imprime todas las notas del alumno para un curso específico
    void imprimirNotasCurso(int cursoId) const;

    // Elimina la inscripción del curso y sus notas, de este alumno
    void eliminarCurso(int cursoId);

    // Elimina todas las notas del curso indicado
    void eliminarNotasCurso(int cursoId);

    // Imprime la lista de cursos en los que el alumno está inscrito
    void imprimirCursosInscritos() const;

    // Indica si el alumno tiene al menos un curso inscrito
    bool tieneCursosInscritos() const;

    // Indica si el alumno tiene al menos una nota registrada
    bool tieneNotas() const;

    // Calcula el promedio general del alumno, usando el promedio de cada curso
    float promedioGeneral() const;
};

#endif //TALLER1ESTRUCTURASDEDATOS_ALUMNO_H