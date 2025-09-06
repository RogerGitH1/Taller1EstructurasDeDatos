#ifndef TALLERES_ESTRUCTURAS_DE_DATOS21_INSCRIPCION_H
#define TALLERES_ESTRUCTURAS_DE_DATOS21_INSCRIPCION_H

#include "Nota.h"
#include <cstddef>

class Curso;

#include "../lists/ListaNotas.h"

class Inscripcion {
private:
    int idAlumno_ = 0;
    int codigoCurso_ = 0;
    Curso* cursoRef_= nullptr;

public:
    ListaNotas notas;

    Inscripcion();
    Inscripcion(int idAlumno, int codigoCurso, Curso* curso= nullptr);

    int idAlumno() const { return idAlumno_; }
    int codigoCurso() const { return codigoCurso_; }
    Curso* cursoRef() const { return cursoRef_; }
    void setCursoRef(Curso* curso) { cursoRef_ = curso; }

    bool igualLlave(int idAlu, int codCurso) const {
        return idAlumno_ == idAlu && codigoCurso_ == codCurso;
    }
};
#endif //TALLERES_ESTRUCTURAS_DE_DATOS21_INSCRIPCION_H