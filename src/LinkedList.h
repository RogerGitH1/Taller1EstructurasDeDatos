#ifndef TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H
#define TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H
#include "Nodo.h"

class LinkedList {
    Nodo *cabeza;
public:
    LinkedList();
    void agregarNodo(const Alumno& alumno);
    bool idExiste(int idBuscado);
    Alumno getAlumno(int idBuscado);
    void mostrarInformacion(int idBuscado, std::string nombreBuscado);
    void eliminarNodo(int id);
    bool isEmpty();
    ~LinkedList();
};

#endif //TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H