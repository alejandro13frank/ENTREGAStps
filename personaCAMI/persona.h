#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
}Persona;

Persona* per_new(void);
void Per_inicializarIdInicial(int val);
Persona* per_newParametros(int id, char* nombre, char* apellido, int edad);
int Per_buscarLibre(Persona* array[], int size, int* posicion);
int Per_inicializar(Persona* array[], int size);
int Per_alta(Persona* array[], int size);
int Per_getId(Persona* this, int* resultado);
int Per_setId(Persona* this, int id);
int Per_setNombre(Persona* this, char* nombre);
int Per_getNombre(Persona* this, char* resultado);
int Per_setApellido(Persona* this, char* apellido);
int Per_getApellido(Persona* this, char* resultado);
int Per_setEdad(Persona* this, int edad);
int Per_getEdad(Persona* this, int* resultado);
int Per_delete(Persona* this);


#endif
