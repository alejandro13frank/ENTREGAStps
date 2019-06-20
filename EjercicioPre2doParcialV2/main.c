#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);


int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados=ll_newLinkedList();
    LinkedList* listaFilter=ll_newLinkedList();
    // Crear lista empledos
    //...

    // Leer empleados de archivo data.csv
    FILE * archivo=fopen("data.csv","rb");
    if(parser_EmployeeFromText(archivo,listaEmpleados)==0)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);

        listaFilter=ll_filter(listaEmpleados,em_filtraPorsueldo);
        ll_reduce(listaEmpleados,em_filtraPorsueldo);
        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==0)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");

        if(generarArchivoSueldos("filter.csv",listaFilter)==0)
        {
            printf("Archivo generado correctamente filter\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    int retorno=-1;
    int i;
    int size;
    int bufferId;
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    Employee* pEmployee;
    FILE* fp = fopen(fileName,"w+");
    if (fp!=NULL)
    {
        size=ll_len(listaEmpleados);
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<size;i++)
        {
            pEmployee=ll_get(listaEmpleados,i);
            employee_getId(pEmployee,&bufferId);
            employee_getNombre(pEmployee,bufferNombre);
            employee_getHorasTrabajadas(pEmployee,&bufferHorasTrabajadas);
            employee_getSueldo(pEmployee,&bufferSueldo);

            fprintf(fp,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

        }
        retorno=0;
        fclose(fp);
    }
    return retorno;

}
