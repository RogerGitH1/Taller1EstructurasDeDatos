#include "Inscripcion.h"

Inscripcion::Inscripcion(): idAlumno_(0), codigoCurso_(0),cursoRef_(nullptr), notas_() {}

Inscripcion::Inscripcion(int idAlumno, int codigoCurso, Curso* curso): idAlumno_(idAlumno), codigoCurso_(codigoCurso),
cursoRef_(curso), notas_() {}