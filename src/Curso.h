
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H

#include <string>
using namespace std;

class Curso {
private:
    int id_;
    string nombre_;
    int maxEstudiantes_;
    string carrera_;
    string profesor_;

public:
    Curso();
    Curso(int id, const string& nombre, int maxEstudiantes, const string& carrera, const string& profesor);

    int getId() const;
    const string& getNombre() const;
    int getMaxEstudiantes() const;
    const string& getCarrera() const;
    const string& getProfesor() const;

    void setNombre(const string& nombre);
    void setMaxEstudiantes(int maxEstudiantes);
    void setCarrera(const string& carrera);
    void setProfesor(const string& profesor);

    static bool esCodigoValido(int codigo){ return codigo >0; }
    static bool esMaxValido(int maxE) { return maxE > 0; }
    static bool esProfesorValido(const string& profesor) { return !profesor.empty(); }

    void mostrarInformacion() const;
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H