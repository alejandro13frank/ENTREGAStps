#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones2.0.h"

int buscarLibre(char vector[][20], int *index, int largo);
int inicializarVector (char vector[][20], int len);
int buscarNombre(char *pNombre,
                 char lista[][20],
                 int len,
                 int *pIndex)
{
    int i;
    int ret = -1;
    for (i=0;i<len;i++)
    {
        if(strcmp(pNombre,lista[i]))
        {
            *pIndex = i;
            ret = 0;
            break;
        }
    }
    return ret;
}
int borrarNombre (char vector[][20],int pIndex)
{
    int ret;
    if (vector!=NULL)
    {
        vector[pIndex][0] = '\0';
        ret=0;
    }
    return ret;
}



int main()
{
    int option = 1;
    int index;
    char buffer[40];
    char lista [20][20];
    while (option!=0)
    {
        utn_getNumber(&option,"ingrese una opcion: ","nomero no sirve",0,5,3);
        switch (option)
        {
            case 1:
                getString(buffer, "ingrese un nombre: ", "nombre no sirve", 1, 20,3);
                inicializarVector(lista,20);
                buscarLibre(lista,&index,20);
                strncpy(lista[index],buffer,20);
                break;
            case 4:
                getString(buffer,"ingresa el valor a borrar","valor invalido",1,20,1);
                buscarNombre(buffer, lista,20,&index);
                borrarNombre(lista,index);
                break;
            case 0:
                break;
        }
    }
    return 0;
}

int buscarLibre(char vector[][20], int *index, int largo)
{
    int i;
    int ret = -1;

    for(i=0;i<largo;i++)
    {
        if (vector[i][0]== '\0')
        {
            *index = i;
            ret =0;
            break;
        }
    }
    return ret;
}
int inicializarVector (char vector[][20], int len)
{
    int i;
    for (i=0; i<len;i++)
    {
        vector[i][0] = '\0';
    }
    return 0;
}
