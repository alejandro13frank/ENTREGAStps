#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "fantasma.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromText(FILE* pFile , LinkedList* pArrayListFantasma)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferIntUno[4096];
    char bufferIntDos[4096];
    char bufferFloatUno[4096];
    int bufferInt;
    int maxId=-1;
    int retorno=-1;
    Fantasma *pFantasma;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferIntUno,
                                                  bufferIntDos);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferIntUno,
                                                  bufferIntDos);

            pFantasma = fantasma_newParametros(     bufferId,
                                                    bufferNombre,
                                                    bufferIntUno,
                                                    bufferIntDos,
                                                    bufferApellido,
                                                    bufferFloatUno);



            if(pFantasma!=NULL &&
                ll_add(pArrayListFantasma,pFantasma)==0)
            {
                fantasma_getId(pFantasma,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
        }
        fantasma_setIdInicial(maxId+1);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromBinary(FILE* pFile , LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    Fantasma *pFantasma;
    int bufferInt;
    int maxId=-1;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pFantasma=fantasma_new();
            if(pFantasma!=NULL &&
                fread(pFantasma,sizeof(Fantasma),1,pFile)&&
                ll_add(pArrayListFantasma,pFantasma)==0)
            {
                fantasma_getId(pFantasma,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
            else
            {
                fantasma_delete(pFantasma);
            }
        }
        fantasma_setIdInicial(maxId+1);
    }
    return retorno;
}
