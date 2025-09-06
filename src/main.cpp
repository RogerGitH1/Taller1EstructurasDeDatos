#include <iostream>
#include <string>
#include <limits>

#include "Alumno.h"
#include "LinkedList.h"


using namespace std;
LinkedList linkedList;

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
    if (!linkedList.idExiste(id)) {
        Alumno alumno(id,nombre,apellido,carrera,fechaIngreso);
        linkedList.agregarNodo(alumno);
        cout << "Alumno agregado correctamente " << endl;
        return;
    }
    cout << "El id: " << id << " ya existe " << endl;
}

void buscarAlumno() {
    cout << "BUSCAR ALUMNO" << endl;
    int id = leerInt("Ingrese Id: ");
}

void eliminarAlumno() {
    cout << "ELIMINAR ALUMNO" << endl;
    int id = leerInt("Ingrese Id: ");

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