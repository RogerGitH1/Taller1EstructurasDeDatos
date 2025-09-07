
#ifndef TALLER1ESTRUCTURASDEDATOS_NODO_H
#define TALLER1ESTRUCTURASDEDATOS_NODO_H

template <typename T>

class Nodo{
private:
    T objeto;
    Nodo<T>* siguiente;
public:
    Nodo();
    void setObjeto(const T& objeto);
    void setSiguiente(Nodo<T>* siguiente);
    T* getObjeto();
    const T* getObjeto() const;
    Nodo<T>* getSiguiente();
};

#endif //TALLER1ESTRUCTURASDEDATOS_NODO_H