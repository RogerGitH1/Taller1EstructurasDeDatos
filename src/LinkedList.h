#ifndef TALLER1ESTRUCTURASDEDATOS_INSCRIPCION_H
#define TALLER1ESTRUCTURASDEDATOS_INSCRIPCION_H

#include "Nodo.h"
#include <string>

template <typename T>
class LinkedList {
    Nodo<T>* cabeza;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;

    void agregarNodo(const T& objeto);

    bool idExiste(int idBuscado) const;
    T getObjeto(int idBuscado) const;
    T* getObjetoPtr(int idBuscado);
    const T* getObjetoPtr(int idBuscado) const;

    void mostrarInformacion(int idBuscado, const std::string& nombreBuscado) const;
    void eliminarNodo(int idBuscado);
};

template<typename T>
LinkedList<T>::LinkedList() : cabeza(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (cabeza) {
        Nodo<T>* siguiente = cabeza->getSiguiente();
        delete cabeza;
        cabeza = siguiente;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return cabeza == nullptr;
}

template<typename T>
void LinkedList<T>::agregarNodo(const T& objeto) {
    auto* nuevo = new Nodo<T>();
    nuevo->setObjeto(objeto);
    nuevo->setSiguiente(nullptr);

    if (!cabeza) {
        cabeza = nuevo;
        return;
    }
    Nodo<T>* actual = cabeza;
    while (actual->getSiguiente()) actual = actual->getSiguiente();
    actual->setSiguiente(nuevo);
}

template<typename T>
bool LinkedList<T>::idExiste(int idBuscado) const {
    const Nodo<T>* actual = cabeza;
    while (actual) {
        if (actual->getObjeto()->getId() == idBuscado) return true;
        actual = actual->getSiguiente();
    }
    return false;
}

template<typename T>
T LinkedList<T>::getObjeto(int idBuscado) const {
    const Nodo<T>* actual = cabeza;
    while (actual) {
        if (actual->getObjeto()->getId() == idBuscado) {
            return *(actual->getObjeto()); // copia
        }
        actual = actual->getSiguiente();
    }
    return T();
}

template<typename T>
T* LinkedList<T>::getObjetoPtr(int idBuscado) {
    Nodo<T>* actual = cabeza;
    while (actual) {
        T* obj = actual->getObjeto();
        if (obj && obj->getId() == idBuscado) return obj;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

template<typename T>
const T* LinkedList<T>::getObjetoPtr(int idBuscado) const {
    const Nodo<T>* actual = cabeza;
    while (actual) {
        const T* obj = actual->getObjeto();
        if (obj && obj->getId() == idBuscado) return obj;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::mostrarInformacion(int idBuscado, const std::string& nombreBuscado) const {
    const Nodo<T>* actual = cabeza;
    while (actual) {
        const T* obj = actual->getObjeto();
        if (obj && (obj->getId() == idBuscado || obj->getNombre() == nombreBuscado)) {
            obj->mostrarInformacion();
        }
        actual = actual->getSiguiente();
    }
}

template<typename T>
void LinkedList<T>::eliminarNodo(int idBuscado) {
    Nodo<T>* ant = nullptr;
    Nodo<T>* actual = cabeza;

    while (actual) {
        T* obj = actual->getObjeto();
        if (obj && obj->getId() == idBuscado) {
            if (!ant) {
                cabeza = actual->getSiguiente();
            } else {
                ant->setSiguiente(actual->getSiguiente());
            }
            delete actual;
            return;
        }
        ant = actual;
        actual = actual->getSiguiente();
    }
}

#endif // TALLER1ESTRUCTURASDEDATOS_INSCRIPCION_H