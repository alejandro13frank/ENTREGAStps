#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicidad.h"
#include "funciones2.0.h"

static int GenerarID(void);

int publicidad_buscarVacio(Publicidad* publicidades, int tamArray)
{
    int ret=-1;
    int i;

    if(publicidades!=NULL&&tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(publicidades[i].isEmpty==1)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int publicidad_Alta(Publicidad* publicidades, int tamArray, int idPantalla)
{//modificar para que FUNCIONE!!!!!
    int ret=-1;
    int posVacia;
    Publicidad aux_Publicidad;
    if (publicidades!=NULL && tamArray>0 && idPantalla>-1)
    {
        posVacia=publicidad_buscarVacio(publicidades,tamArray);

        if(posVacia!=-1)
        {
            getString(aux_Publicidad.cuit,"Ingrese el cuit del cliente: ","cuit incorrecto",1,20,5);
            getString(aux_Publicidad.archivoVideo,"Ingrese nombre del archivo de video: ","Archivo de video invalido",1,50,5);
            utn_getNumber(&(aux_Publicidad.dias),"Ingrese cantidad de dias de puclicidad: ","Ingrese cantidad valida",1,1000,5);

            aux_Publicidad.isEmpty=0;
            aux_Publicidad.idPantalla = idPantalla;
            aux_Publicidad.idPublicidad = GenerarID();
            publicidades[posVacia]=aux_Publicidad;

            ret=0;
        }else
            {
                printf("No encontro un lugar vacio.");
            }
    }
    return ret;
}


int publicidad_Baja(Publicidad* publicidades, int tamArray)
{
    int ret=-1;
    char cuit[20];
    int posicionPublicidad;
    int idPublicidad;
    if (publicidades!=NULL && tamArray>0)
    {
        getString(cuit,"ingrese cuit de cliente para dar BAJA: ","cuit invalido",1,20,3);
        publicidad_listaPantallaPorCuit(publicidades,tamArray,cuit);
        utn_getNumber(&idPublicidad,"Seleccione un ID de Pantalla a borrar: ","ID invalido",0,30000,3);
        posicionPublicidad=publicidad_buscarPublicidad(publicidades,tamArray,idPublicidad);
        if (posicionPublicidad!=-1)
        {
            publicidades[posicionPublicidad].isEmpty=1;
            ret=0;
        }else
            {
                printf("No se encontro la publicidad.\n");
            }
    }

  return ret;
}
int publicidad_Modificacion(Publicidad* publicidades, int tamArray)
{
    int ret=-1;
    char cuit[20];
    int posicionPublicidad;
    int idPublicidad;
    if (publicidades!=NULL && tamArray>0)
    {
        getString(cuit,"ingrese cuit de cliente a MODIFICAR: ","cuit invalido",1,20,3);
        publicidad_listaPantallaPorCuit(publicidades,tamArray,cuit);
        utn_getNumber(&idPublicidad,"Seleccione un ID de Pantalla: ","ID invalido",0,30000,3);
        posicionPublicidad=publicidad_buscarPublicidad(publicidades,tamArray,idPublicidad);
        if (posicionPublicidad!=-1)
        {
            utn_getNumber(&(publicidades[posicionPublicidad].dias),"Ingrese cantidad de dias de puclicidad 0 a 100","Ingrese cantidad valida",1,100,5);
            ret=0;
        }else
            {
                printf("No se encontro la publicidad.\n");
            }
    }

  return ret;
}
int publicidad_buscarPublicidad(Publicidad* publicidades, int tamArray, int idPublicidad)
{
    int ret=-1;
    int i;

    if(publicidades!=NULL&&tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(publicidades[i].idPublicidad==idPublicidad)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}
int publicidad_inicializarArray(Publicidad* publicidades, int tamArray)
{
    int i;
    int ret=-1;

    if(publicidades!=NULL&&tamArray>0)
    {
        for(i=0;i<tamArray;i++)
        {
            publicidades[i].isEmpty=1;
        }
        ret=0;
    }
    return ret;
}
static int GenerarID(void)
{
    static int idPublicidad=0;
    return idPublicidad++;
}
int publicidad_listaPantallaPorCuit(Publicidad *publicidades,int tamArray,char *cuit)
{
    int i;
    int ret =0;
    int j=0;
    for (i=0;i<tamArray;i++)
    {
        if(!publicidades[i].isEmpty && strcmp(publicidades[i].cuit,cuit)==1)
        {
            j++;
            printf("%d ID Pantalla: %d\n",j,publicidades[i].idPantalla);
        }
        ret =0;
    }
    return ret;
}

int publicidad_mostrarPublicidades(Publicidad* publicidades, Pantalla *pantallas, int tamArrayPub, int tamArrayPub)
{
    int i;
    int posPantalla;
    for (i=0;i<tamArray;i++)
    {
	posPantalla = pantalla_buscarIDporpantalla(pantallas,tamArrayPan,publicidades[i].idPantallas)
        if (!(publicidades[i].isEmpty))
        {
            printf("%d pantalla ID: %d \n",i,publicidades[i].idPantalla);
            printf("   publicidad ID: %d \n",publicidades[i].idPublicidad);
            printf("   publicidad Direccion %s \n",publicidades[i].cuit);
            printf("   publicidad archivo: %s \n",publicidades[i].archivoVideo);
            printf("   pantalla DIAS: %d \n",publicidades[i].dias);
	    printf("   pantalla nombre: %d \n",pantallas[posPantalla].nombre);

        }
    }
    return 0;
}

int publicidad_mostrarPorDias(Publicidad* publicidades, Pantalla *pantallas, int tamArrayPub, int tamArrayPan, int valor)
{
    int i;
    int posPantalla;
    for (i=0;i<tamArrayPub;i++)
    {
        if (!(publicidades[i].isEmpty))
        {
	    if (publicidades[i].dias<valor)
	    {
	   	posPantalla = pantalla_buscarIDporpantalla(pantallas,tamArrayPan,publicidades[i].idPantallas);
            	printf("%d pantalla ID: %d \n",i,publicidades[i].idPantalla);
           	printf("   publicidad ID: %d \n",publicidades[i].idPublicidad);
          	printf("   publicidad precio: %d \n",publicidades[i].precio);
           	printf("   pantalla DIAS: %d \n",publicidades[i].dias);
	   	printf("   pantalla nombre: %d \n",pantallas[posPantalla].nombre);
		printf("   pantalla PRECIO X DIAS: %d \n",publicidades[i].dias*pantallas[i].precio);

	    }
        }
    }
    return 0;
}
































/****************************************************************************
            Codeado por Alejandro Frank
******************************************************************************/

