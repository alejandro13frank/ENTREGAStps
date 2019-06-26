#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "fantasma.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"r+");
    if (pFile!=NULL && parser_FantasmaFromText(pFile , pArrayListFantasma)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if (pFile!=NULL && parser_FantasmaFromBinary(pFile , pArrayListFantasma)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_addFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    int bufferId;
    char bufferNombre[4096];
    char bufferApellido[4096];
    int bufferIntUno;
    int bufferIntDos;
    Fantasma* pFantasma;

    if (pArrayListFantasma!=NULL)
    {
        utn_getName("\nIngrese nombre: ","\nError",1,20,1,bufferNombre);
        utn_getName("\nIngrese nombre: ","\nError",1,20,1,bufferApellido);
        utn_getUnsignedInt("\nIngrese horas trabajadas: ","\nError",1,6,1,30000,1,&bufferIntUno);
        utn_getUnsignedInt("\nIngrese Sueldo: ","\nError",1,6,1,30000,1,&bufferIntDos);
        bufferId=fantasma_generarId();
        pFantasma=fantasma_new();
        if (pFantasma!=NULL &&
            fantasma_setId(pFantasma,bufferId)==0 &&
            fantasma_setNombre(pFantasma,bufferNombre)==0 &&
            fantasma_setApellido(pFantasma,bufferApellido)==0 &&
            fantasma_setIntUno(pFantasma,bufferIntUno)==0 &&
            fantasma_setIntDos(pFantasma,bufferIntDos)==0 &&
            ll_add(pArrayListFantasma,pFantasma)==0)
            {
                retorno=0;
            }
            else
            {
                printf("\nNo se pudo agregar el empleado.");
            }
        //------------------------------------------------------
       /* Fantasma* pFantasma;
        bufferId=fantasma_generarId();
        controller_ListFantasma(lista);
        utn_getUnsignedInt("\nIngrese ID: ","\nError",1,6,1,30000,1,&bufferIntUno);
        if (controller_searchIdFantasma(lista,bufferIntUno)>=0)
        {
            utn_getAlfanumerico("\nIngrese Codigo de loque sea: ","\nError",0,60,1,bufferCodigo);
            sscanf(bufferCodigo,"%[^-]-%[^-]-%[^\n]\n",bufferIdCodigo
                                                      ,bufferNombreCodigo
                                                        ,bufferPrecioCodigo);
            utn_getUnsignedInt("\nIngrese cantidad a comprar: ","\nError",1,6,1,30000,1,&bufferIntUno);
            pFantasma=fantasma_newParametros(bufferId,bufferIdCodigo,bufferNombreCodigo,bufferPrecioCodigo,bufferIntUno);
            if (pFantasma!=NULL)
            {
                retorno=0;
            }
        }
        else
        {
            printf("\n No se encontro el ID.");
        }*/


    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_editFantasma(LinkedList* pArrayListFantasma)
{

    int retorno=-1;
    int id;
    int bufferIdNode;
    char bufferNombre[128];
    char bufferApellido[128];
    int bufferIntDos;
    int bufferIntUno;
    char opcion;
    Fantasma *bufferFantasma;
    if(pArrayListFantasma!=NULL)
    {
        controller_ListFantasma(pArrayListFantasma);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),0,30000,1,&id);
        bufferIdNode=controller_searchIdFantasma(pArrayListFantasma,id);
        if(bufferIdNode==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                bufferFantasma=ll_get(pArrayListFantasma,bufferIdNode);
                fantasma_printNode(bufferFantasma);
                utn_getChar("\nModificar: \nA: Nombre. \nB: Horas trabajadas. \nC: Sueldo \nD: Apellido \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,bufferNombre);
                        fantasma_setNombre(bufferFantasma,bufferNombre);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,30000,1,&bufferIntUno);
                        fantasma_setIntUno(bufferFantasma,bufferIntUno);
                        break;
                    case 'C':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,30000,1,&bufferIntDos);
                        fantasma_setIntDos(bufferFantasma,bufferIntDos);
                        break;
                    case 'D':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,bufferApellido);
                        fantasma_setApellido(bufferFantasma,bufferApellido);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_removeFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    int id;
    int bufferIdNode;
    if(pArrayListFantasma!=NULL)
    {
        controller_ListFantasma(pArrayListFantasma);
        utn_getUnsignedInt("\nID a eliminar: ","\nError",1,6,0,30000,1,&id);
        bufferIdNode=controller_searchIdFantasma(pArrayListFantasma,id);
        if(bufferIdNode==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListFantasma,bufferIdNode);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_ListFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    int i;
    int lenLista;
    if (pArrayListFantasma!=NULL && ll_len(pArrayListFantasma)!=0)
    {
        lenLista=ll_len(pArrayListFantasma);
        for (i=0;lenLista>i;i++)
        {
           fantasma_printNode(ll_get(pArrayListFantasma,i));
        }
    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_sortFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    if (pArrayListFantasma!=NULL)
    {
        ll_sort(pArrayListFantasma,fantasma_comparaNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    int i;
    int size;
    int bufferId;
    char bufferNombre[4096];
    int bufferIntUno;
    int bufferIntDos;
    Fantasma* pFantasma;
    FILE* fp = fopen(path,"w+");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListFantasma);
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<size;i++)
        {
            pFantasma=ll_get(pArrayListFantasma,i);
            fantasma_getId(pFantasma,&bufferId);
            fantasma_getNombre(pFantasma,bufferNombre);
            fantasma_getIntUno(pFantasma,&bufferIntUno);
            fantasma_getIntDos(pFantasma,&bufferIntDos);

            fprintf(fp,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferIntUno,bufferIntDos);

        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    int i;
    int size;
    Fantasma* pFantasma;
    FILE* fp = fopen(path,"w+b");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListFantasma);
        for(i=0;i<size;i++)
        {
            pFantasma=ll_get(pArrayListFantasma,i);
            fwrite(pFantasma,sizeof(Fantasma),1,fp);
        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}
int controller_searchIdFantasma(LinkedList* pArrayListFantasma, int id)
{
    int retorno=-1;
    int lenLista;
    int i;
    int bufferId;
    if (pArrayListFantasma!=NULL && id>0 && ll_len(pArrayListFantasma)!=0)
    {
        lenLista=ll_len(pArrayListFantasma);
        for (i=0;i<lenLista;i++)
        {
            fantasma_getId(ll_get(pArrayListFantasma,i),&bufferId);
            if (id==bufferId)
            {
                retorno=i;
                break;
            }
        }

    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}

/*int controller_listByCOSA(LinkedList* this,int (*pFunc)(void*,void*))
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    int i;
    char bufferCosa[1024];
    char bufferCodigo[1024];
    if (this!=NULL && pFunc!=NULL)
    {
        returnAux=0;
        utn_getAlfanumerico("\nIngrese Codigo de loque sea: ","\nError",0,60,1,bufferCosa);
        sscanf(bufferCosa,"%[^-]-",bufferCodigo);
        if (isValidNumber(bufferCodigo))
        {

            for(i=0;i<lenLista;i++)
            {
                auxElement=ll_iterNext(iterator);
                if (pFunc(auxElement,bufferCodigo)==-1)
                {
                    returnAux=-1*i;
                    break;
                }
            }
        }
    }
    ll_iterFinishIter(iterator);
    return returnAux;
}

int imprimoVenta(void* this, void* codigo)
{
    int retorno=-1;
    if (this!=NULL && codigo>0)
    {
        fantasma_getCodigo((Fantasma*)this,&bufferCodigo);
        if (codigo==bufferCodigo)
        {
            fantasma_printNode(this);
            retorno=0;
        }
    }
    return retorno;
}
*/

int controller_ListFantasmaMagia(LinkedList* this, LinkedList* that)
{
    int returnAux=-1;
    IterNode* iteratorA=ll_iterInit(this);
    IterNode* iteratorB;
    int lenListaA=ll_len(this);
    int lenListaB=ll_len(that);
    void* auxElementA;
    void* auxElementB;
    int idCliente;
    int idVenta;
    float monto;
    float montoTotal;
    int cantVentas;
    int i;
    int j;
    if (this!=NULL && that!=NULL)
    {
        //returnAux=0;
        for(i=0;i<lenListaA;i++)
        {
            cantVentas=0;
            auxElementA=ll_iterNext(iteratorA);
            fantasma_getId(auxElementA,&idCliente);
            iteratorB =ll_iterInit(that);
            for(j=0;j<lenListaB;j++)
            {
                auxElementB=ll_iterNext(iteratorB);
                fantasma_getId(auxElementB,&idVenta);
                fantasma_getFloatUno(auxElementB,&monto);
                if (idCliente==idVenta)
                {
                    cantVentas++;
                    montoTotal+=monto;

                }
            }
            fantasma_printNode(auxElementA);
            printf("cantidad de ventas= %d \f monto total= %f",cantVentas,montoTotal);
            ll_iterFinishIter(iteratorB);
        }
        returnAux=0;
    }
    ll_iterFinishIter(iteratorA);
    return returnAux;

}



