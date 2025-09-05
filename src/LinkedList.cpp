
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList():cabeza(nullptr) {}

void LinkedList::agregarNodo(Alumno alumno) {
    Nodo* nuevo = new Nodo();
    nuevo->setAlumno(alumno);
    nuevo->setSiguiente(nullptr);

    if (cabeza == nullptr) {
        cabeza = nuevo;
    }
    else {
        Nodo* actual = cabeza;
        while (actual->getSiguiente()) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

LinkedList::~LinkedList(){
    if (!cabeza) {
        std::cout << "No hay ningun elemento en la lista" << std::endl;
        return;
    }

    while (cabeza) {
        Nodo* actual = cabeza->getSiguiente();
        delete cabeza;
        cabeza = actual;
    }
}
