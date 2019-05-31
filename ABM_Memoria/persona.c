#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn_strings.h"
static void setIdInicial(int val);
static int generarId(void);

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(char* nombre,char* apellido,char* edad)
{
    Persona* per=persona_new();
    if(per!=NULL)
    {
        persona_setNombre(per,nombre);
        persona_setApellido(per,apellido);
        persona_setEdad(per,edad);
    }


    return per;
}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setId(Persona* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}


int persona_setEdad(Persona* this, char* value)
{
    int auxEdad;
    int retorno = -1;
    if(this != NULL && isNumber(value))
    {
        auxEdad=atoi(value);
        this->edad = auxEdad;
        retorno = 0;
    }
    return retorno;
}

int persona_setNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && isLetter(value))
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_setApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && isLetter(value))
    {
        strncpy(this->apellido,value,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}


int persona_getEdad(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->edad;
        retorno = 0;
    }
    return retorno;
}

int persona_getNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_getApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_addPersona(Persona* arrayPersona[],int lenPersona,char* msgE,int tries)
{
    int indexFree;
    char bufferName[32];
    char bufferApellido[32];
    char bufferEdad[32];
    char nombre[32];
    char apellido[32];
    int edad;
    int retorno=-1;
    if(lenPersona>0)
    {
        indexFree=persona_findFree(arrayPersona,lenPersona);
        if(indexFree!=-1)
        {
            if((!getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries))
                    &&(!getStringLetras(bufferApellido,"\nIngrese Apellido: ",msgE,tries))
                       &&(!getStringNumeros(bufferEdad,"\nIngrese Edad: ",msgE,tries)))
            {
                arrayPersona[indexFree]=persona_newParametros(bufferName,
                                                               bufferApellido,
                                                               bufferEdad);
                persona_setId(arrayPersona[indexFree],generarId());
                persona_getNombre(arrayPersona[indexFree],nombre);
                persona_getApellido(arrayPersona[indexFree],apellido);
                persona_getEdad(arrayPersona[indexFree],&edad);
                printf("\nSe dio de alta a:\n"
                        "Nombre: %s\nApellido: %s\n"
                        "Edad: %d\n",
                        nombre,
                        apellido,
                        edad);


                retorno=0;
            }
        }

    }
    return retorno;
}

int persona_initArray(Persona* arrayPer[],int lenPer)
{
    int i;
    int retorno=-1;
    if(arrayPer!=NULL&&lenPer>0)
    {
        for(i=0; i<lenPer; i++)
        {
            arrayPer[i]=NULL;
        }
        retorno=0;

    }
    return retorno;
}

int persona_findFree(Persona* arrayPersona[], int lenPersona)
{
    int i;
    int ret=-1;
    if(arrayPersona!=NULL && lenPersona>0)
    {
        for(i=0; i<lenPersona; i++)
        {
            if(arrayPersona[i]==NULL)
            {
                ret=i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}
static int idPer=0;
static int generarId(void)
{
    return idPer++;
}
static void setIdInicial(int val)
{
    idPer= val;
}

int persona_parcer(char* nombreArchivo,Persona *arrayPersona[],int size)
{
    FILE *personaTxt  = fopen(nombreArchivo,"r");
    int retorno=-1;
    Persona *auxPersona;
    int r;
    int maxId=-1;
    char nombre[512];
    char apellido[512];
    char edad[512];
    int id;
    char auxA[512];
    int i=0;
    if (personaTxt!=NULL)
    {
        fscanf(personaTxt,"%[^\n]\n",auxA);
        do
        {
            r = fscanf(personaTxt,"%d,%[^,],%[^,],%[^\n]\n",&id,nombre,apellido,edad);
            if (r==4)
            {
                auxPersona = persona_new();
                if (auxPersona!=NULL)
                {
                    if (id>maxId) //usar id de tipo int, usando atoi
                    {
                        maxId=id;
                    }
                    persona_setId(auxPersona,id);
                    persona_setEdad(auxPersona,edad);
                    persona_setNombre(auxPersona,nombre);
                    persona_setApellido(auxPersona,apellido);
                    arrayPersona[i]=auxPersona;
                    i++;
                }
            }
        }while(!feof(personaTxt));
        setIdInicial(maxId);
        fclose(personaTxt);
        retorno=i;
    }
   return retorno;
}
