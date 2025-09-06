
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H

struct Nota {
    float valor = 0.0f;
    static bool esValida(float valor) { return v >= 1.0f && valor <= 7.0f; }
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H