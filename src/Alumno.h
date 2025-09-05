
#ifndef TALLER1ESTRUCTURASDEDATOS_ALUMNO_H
#define TALLER1ESTRUCTURASDEDATOS_ALUMNO_H
#include <string>

class Alumno {
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;
    //listaCursos (implementada en futuro)
public:
    Alumno(int id, std::string nombre, std::string apellido, std::string carrera,std::string fechaIngreso);
    void mostrarInformacion();
    int getId();
    std::string getNombre();
    std::string getApellido();
    std::string getCarrera();
    std::string getFechaIngreso();
};

#endif //TALLER1ESTRUCTURASDEDATOS_ALUMNO_H