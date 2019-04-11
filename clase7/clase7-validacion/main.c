#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones2.0.h"

int main()
{
    int numero;

    utn_getNumber(&numero, "INGRESE UN NUMERO: ","NO SEAS PUTO: ",-100,80,4);

    printf("%d",numero);

   return(0);
}








