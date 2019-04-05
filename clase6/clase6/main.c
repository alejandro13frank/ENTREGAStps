#include <stdio.h>
#include <stdlib.h>
#define NUM_LEN 10

int int calcularPromedio(int *pArrayResultado, float *promedio, int tamArray);
int int calcularMin (int *pArray, int len, int *minimo);
int int calcularMax (int *pArray, int len, int *maximo);
int int buscarNumeroArray(int *pArray, int len, int numero);
int int ordenarBurbujeo(int *pArrayInt, int limite, int menorMayor);
int int swap(int *A, int *B);
int int mostrarArray (int *pArray,int limite);

int main()
{
    int array[NUM_LEN]= {10,80,56,74,1,5,8,6,98,2};
    int maximo;
    int minimo;
    float promedio;

    calcularMax(array, NUM_LEN, &maximo);
    calcularMin(array, NUM_LEN, &minimo);
    calcularPromedio(array, &promedio, NUM_LEN);

    ordenarBurbujeo(array,NUM_LEN,0);//ordena de mayor a menor
    mostrarArray (array,NUM_LEN);
    ordenarBurbujeo(array,NUM_LEN,1);//ordena de menor a mayor
    mostrarArray (array,NUM_LEN);

    printf("maximo: %d\n", maximo);
    printf("minimo: %d\n", minimo);
    printf("promedio: %.2f\n", promedio);
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

int int swap(int *A, int *B)
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
    printf("\n");
    return 0;
}
