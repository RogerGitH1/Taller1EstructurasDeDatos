#ifndef TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H
#define TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H
#include "Nodo.h"

class LinkedList {
    Nodo *cabeza;
public:
    LinkedList();
    void agregarNodo(Alumno alumno);
    //void eliminarNodo(Alumno alumno);
    ~LinkedList();
};


#endif //TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H