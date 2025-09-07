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
    cout << "BUSCAR ALUMNO" << endl;
    int id = leerInt("Ingrese Id: ");
    Alumno alumno = alumnos.getObjeto(id);
    if (alumno.getId() != -1) {
        alumnos.mostrarInformacion(alumno.getId(), alumno.getNombre());
        return;
    }
    cout << "Id: " << id << " no encontrado " << endl;
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
        cout << "2. Buscar un alumno por ID o nombre y listar su información" << endl;
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
    cout << "BUSCAR CURSO" << endl;
    int id = leerInt("Ingrese Id del curso: ");
    Curso curso = cursos.getObjeto(id);
    if (curso.getId() != -1) {
        cursos.mostrarInformacion(curso.getId(), curso.getNombre());
        return;
    }
    cout << "Id: " << id << " no encontrado" << endl;
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
        cout << "2. Buscar un curso por ID o nombre y listar su información" << endl;
        cout << "3. Eliminar un curso del sistema utilizando su ID" << endl;
        opcion = leerInt("Ingrese una opción: ");
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

            break;
        case 4:

            break;
        case 5:

            break;
        }
    } while (opcion != 0);
    cout << "Cerrando Programa..." << endl;
    return 0;
}