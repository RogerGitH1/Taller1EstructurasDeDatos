#include "Nodo.h"

template<typename T> Nodo<T>::Nodo(): siguiente(nullptr){
}

template<typename T> void Nodo<T>::setObjeto(const T& objeto) {
    this->objeto = objeto;
}

template<typename T> void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

template<typename T> T* Nodo<T>::getObjeto() {
    return &objeto;
}

template<typename T> const T* Nodo<T>::getObjeto() const {
    return &objeto;
}

template<typename T> Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

template<typename T> const Nodo<T>* Nodo<T>::getSiguiente() const {
    return siguiente;
}

#include "Alumno.h"
#include "Curso.h"
template class Nodo<Alumno>;
template class Nodo<Curso>;
