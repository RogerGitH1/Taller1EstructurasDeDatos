
#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H

#include <string>

class Curso {
private:
    int id_;
    std::string nombre_;
    int maxEstudiantes_;
    std::string carrera_;
    std::string profesor_;

public:
    Curso();
    Curso(int id, const std::string& nombre, int maxEstudiantes,
    const std::string& carrera, const std::string& profesor);

    int getId() const;
    const std::string& getNombre() const;
    int getMaxEstudiantes() const;
    const std::string& getCarrera() const;
    const std::string& getProfesor() const;

    void setNombre(const std::string& nombre);
    void setMaxEstudiantes(int maxEstudiantes);
    void setCarrera(const std::string& carrera);
    void setProfesor(const std::string& profesor);

    //Funciones para validar algunas caracteristicas
    static bool esIdValido(int id){ return id > 0; }
    static bool esMaxValido(int maxE){ return maxE > 0; }
    static bool esTextoValido(const std::string& s) { return !s.empty(); }

    // Muestra en consola todos los datos del curso
    void mostrarInformacion() const;
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_CURSO_H