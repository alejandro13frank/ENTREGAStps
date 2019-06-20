#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    int bufferInt;
    int maxId=-1;
    int retorno=-1;
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas);

            pEmpleado = employee_newParametros(     bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas);

            employee_setSueldo(pEmpleado,0);

            if(pEmpleado!=NULL &&
                ll_add(pArrayListEmployee,pEmpleado)==0)
            {
                employee_getId(pEmpleado,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
        }
        employee_setIdInicial(maxId+1);
    }
    return retorno;
}
