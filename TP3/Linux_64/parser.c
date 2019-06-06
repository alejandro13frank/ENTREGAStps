#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int bufferInt;
    int maxId=-1;
    int retono=-1;
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^\n]\n",bufferNombre);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);

            pEmpleado = employee_newParametros(     bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);



            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee,pEmpleado);
                employee_getId(pEmpleado,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retono=0;
            }
        }
        setIdInicial(maxId);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
