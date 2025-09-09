
#ifndef TALLER1ESTRUCTURASDEDATOS_NODO_H
#define TALLER1ESTRUCTURASDEDATOS_NODO_H

template <typename T>

class Nodo{
private:
    T objeto;
    Nodo<T>* siguiente;
public:
    Nodo() : siguiente(nullptr) {}
    T* getObjeto() { return &objeto; }
    const T* getObjeto() const {return &objeto; }
    Nodo<T>* getSiguiente() { return siguiente; }
    const Nodo<T>* getSiguiente() const { return siguiente; }
    void setObjeto(const T& obj) { objeto = obj; }
    void setSiguiente(Nodo<T>* siguiente) { siguiente = siguiente;}
};
#endif //TALLER1ESTRUCTURASDEDATOS_NODO_H