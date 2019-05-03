#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "funciones2.0.h"
static int generarID(void);

int pantalla_inicializarArray(Pantalla* pantallas, int tamArray)
{
    int i;
    int ret=-1;

    if(pantallas!=NULL&&tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            pantallas[i].isEmpty=1;
        }
        ret=0;
    }
    return ret;
}

int pantalla_buscarVacio(Pantalla* pantallas, int tamArray)
{
    int ret=-1;
    int i;

    if(pantallas!=NULL&&tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(pantallas[i].isEmpty==1)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int pantalla_Alta(Pantalla* pantallas, int tamArray)
{
    int ret=-1;
    int posVacia; //uso esta variable auxiliar para guardar el retorno de la funcion pantalla_buscarVAcio.
    Pantalla aux_Pantalla;
    posVacia=pantalla_buscarVacio(pantallas,tamArray);

    if(posVacia!=-1)
    {
        getString(aux_Pantalla.nombre,"Ingrese el nombre de la pantalla: ","Nombre de la pantalla incorrecto",1,49,5);
        getString(aux_Pantalla.direccion,"Ingrese la direccion de la pantalla: ","Direccion de la pantalla invalida",1,249,5);
        utn_getNumber(&(aux_Pantalla.precio),"Ingrese el precio de la pantalla: ","Ingrese un monto valido",1,30000,5);   //&(aux_Pantalla.precio) asi se nota como puntero en el caso de ser una variable primitiva tipo int o float.
        utn_getNumber(&(aux_Pantalla.tipo),"Ingrese 0 para led, 1 para lcd: ", "Ingrese un tipo valido",0,1,5);

        aux_Pantalla.isEmpty=0;
        aux_Pantalla.idPantalla = generarID();
        pantallas[posVacia]=aux_Pantalla;//como el auxiliar es solo variable para una pantalla, no necesita asignarle posicion.

        ret=0;
    }
    else
    {
        printf("No encontro un lugar vacio.");
    }
    return ret;
}

int pantalla_buscarPantalla(Pantalla* pantallas, int tamArray, int idPantalla)
{
    int ret=-1;
    int i;

    if(pantallas!=NULL&&tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(pantallas[i].idPantalla==idPantalla)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}
int pantalla_Baja(Pantalla* pantallas, int tamArray)
{
    int ret=-1;
    int idPantalla;
    int posicionPantalla;
    if (pantallas!=NULL && tamArray>0)
    {
        utn_getNumber(&idPantalla,"ingrese ID de pantalla a dar BAJA: ","pantalla invalida",0,30000,3);
        posicionPantalla=pantalla_buscarPantalla(pantallas,tamArray,idPantalla);
        if (posicionPantalla!=-1)
        {
            pantallas[posicionPantalla].isEmpty =1;
            printf("La pantalla se dio de baja.\n");
            ret=0;
        }else
            {
                printf("No se encontro la pantalla.\n");
            }
    }

  return ret;
}

static int generarID(void)
{
    static int idPantalla;
    return idPantalla++;
}

int pantalla_Modificacion(Pantalla* pantallas, int tamArray)
{
    int ret=-1;
    int idPantalla;
    int posicionPantalla;
    Pantalla aux_Pantalla;
    if (pantallas!=NULL && tamArray>0)
    {
        utn_getNumber(&idPantalla,"ingrese ID de pantalla a MODIFICAR: ","pantalla invalida",0,30000,3);
        posicionPantalla=pantalla_buscarPantalla(pantallas,tamArray,idPantalla);
        if (posicionPantalla!=-1)
        {
            getString(aux_Pantalla.nombre,"Ingrese el nombre de la pantalla: ","Nombre de la pantalla incorrecto",1,49,5);
            getString(aux_Pantalla.direccion,"Ingrese la direccion de la pantalla: ","Direccion de la pantalla invalida",1,249,5);
            utn_getNumber(&(aux_Pantalla.precio),"Ingrese el precio de la pantalla: ","Ingrese un monto valido",1,5,5);   //&(aux_Pantalla.precio) asi se nota como puntero en el caso de ser una variable primitiva tipo int o float.
            utn_getNumber(&(aux_Pantalla.tipo),"Ingrese 0 para led, 1 para lcd: ", "Ingrese un tipo valido",0,1,5);
            aux_Pantalla.isEmpty=0;
            aux_Pantalla.idPantalla = idPantalla;
            pantallas[posicionPantalla]=aux_Pantalla;
            ret=0;
        }else
            {
                printf("No se encontro la pantalla.\n");
            }
    }

  return ret;
}

int pantalla_MostrarPantallas(Pantalla *pantallas,int tamArray)
{
    int i;
    for (i=0;i<tamArray;i++)
    {
        if (!(pantallas[i].isEmpty))
        {
            printf("%d pantalla ID: %d \n",i,pantallas[i].idPantalla);
            printf("%d pantalla direccion %s \n",i,pantallas[i].direccion);
            printf("%d pantalla nombre: %s \n",i,pantallas[i].nombre);
            printf("%d pantalla TIPO: %d \n",i,pantallas[i].tipo);
            printf("%d pantalla precio: %d \n",i,pantallas[i].tipo);
        }
    }
    return 0;
}




















/****************************************************************************
            Codeado por Alejandro Frank
******************************************************************************/
