#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"
#define QTY_PEOPLE 100

int main()
{
    Persona *arrayPersonas[QTY_PEOPLE];
    int opcionMenu;

    do
    {
        utn_getUnsignedInt("\n1)Agregar Persona \n2)Modificar Persona \n3)Eliminar Persona \n4)Imprimir Personas \n5)Salir",
                            "\n-- ERROR --",1,sizeof(int),1,5,1,&opcionMenu);
        switch(opcionMenu)
        {
            case 1:
                Per_alta(arrayPersonas,QTY_PEOPLE);
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcionMenu!=5);

    return 0;
}
