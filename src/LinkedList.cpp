#include "LinkedList.h"
#include <iostream>
#include "Alumno.h"
#include "Curso.h"

template<typename T> LinkedList<T>::LinkedList() : cabeza(nullptr) {}

template<typename T> void LinkedList<T>::agregarNodo(const T& objeto) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->setObjeto(objeto);
    nuevo->setSiguiente(nullptr);

    if (cabeza == nullptr) {
        cabeza = nuevo;
    }
    else {
        Nodo<T>* actual = cabeza;
        while (actual->getSiguiente()) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

template<typename T> LinkedList<T>::~LinkedList(){
    while (cabeza) {
        Nodo<T>* actual = cabeza->getSiguiente();
        delete cabeza;
        cabeza = actual;
    }
}

template<typename T> bool LinkedList<T>::idExiste(int idBuscado) const {
    Nodo<T>* actual = cabeza;

    while (actual) {
        if (actual ->getObjeto()->getId() == idBuscado){
            return true;
        }
        actual = actual->getSiguiente();
    }
    return  false;
}

template<typename T> T LinkedList<T>::getObjeto(int idBuscado) const{
    Nodo<T>* actual = cabeza;
    while (actual) {
        if (actual->getObjeto()->getId() == idBuscado) {
            return *(actual->getObjeto());
        }
        actual = actual->getSiguiente();
    }
    return T();
}

template<typename T> void LinkedList<T>::mostrarInformacion(int idBuscado, const std::string& nombreBuscado) const{
    Nodo<T>* actual = cabeza;
    while (actual) {
        if (actual->getObjeto() -> getId() == idBuscado || actual -> getObjeto()->getNombre() == nombreBuscado) {
            actual -> getObjeto()->mostrarInformacion();
        }
        actual = actual->getSiguiente();
    }
}

template<typename T> void LinkedList<T>::eliminarNodo(int idBuscado) {
    Nodo<T>* ant = nullptr;
    Nodo<T>* actual = cabeza;
    while (actual) {
        if (actual -> getObjeto()->getId() == idBuscado) {
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

template<typename T> bool LinkedList<T>::isEmpty() const{
    if (cabeza == nullptr) {
        return true;
    }
    return  false;
}


template class LinkedList<Alumno>;
template class LinkedList<Curso>;