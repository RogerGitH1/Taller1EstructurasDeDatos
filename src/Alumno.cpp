
#include "Alumno.h"
#include <iostream>

Alumno::Alumno(): id(-1){}

Alumno::Alumno(int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso) {
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

void Alumno::mostrarInformacion() const{
    std::cout << "Id: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << " Carrera: " << carrera << std::endl;
    std::cout << " Fecha: " << fechaIngreso  << std::endl;
    std::cout << std::endl;
}

void Alumno::anadirCurso(const Curso& curso) {
    cursos.agregarNodo(curso);
}
int Alumno::getId() const{
    return  id;
}
const std::string& Alumno::getNombre() const  {
    return nombre;
}
const std::string& Alumno::getApellido() const {
    return apellido;
}
const std::string& Alumno::getCarrera()const  {
    return carrera;
}
const std::string& Alumno::getFechaIngreso()const  {
    return fechaIngreso;
}
bool Alumno::estaInscritoEn(int idCurso) const {
    return cursos.idExiste(idCurso);
}
void Alumno::agregarNota(int cursoId, float nota) {
    notas.agregarNodo( Nota(cursoId, nota));
}

float Alumno::promedioEnCurso(int cursoId) const {
    float suma =0.0f; int contador = 0;
    notas.forEach([&](const Nota& n){
        if (n.cursoId == cursoId) { suma += n.valor; ++contador; } });
    return contador? suma/contador: 0.0f;
}

void Alumno::imprimirNotasCurso(int cursoId) const {
    bool alguna =false;
    notas.forEach([&](const Nota& n){
        if (n.getCursoId() == cursoId) {n.imprimir(); alguna=true;} });
    if (!alguna) std::cout << "(sin notas)";
    std::cout << std::endl;

}

void Alumno::eliminarNotasCurso(int cursoId) {
    notas.eraseIf([&](const Nota& n) {
        return n.getCursoId() == cursoId;
    });
}

void Alumno::eliminarCurso(int cursoId) {
    cursos.eraseIf([&](const Curso& c) {
        return c.getId() == cursoId;
    });
    eliminarNotasCurso(cursoId);
}

//Metodos para reportes
void Alumno::imprimirCursosInscritos() const{
    cursos.imprimirLista();
}

bool Alumno::tieneCursosInscritos() const {
    return !cursos.isEmpty();
}



