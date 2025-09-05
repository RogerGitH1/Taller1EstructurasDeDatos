
#ifndef TALLER1ESTRUCTURASDEDATOS_NODO_H
#define TALLER1ESTRUCTURASDEDATOS_NODO_H
#include "Alumno.h"

class Nodo {
private:
    Alumno alumno;
    Nodo* siguiente;
public:
    Nodo();
    void setAlumno(Alumno alumno);
    void setSiguiente(Nodo* siguiente);
    Alumno* getAlumno();
    Nodo* getSiguiente();
};

#endif //TALLER1ESTRUCTURASDEDATOS_NODO_H