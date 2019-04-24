#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "utn.h"
#include <string.h>
#include <stdio_ext.h>

int empleado_InicializarArray(Empleado *arrayEmpleados,int tamArray)
{
    int i;
    int ret = -1;
    if ((arrayEmpleados!=NULL) && (tamArray>=0))
    {
        for (i=0;i<tamArray;i++)
        {
            arrayEmpleados[i].isEmpty = 1;
        }
        ret =0;

    }
    return ret;
}

int empleado_MostrarArray(Empleado *arrayEmpleados,int tamArray)
{
    int i;
    int ret=-1;
    if ((arrayEmpleados!=NULL) && (tamArray>=0))
    {
        for (i=0;i<tamArray;i++)
        {
            if (!arrayEmpleados[i].isEmpty && arrayEmpleados[i].isActive)
            {
                printf("\nEsta ocupado en posicion %d",i);
                printf("\nnombre: %s",arrayEmpleados[i].nombre);
                printf("\napellido: %s",arrayEmpleados[i].apellido);
                printf("\nID: %d",arrayEmpleados[i].idEmpleado);
            } else{
                printf("\nEsta vacio en posicion %d",i);
            }
        }
        ret =0;

    }
    return ret;
}
int empleado_BuscarLibre(Empleado *arrayEmpleados,int tamArray)
{
    int i;
    int ret = -1;
    if ((arrayEmpleados!=NULL) && (tamArray>=0))
    {
        for (i=0;i<tamArray;i++)
        {
            if (arrayEmpleados[i].isEmpty)
            {
                ret =i;
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
    int posLibre=empleado_BuscarLibre(arrayEmpleados,tamArray);
    if ((arrayEmpleados!=NULL) && (tamArray>=0))
    {
        if (posLibre>=0)
        {
            //printf("\nok1");
            //utn_getString(empleadoNuevo.nombre,"\nIngrese nombre de empleado: ","\nReintente, error.",1,20,3);
            //printf("\nok2");
            //utn_getString(empleadoNuevo.apellido,"\nIngrese apellido de empleado: ","\nReintente, error.",1,20,3);
            __fpurge(stdin);
            printf("\nIngrese nombre: ");
            fgets(empleadoNuevo.nombre,sizeof(empleadoNuevo.nombre),stdin);
            empleadoNuevo.nombre[strlen(empleadoNuevo.nombre) - 1] = '\0';

            printf("\nIngrese apellido: ");
            fgets(empleadoNuevo.apellido,sizeof(empleadoNuevo.apellido),stdin);
            empleadoNuevo.apellido[strlen(empleadoNuevo.apellido) - 1] = '\0';

            empleadoNuevo.isEmpty = 0;
            empleadoNuevo.idEmpleado = id;
            empleadoNuevo.isActive = 1;
            arrayEmpleados[posLibre] = empleadoNuevo;
            ret = 0;
        }else{
            printf("No se pudo encontrar una pisicion libre");
        }
    }
    return ret;
}
int empleado_buscarEmpleado(Empleado *arrayEmplado, int tamArray, char *nombre, char *apellido)
{
    int i;
    int ret=-1;
    for (i=0;i<tamArray;i++)
    {
        if(!strcmp(nombre,arrayEmplado[i].nombre)
           && !strcmp(apellido,arrayEmplado[i].apellido)
           && arrayEmplado[i].isActive)
        {
            ret =i;
            break;
        }
    }
    return ret;
}

int empleado_Baja(Empleado *arrayEmpleados,int tamArray)
{
    int ret=-1;
    char nombre[50];
    char apellido[50];
    int posicionEmpleado;
    //utn_getString(nombre,"ingrese nombre a borrar: ","Nombre invalido",0,49,3);
    //utn_getString(nombre,"ingrese apellido a borrar: ","apellido invalido",0,49,3);
    __fpurge(stdin);
    printf("\nIngrese nombre a borrar: ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strlen(nombre) - 1] = '\0';

    printf("\nIngrese apellido a borrar: ");
    fgets(apellido,sizeof(apellido),stdin);
    apellido[strlen(apellido) - 1] = '\0';
    posicionEmpleado= empleado_buscarEmpleado(arrayEmpleados,tamArray,nombre,apellido);
    if (posicionEmpleado>=0)
    {
        arrayEmpleados[posicionEmpleado].isActive = 0;
        ret = 0;
    }


    return ret;
}

int empleado_Modificacion(Empleado *arrayEmpleados,int tamArray)
{
    Empleado empleadoModificado;
    int ret=-1;
    char nombre[50];
    char apellido[50];
    int posicionEmpleado;
    //utn_getString(nombre,"ingrese nombre a modificar: ","Nombre invalido",0,49,3);
    //utn_getString(nombre,"ingrese apellido a modificar: ","apellido invalido",0,49,3);
    __fpurge(stdin);
    printf("\nIngrese nombre a modificar: ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strlen(nombre) - 1] = '\0';

    printf("\nIngrese apellido a modificar: ");
    fgets(apellido,sizeof(apellido),stdin);
    apellido[strlen(apellido) - 1] = '\0';
    posicionEmpleado= empleado_buscarEmpleado(arrayEmpleados,tamArray,nombre,apellido);
    if (posicionEmpleado>=0)
    {
        __fpurge(stdin);
        printf("\nIngrese nombre: ");
        fgets(empleadoModificado.nombre,sizeof(empleadoModificado.nombre),stdin);
        empleadoModificado.nombre[strlen(empleadoModificado.nombre) - 1] = '\0';

        printf("\nIngrese apellido: ");
        fgets(empleadoModificado.apellido,sizeof(empleadoModificado.apellido),stdin);
        empleadoModificado.apellido[strlen(empleadoModificado.apellido) - 1] = '\0';

        empleadoModificado.isEmpty = 0;
        empleadoModificado.idEmpleado = arrayEmpleados[posicionEmpleado].idEmpleado;
        empleadoModificado.isActive = 1;
        arrayEmpleados[posicionEmpleado] = empleadoModificado;
        ret =0;
    }else
        {
            printf("No se a encontrado el Empleado.\n");
        }
    return ret;
}





