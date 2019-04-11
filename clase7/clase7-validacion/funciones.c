#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"

int utn_getNumeroMio(int* pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
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

int utn_getFloatMio(float *pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
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

int utn_getChar(char* pResultado,char *mensaje,char *mensajeError,char *minimo,char *maximo,int reintentos)
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

int calcularMax (int *pArray, int len, int *maximo)
{
    int i;
    int buffer;

    for(i=0;i<len;i++)
    {
        if (i==0 || buffer>pArray[i])
            {
                buffer = pArray[i];
            }
    }
    *maximo = buffer;
    return 0;
}

int calcularMin (int *pArray, int len, int *minimo)
{
    int i;
    int buffer;

    for(i=0;i<len;i++)
    {
        if (i==0 || buffer<pArray[i])
            {
                buffer = pArray[i];
            }
    }
    *minimo = buffer;
    return 0;
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

int buscarNumeroArray(int *pArray, int len, int numero)
{
    int i;
    int ret=-1;
    for (i=0;i<len;i++)
    {
        if (numero == pArray[i])
        {
            ret = 0;
            break;
        }
    }
    return ret;
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
    //0 para mayor y 1 para menor;
    int i;
    int flagSwap;
    do{
    flagSwap=0;
    for (i=0 ; i<limite-1; i++)
    {
        if (menorMayor==0 && pArrayInt[i]<pArrayInt[i+1])
        {
            swap(&pArrayInt[i],&pArrayInt[i+1]);
            flagSwap++;
        }
        if (menorMayor==1 && pArrayInt[i]>pArrayInt[i+1])
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







