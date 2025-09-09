
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H
#include <iostream>

struct Nota {
    int cursoId = 0;
    float valor = 1.0f;

    Nota() = default;

    explicit Nota(float v) : valor(v) {}

    Nota(int curId, float val) : cursoId(curId), valor(val) {}

    float getValor() const { return valor; }
    int getCursoId() const { return cursoId; }
    void imprimir() const { std::cout << cursoId << ": " << valor << '\n'; }
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H