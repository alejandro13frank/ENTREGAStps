#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "fantasma.h"
#include "utn.h"


int main()
{
    int opcion;
    char nombreArchivoTexto[20];
    char nombreArchivoBinario[20];
    LinkedList* listaFantasma = ll_newLinkedList();
//    LinkedList* listaFantasma2 = ll_newLinkedList();
    do
    {
        printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
        printf("\n3) Alta de empleado");
        printf("\n4) Modificar datos de empleado");
        printf("\n5) Baja de empleado");
        printf("\n6) Listar empleados");
        printf("\n7) Ordenar empleados por Nombre");
        printf("\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario)");
        utn_getUnsignedInt("\n\n10) Salir\n","\nError",1,sizeof(int),1,60,1,&opcion);
        switch(opcion)
        {
            case 1: //
                utn_getString("\nIngrese nombre de archivo a abrir (data.csv):","\nError ",1,20,1,nombreArchivoTexto);
                controller_loadFromText(nombreArchivoTexto,listaFantasma);
                break;

            case 2: //
                utn_getString("\nIngrese nombre de archivo a abrir (dataBinario.csv):","\nError ",1,20,1,nombreArchivoBinario);
                controller_loadFromBinary(nombreArchivoBinario,listaFantasma);
                break;

            case 3: //
                controller_addFantasma(listaFantasma);
                break;

            case 4: //
                controller_editFantasma(listaFantasma);
                break;

            case 5: //
                controller_removeFantasma(listaFantasma);
                break;

            case 6: //
                controller_ListFantasma(listaFantasma);
                break;

            case 7: //
                controller_sortFantasma(listaFantasma);
                break;

            case 8: //
                utn_getString("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoTexto);
                controller_saveAsText(nombreArchivoTexto,listaFantasma);
                break;

            case 9: //
                utn_getString("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoBinario);
                controller_saveAsBinary(nombreArchivoBinario,listaFantasma);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10); //

    ll_deleteLinkedList(listaFantasma);
    return 0;
}
