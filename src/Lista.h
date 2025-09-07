
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_LISTA_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_LISTA_H

#include <cstddef>
#include <functional>

using  std::size_t;
using std::function;

template <typename T>

struct Nodo {
    T data;
    Nodo<T>* next;
    explicit Nodo(const T& data_):data(data_), next(nullptr) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* cabeza; nullptr;
    Nodo<T>* cola; nullptr;
    size_t n = 0;

public:
    Lista() = default;
    ~Lista() {clear(); }

    bool empty() const {return n == 0;}
    size_t size() const {return n;}

    void push_back(const T& valor) {
        Nodo<T>* nn = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = cola = nn;
        } else {
            cola -> next = nn;
            cola = nn;
        }
        ++n;
    }

    bool push_unique(const T& value, function<bool(const T&, const T&)> same) {
        for (Nodo<T>* c = cabeza; c; c = c -> next) {
            if (same(value, c->data)) return false;
        }
        push_back(value);
        return true;
    }

    T* findIf(function<bool(const T&)> pred) {
        for (Nodo<T>* c = cabeza; c; c = c -> next) {
            if (pred(c-> data)) return &c-> data;
        }
        return nullptr;
    }

    bool eraseIf(function<bool(const T&)> pred) {
        Nodo<T>* prev = nullptr;
        Nodo<T>* cur = cabeza;
        while (cur) {
            if (pred(cur->data)) {
                if (!prev) cabeza = cur->next;
                else prev->next = cur->next;
                if (cur == cola) cola = prev;
                delete cur;
                --n;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    size_t eraseAllIf(function<bool(const T&)> pred) {
        size_t removed = 0;
        Nodo<T>* prev = nullptr;
        Nodo<T>* cur = cabeza;
        while (cur) {
            if (pred(cur->data)) {
                Nodo<T>* del = cur;
                if (!prev) cabeza = cur->next;
                else prev->next = cur->next;
                if (del == cola) cola = prev;
                cur = cur->next;
                delete del;
                ++removed;
                --n;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return removed;
    }

    void forEach(function<void(T&)> fn) {
        for (Nodo<T>* c = cabeza; c; c = c->next) fn(c->data);
    }

    void clear() {
        Nodo<T>* c = cabeza;
        while (c) {
            Nodo<T>* nx = c->next;
            delete c;
            c = nx;
        }
        cabeza = cola = nullptr;
        n = 0;
    }
};

#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_LISTA_H