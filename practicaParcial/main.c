#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones2.0.h"
#include "publicidad.h"
#include "pantalla.h"


int main()

{
    char seguir='s'; //MENU
    int opcion; //MENU
    int valor1;
    int valor2;
    Publicidad publicidades[100];
    Pantalla pantallas[100];

    valor1=pantalla_inicializarArray(pantallas,100);
    valor2=publicidad_inicializarArray(publicidades,100);

    if (valor1==0 && valor2==0)
    {
        printf("inicializados correctamente\n\n\n");
    }
    while (seguir=='s')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta pantalla");
        printf("\n\n2-Mostrar pantallas");
        printf("\n\n3-Borrar pantallas");
        printf("\n\n4-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>4);
            switch (opcion)
            {
                case 1:
                        switch(pantalla_Alta(pantallas, 100))
                        {
                            case 0:
                                printf("dato ingresado correctamente\n\n");
                                break;
                            case -1:
                                printf("dato ingresado INCORRECTAMENTE\n\n");
                                break;
                        }

                        break;

                case 2:

                    pantalla_MostrarPantallas(pantallas,100);
                    break;

                case 3:
                    if (pantalla_Baja(pantallas, 100)==0)
                    {
                        printf("exito");
                    }
                    break;

                case 4:
                    seguir='f';
                    break;
            }
    }
    return 0;
}
