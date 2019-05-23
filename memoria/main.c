#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "funciones.h"
int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    int auxEstado;
    float auxPeso;
    char* auxNombre[50];

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Emp_setNombre(pArrayEmpleado[indiceActual],"Juan"))
        {

            Emp_getNombre(pArrayEmpleado[indiceActual], auxNombre);
            printf("\n El nombre es %s",auxNombre);
        }

       if(!Emp_setPeso(pArrayEmpleado[indiceActual],80))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual], &auxPeso);
            printf("\n El peso es %.2f",auxPeso);
        }

        if(!Emp_setEstado(pArrayEmpleado[indiceActual],1))
        {
            Emp_getEstado(pArrayEmpleado[indiceActual], &auxEstado);
            printf("\n El estado es %d",auxEstado);
        }

    }


    return 0;
}
