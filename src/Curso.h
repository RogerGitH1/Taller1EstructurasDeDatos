
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H

#include <string>
using namespace std;

class Curso {
private:
    int codigo_;
    string nombre_;
    int maxEstudiantes_;
    string carrera_;
    string profesor_;

public:
    Curso();
    Curso(int codigo, const string& nombre, int maxEstudiantes, const string carrera, const string& profesor);

    int codigo() const;
    const string& nombre() const;
    int maxEstudiantes() const;
    const string& carrera() const;
    const string& profesor() const;

    void setNombre(const string& nombre);
    void setMaxEstudiantes(int maxEstudiantes);
    void setCarrera(const string& carrera);
    void setProfesor(const string& profesor);

    static bool esCodigoValido(int codigo){ return codigo >0; }
    static bool esProfesorValido(const string& profesor){ return maxE >0;}

    void imprimir() const;
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H