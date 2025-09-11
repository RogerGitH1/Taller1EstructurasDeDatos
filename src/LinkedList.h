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

    // Agrega un nuevo nodo al final con una copia del objeto
    void agregarNodo(const T& objeto);

    // Indica si existe un elemento con ese id
    bool idExiste(int idBuscado) const;

    // Devuelve una COPIA del objeto por id
    T getObjeto(int idBuscado) const;

    // Devuelve una COPIA del objeto por id
    T* getObjetoPtr(int idBuscado);
    const T* getObjetoPtr(int idBuscado) const;

    // Muestra información del objeto si coincide por id o por nombre
    void mostrarInformacion(int idBuscado, const std::string& nombreBuscado) const;

    // Elimina el Nodo que tenga el Id
    void eliminarNodo(int idBuscado);

    // Recorre todos los elementos de la lista aplicando una funcion a cada uno
    template<typename Funcion>
    void recorrer(Funcion funcion);

    // Recorre todos los elementos de la lista aplicando una funcion a cada uno / const
    template<typename Funcion>
    void recorrer(Funcion funcion) const;

    // Busca el primer elemento que cumpla el predicado y devuelve puntero
    template<typename FunBool>
    T* buscarSi(FunBool funbool);

    // Busca el primer elemento que cumpla el predicado y devuelve puntero/const
    template<typename FunBool>
    const T* buscarSi(FunBool funbool) const;

    // Elimina el primer elemento que cumpla la condicion
    template<typename FunBool>
    bool eliminarSi(FunBool funbool);

    // Vacía por completo la lista liberando memoria
    void limpiar();

    // Indica si existe algún elemento con la carrera indicada
    bool carreraExiste(const std::string carreraBuscada) const;

    // Imprime todos los alumnos de una carrera
    void obtenerAlumnosCarrera(const std::string carreraBuscada) const;
    void imprimirLista() const;
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
    while (actual->getSiguiente()) {
        actual = actual->getSiguiente();
    }
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

template<typename T>
template<typename Funcion>
void LinkedList<T>::recorrer(Funcion funcion) {
    Nodo<T>* actual = cabeza;
    while (actual) {
        T* obj = actual->getObjeto();
        if (obj) {
            funcion(*obj);
        }
        actual = actual->getSiguiente();
    }
}

template<typename T>
template<typename Funcion>
void LinkedList<T>::recorrer(Funcion funcion) const{
    Nodo<T>* actual = cabeza;
    while (actual) {
        const T* obj = actual->getObjeto();
        if (obj) funcion(*obj);
        actual = actual->getSiguiente();
    }
}

template<typename T>
template<typename FunBool>
T* LinkedList<T>::buscarSi(FunBool funbool) {
    Nodo<T>* actual = cabeza;
    while (actual) {
        T* obj = actual->getObjeto();
        if (obj && funbool(*obj)) return obj;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

template<typename T>
template<typename FunBool>
const T* LinkedList<T>::buscarSi(FunBool funbool) const{
    const Nodo<T>* actual = cabeza;
    while (actual) {
        const T* obj = actual->getObjeto();
        if (obj && funbool(*obj)) return obj;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

template<typename T>
template<typename FunBool>
bool LinkedList<T>::eliminarSi(FunBool funbool) {
    Nodo<T>* ant = nullptr;
    Nodo<T>* actual = cabeza;
    while (actual) {
        T* obj = actual->getObjeto();
        if (obj && funbool(*obj)) {
            if (!ant) cabeza = actual->getSiguiente();
            else ant->setSiguiente(actual->getSiguiente());
            delete actual;
            return true;
        }
        ant = actual;
        actual = actual->getSiguiente();
    }
    return false;
}

template<typename T>
void LinkedList<T>::limpiar() {
    while (cabeza) {
        Nodo<T>* siguiente = cabeza->getSiguiente();
        delete cabeza;
        cabeza = siguiente;
    }
}

//Metodos reportes
template<typename T>
bool LinkedList<T>::carreraExiste(std::string carreraBuscada) const {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        const T* objeto = actual->getObjeto();
        if (objeto && objeto->getCarrera() == carreraBuscada) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;

}

template<typename T>
void LinkedList<T>::obtenerAlumnosCarrera(std::string carreraBuscada) const {
    const Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        const T* objeto = actual->getObjeto();
        if (objeto != nullptr && objeto->getCarrera() == carreraBuscada) {
            objeto->mostrarInformacion();
        }
        actual = actual->getSiguiente();
    }
}

template<typename T>
void LinkedList<T>::imprimirLista() const {
    const Nodo<T>* actual = cabeza;

    while (actual != nullptr) {
        const T* objeto = actual->getObjeto();
        objeto -> mostrarInformacion();
        actual = actual->getSiguiente();
    }
}

#endif //TALLER1ESTRUCTURASDEDATOS_LINKEDLIST_H