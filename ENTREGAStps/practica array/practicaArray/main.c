#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_ARRAY 10

int utn_getArrayNumero(int* pArrayResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos ,int tamArray);
int calcularPromedio(int *pArrayResultado, float *promedio, int tamArray);


int main()
{
    //char* mensaje = "ingrese un numero: ";
    //char* mensajeError = "numero invalido solo entre 0 y 100";
    int arrayNumeros[TAM_ARRAY] = {2,5,4,8,6,8,7,5,1,5};
    //float promedio;
    mostrarArray(arrayNumeros,TAM_ARRAY);
    /*utn_getArrayNumero(arrayNumeros, mensaje, mensajeError, 0, 100, 3, TAM_ARRAY);
    calcularPromedio(arrayNumeros, &promedio, TAM_ARRAY);
    printf("el promedio es : %.2f\n", promedio);
    return 0;*/

    ordenarBurbujeo(arrayNumeros,TAM_ARRAY,0);
    printf("\n");
    mostrarArray(arrayNumeros,TAM_ARRAY);
}






