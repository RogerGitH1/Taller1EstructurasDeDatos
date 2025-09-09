#include <iostream>
#include <string>
#include <limits>
#include "Alumno.h"
#include "Curso.h"
#include "LinkedList.h"

using namespace std;

LinkedList<Alumno> alumnos;
LinkedList<Curso> cursos;

string leerString(string texto){
    cout << texto;
    string ingresado;
    cin >> ingresado;
    return ingresado;
}

int leerInt(string texto) {
    cout << texto;
    int ingresado;
    while (!(cin >> ingresado)) {
        cout << "Valor ingresado invalido" << endl;
        cout << texto;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return ingresado;
}

float leerFloat(string texto1) {
    cout << texto1;
    float ingresado1;
    while (!(cin >> ingresado1)) {
        cout << "Valor ingresado invalido" << endl;
        cout << texto1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return ingresado1;
}

void crearAlumno(){
    cout << "CREAR ALUMNO" << endl;
    int id = leerInt("Ingrese Id: ");
    string nombre = leerString("Ingrese Nombre: ");
    string apellido = leerString("Ingrese Apellido: ");
    string carrera = leerString("Ingrese Carrera: ");
    string fechaIngreso = leerString("Ingrese Fecha de ingreso (dia/mes/año): ");

    if (!alumnos.idExiste(id)) {
        Alumno alumno(id,nombre,apellido,carrera,fechaIngreso);
        alumnos.agregarNodo(alumno);
        cout << "Alumno agregado correctamente " << endl;
        return;
    }
    cout << "El id: " << id << " ya existe " << endl;
}

void buscarAlumno() {
    std::cout << "BUSCAR ALUMNO" << std::endl;
    int id = leerInt("Ingrese Id: ");
    Alumno* alumno = alumnos.getObjetoPtr(id);
    if (alumno) {
        alumnos.mostrarInformacion(alumno->getId(), alumno->getNombre());
    } else {
        std::cout << "Id: " << id << " no encontrado " << std::endl;
    }
}

void eliminarAlumno() {
    cout << "ELIMINAR ALUMNO" << endl;
    int id = leerInt("Ingrese Id: ");
    if (alumnos.idExiste(id)) {
        alumnos.eliminarNodo(id);
        cout << "El alumno con Id: " << id << " eliminado " << endl;
        return;
    }
    cout << "El id: " << id << " no existe " << endl;
}

void manejoAlumnos(){
    int opcion;
    cout << "MANEJO DE ALUMNOS" << endl;
    do{
        cout << "0. Volver al menu Principal" << endl;
        cout << "1. Crear Alumno" << endl;
        cout << "2. Buscar un alumno por ID o nombre y listar su informacion" << endl;
        cout << "3. Eliminar un alumno del sistema utilizando su ID" << endl;
        cout << "Ingresa una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
        case 1:
            crearAlumno();
            break;
        case 2:
            buscarAlumno();
            break;
        case 3:
            eliminarAlumno();
            break;
        }
    }while (opcion != 0);

}

void crearCurso(){
    cout << "CREAR CURSO" << endl;
    int id = leerInt("Ingrese Id del curso: ");
    string nombre = leerString("Ingrese Nombre del curso: ");
    int cantMaxima = leerInt("Ingrese cantidad maxima de estudiantes:  ");
    string carrera = leerString("Ingrese Carrera del curso: ");
    string profesor = leerString("Ingrese Profesor: ");

    if (!cursos.idExiste(id)) {
        Curso curso(id, nombre, cantMaxima, carrera, profesor);
        cursos.agregarNodo(curso);
        cout << "Curso agregado correctamente" << endl;
        return;
    }
    cout << "El id: " << id << " ya existe" << endl;
}

void buscarCurso() {
    std::cout << "BUSCAR CURSO" << std::endl;
    int id = leerInt("Ingrese Id del curso: ");
    Curso* curso = cursos.getObjetoPtr(id);
    if (curso) {
        cursos.mostrarInformacion(curso->getId(), curso->getNombre());
    } else {
        std::cout << "Id: " << id << " no encontrado" << std::endl;
    }
}

void eliminarCurso() {
    cout << "ELIMINAR CURSO" << endl;
    int id = leerInt("Ingrese Id del curso: ");
    if (cursos.idExiste(id)) {
        cursos.eliminarNodo(id);
        cout << "El curso con Id: " << id << " eliminado" << endl;
        return;
    }
    cout << "El id: " << id << " no existe" << endl;
}

void manejoCursos(){
    int opcion;
    cout << "MANEJO DE CURSOS" << endl;
    do{
        cout << "0. Volver al menu Principal" << endl;
        cout << "1. Crear Curso" << endl;
        cout << "2. Buscar un curso por ID o nombre y listar su informacion" << endl;
        cout << "3. Eliminar un curso del sistema utilizando su ID" << endl;
        opcion = leerInt("Ingrese una opcion: ");
        cout << endl;

        switch (opcion){
            case 1:
                crearCurso();
                break;
            case 2:
                buscarCurso();
                break;
            case 3:
                eliminarCurso();
                break;
        }
    } while (opcion != 0);
}

void inscribirAlumnoCurso() {
    cout << "INSCRIBIR UN ALUMNO EN UN CURSO " << endl;

    if (alumnos.isEmpty() || cursos.isEmpty()) {
        cout << "Debe haber minimo un curso y un alumno agregados" << endl;
        return;
    }
    const int idAlumno = leerInt("Ingrese Id del alumno que quiere inscribir curso: ");
    Alumno* alumno = alumnos.getObjetoPtr(idAlumno);
    if (!alumno) {
        cout << "El id: " << idAlumno << " no encontrado" << endl;
        return;
    }

    cout << "Alumno encontrado" << endl;
    alumno->mostrarInformacion();

    const int idCurso = leerInt("Ingrese id del curso al que desea agregar al alumno: ");
    Curso* curso = cursos.getObjetoPtr(idCurso);
    if (!curso) {
        cout << "Curso con id " << idCurso << " no encontrado" << endl;
        return;
    }

    if (curso->getCarrera() != alumno->getCarrera()) {
        cout << "Curso no válido para el alumno (carrera distinta)" << endl;
        return;
    }

    alumno->anadirCurso(*curso);
    cout << "Alumno inscrito en el curso correctamente" << endl;
}

void eliminarAlumnoCurso() {
    cout << "ELIMINAR ALUMNO EN UN CURSO " << endl;

}

void manejoInscripciones() {
    int opcion;
    cout << "MANEJO DE INSCRIPCIONES" << endl;
    do {
        cout << "0. Volver al menu Principal" << endl;
        cout << "1. Inscribir un alumno en un curso" << endl;
        cout << "2. Eliminar un alumno de un curso" << endl;
        opcion = leerInt("Ingrese una opcion: ");

        switch (opcion) {
            case 1:
                inscribirAlumnoCurso();
                break;
            case 2:
                eliminarAlumnoCurso();
                break;
        }

    }
    while (opcion != 0);

}

void asignarNotas() {
    cout << "ASIGNAR NOTA A UN ALUMNO EN UN CURSO " << endl;

    if (alumnos.isEmpty() || cursos.isEmpty()) {
        cout << "Debe haber minimo un curso y un alumno agregados" << endl;
        return;
    }
    const int idAlumno = leerInt("Ingrese Id del alumno para asignar nota: ");
    Alumno* alumno = alumnos.getObjetoPtr(idAlumno);
    if (!alumno) {
        cout << "El id: " << idAlumno << " no encontrado" << endl;
        return;
    }

    cout << "Alumno encontrado" << endl;
    alumno->mostrarInformacion();

    const int idCurso = leerInt("Ingrese id del curso al que desea agregar la nota: ");
    Curso* curso = cursos.getObjetoPtr(idCurso);
    if (!curso) {
        cout << "Curso con id " << idCurso << " no encontrado" << endl;
        return;
    }
    if (!alumno->estaInscritoEn(idCurso)) {
        cout << "El Alumno No esta inscrito en el curso" << endl;
        return;
    }

    const float nota = leerFloat("Ingrese la nota a asignar(1.0-7.0): ");
    if (nota < 1.0f || nota > 7.0) {
        cout << "La nota esta fuera del rango permitido" << endl;
        return;
    }

    alumno->agregarNota(idCurso, nota);
    cout << "Nota agregada correctamente" << endl;
}

void manejoNotas() {
    int opcion;
    cout << "MANEJO DE NOTAS" << endl;
    do {
        cout << "0. Volver al menu Principal" << endl;
        cout << "1. Asignar nota a un alumno en un curso especifico" << endl;
        opcion = leerInt("Ingrese una opcion: ");

        switch (opcion) {
            case 1:
                asignarNotas();
                break;
        }
    }
    while (opcion != 0);
}

int main(){
    int opcion;
    do{
        cout << "MENU PRINCIPAL" << endl;
        cout << "0. Cerrar Programa" << endl;
        cout << "1. Manejo de alumnos" << endl;
        cout << "2. Manejo de Cursos" << endl;
        cout << "3. Manejo de Inscripciones" << endl;
        cout << "4. Manejo de Notas" << endl;
        cout << "5. Consultas y Reportes" << endl;
        cout << "Ingresa una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
        case 1:
            manejoAlumnos();
            break;
        case 2:
            manejoCursos();
            break;
        case 3:
            manejoInscripciones();
            break;
        case 4:
            manejoNotas();
            break;
        case 5:

            break;
        }
    } while (opcion != 0);
    cout << "Cerrando Programa..." << endl;
    return 0;
}