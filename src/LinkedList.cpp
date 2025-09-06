
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList():cabeza(nullptr) {}

void LinkedList::agregarNodo(const Alumno& alumno) {
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
    while (cabeza) {
        Nodo* actual = cabeza->getSiguiente();
        delete cabeza;
        cabeza = actual;
    }
}

bool LinkedList::idExiste(int idBuscado) {
    Nodo* actual = cabeza;

    while (actual) {
        if (actual ->getAlumno()->getId() == idBuscado){
        return true;
        }
        actual = actual->getSiguiente();
    }
    return  false;
}

Alumno LinkedList::getAlumno(int idBuscado) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->getAlumno()->getId() == idBuscado) {
            return *(actual->getAlumno());
        }
        actual = actual->getSiguiente();
    }
    return Alumno();
}

void LinkedList::mostrarInformacion(int idBuscado, std::string nombreBuscado) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->getAlumno()->getId() == idBuscado || actual -> getAlumno()->getNombre() == nombreBuscado) {
            actual -> getAlumno()->mostrarInformacion();
        }
        actual = actual->getSiguiente();
    }

}

void LinkedList::eliminarNodo(int idBuscado) {
    Nodo* ant = nullptr;
    Nodo* actual = cabeza;
    while (actual) {
        if (actual -> getAlumno()->getId() == idBuscado) {
            if (!ant) {
                cabeza = actual ->getSiguiente();
            }
            else {
                ant->setSiguiente(actual->getSiguiente());
            }

            delete actual;
            return;
        }
        ant = actual;
        actual = actual->getSiguiente();
    }
}

bool LinkedList::isEmpty() {
    if (cabeza == nullptr) {
        return true;
    }
    return  false;
}