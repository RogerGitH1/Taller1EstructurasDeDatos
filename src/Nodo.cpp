#include "Nodo.h"

Nodo::Nodo(): siguiente(nullptr){
}

void Nodo::setAlumno(Alumno alumno) {
    this->alumno = alumno;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Alumno* Nodo::getAlumno() {
    return &alumno;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

