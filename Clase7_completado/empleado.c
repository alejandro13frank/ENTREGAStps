#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "utn.h"

int empleado_InicializarArray(Empleado arrayEmpleados[],int tamArray)
{
    int i;
    int ret = -1;
    if ((arrayEmpleados!=NULL) && (tamArray>0))
    {
        for (i=0;i<tamArray;i++)
        {
            arrayEmpleados[i].isEmpty = 1;
        }
        ret =0;

    }
    return ret;
}

int empleado_MostrarArray(Empleado arrayEmpleados[],int tamArray)
{
    int i;
    int ret=-1;
    if ((arrayEmpleados!=NULL) && (tamArray>0))
    {
        for (i=0;i<tamArray;i++)
        {
            if (!arrayEmpleados[i].isEmpty)
            {
                printf("\nEsta ocupado en posicion %d",i);
                printf("\nnombre: %s",arrayEmpleados[i].nombre);
                printf("\napellido: %s",arrayEmpleados[i].apellido);
            } else{
                printf("\nEsta vacio en posicion %d",i);
            }
        }
        ret =0;

    }
    return ret;
}
int empleado_BuscarLibre(Empleado arrayEmpleados[],int tamArray, int *posicionLibre)
{
    int i;
    int ret = -1;
    if ((arrayEmpleados!=NULL) && (tamArray>0))
    {
        for (i=0;i<tamArray;i++)
        {
            if (arrayEmpleados[i].isEmpty)
            {
                *posicionLibre = i;
                ret = 0;
                break;
            }
        }
    }
    return ret;
}
int empleado_Alta(Empleado arrayEmpleados[],int tamArray, int id)
{
    int ret=-1;
    Empleado empleadoNuevo;
    int posicionLibre;
    if ((arrayEmpleados!=NULL) && (tamArray>0))
    {
        if (!empleado_BuscarLibre(arrayEmpleados,tamArray,&posicionLibre))
        {
            utn_getString(empleadoNuevo.nombre,"\nIngrese nombre de empleado: ","\nReintente, error.",1,20,3);
            utn_getString(empleadoNuevo.apellido,"\nIngrese apellido de empleado: ","\nReintente, error.",1,20,3);
            empleadoNuevo.isEmpty = 0;
            empleadoNuevo.idEmpleado = id;
            arrayEmpleados[posicionLibre] = empleadoNuevo;
            ret = 0;
        }else{
            printf("No se pudo encontrar una pisicion libre");
        }
    }
    return ret;
}
