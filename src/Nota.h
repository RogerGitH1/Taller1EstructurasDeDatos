
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H

struct Nota {
    float valor = 0.0f;
    static bool esValida(float v) { return v >= 1.0f && v <= 7.0f; }
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_NOTA_H