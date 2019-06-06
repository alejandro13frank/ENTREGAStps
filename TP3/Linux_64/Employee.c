#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int retorno=-1;
    Employee* pEmployee=employee_new();
    if (pEmployee!=NULL)
    {
        employee_setIdStr(pEmployee,idStr);
        employee_setNombre(pEmployee,nombreStr);
        employee_setHorasTrabajadas(pEmployee,horasTrabajadasStr);
        employee_setSueldoStr(pEmployee,sueldoStr);
    }
    return pEmployee;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setIdStr(Employee* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if (this!=NULL && isValidNumber(id))
    {
        atoi(bufferInt);
        if (bufferInt>0)
        {
            employee_setId(this,bufferInt);
        }
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if (this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr)
{
    int retorno=-1;
    int bufferHora;
    if (this!=NULL && isValidNumber(horasTrabajadasStr))
    {
        atoi(bufferHora);
        if (bufferHora>0)
        {
            employee_setId(this,bufferHora);
        }
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=-1;
    if (this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno=-1;
    int buffersueldo;
    if (this!=NULL && isValidNumber(sueldo))
    {
        atoi(buffersueldo);
        if (buffersueldo>0)
        {
            employee_setId(this,buffersueldo);
        }
    }
    return retorno;
}





