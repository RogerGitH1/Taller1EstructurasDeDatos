#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_LINKEDLIST_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_LINKEDLIST_H

#include "Nodo.h"
#include <string>

template <typename T>
class LinkedList {
    Nodo<T> *cabeza;

public:
    LinkedList();
    void agregarNodo(const T& objeto);
    bool idExiste(int idBuscado) const;
    T getObjeto(int idBuscado) const;
    void mostrarInformacion(int idBuscado, const std::string& nombreBuscado) const;
    void eliminarNodo(int id);
    bool isEmpty() const;
    ~LinkedList();
};

#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_LINKEDLIST_H