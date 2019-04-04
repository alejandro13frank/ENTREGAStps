#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"

int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atof(buffer);
    return 0;
}

int utn_getChar(char* pResultado,const char *mensaje,const char *mensajeError,const char *minimo,const char *maximo,int reintentos)
{
    int ret = -1;
    char buffer[64];
    int i;

    do{
        printf("%s",mensaje);
        scanf("%s", buffer);
        i=0;
        while (buffer[i]!='\0' && i<2)
        {

            if (buffer[0]>=minimo[0] && buffer[0]<=maximo[0])
            {
                ret=0;
            }
            i++;
        }

        if (ret==0 && i==1)
        {
            pResultado = buffer;
            break;
        }
        reintentos--;
        printf("%s\n",mensajeError);
        ret = -1;
        __fpurge(stdin);

    }while (reintentos>0);
    return ret;
}

int utn_getArrayNumero(int* pArrayResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos, int tamArray)
{
    int i;
    int buffer;
    int ret;
    for(i=0; i<tamArray;i++)
    {
        ret = utn_getNumero(&buffer,mensaje,mensajeError,minimo,maximo,reintentos);
        if (ret)
        {
            break;
        }
        pArrayResultado[i] = buffer;
    }
    return ret;
}

int calcularPromedio(int *pArrayResultado, float *promedio, int tamArray)
{
    int i;
    int acumulador=0;
    for (i=0; i<tamArray; i++)
    {
        acumulador+= pArrayResultado[i];
    }

    *promedio = (float)acumulador/tamArray;
    return 0;
}

int swap(int *A, int *B)
{
    int buffer;

    buffer = *A;
    *A = *B;
    *B = buffer;
    return 0;
}

int ordenarBurbujeo(int *pArrayInt, int limite, int menorMayor)
{
    int i;
    int flagSwap;
    do{
    flagSwap=0;
    for (i=0 ; i<limite-1; i++)
    {
        if (pArrayInt[i]<pArrayInt[i+1])
        {
            swap(&pArrayInt[i],&pArrayInt[i+1]);
            flagSwap++;
        }
    }
    }while(flagSwap!=0);
    return 0;
}

int mostrarArray (int *pArray,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        printf("%d, ",pArray[i]);
    }
    return 0;
}

