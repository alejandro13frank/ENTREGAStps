#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuit[20];
    int dias;
    char archivoVideo[50];
    int idPantalla;
}Publicidad;

int publicidad_buscarVacio(Publicidad* publicidades, int tamArray);

int publicidad_Alta(Publicidad* publicidades, int tamArray,int idPantalla);

int publicidad_Baja(Publicidad* publicidades, int tamArray);

int publicidad_Modificacion(Publicidad* publicidades, int tamArray);

int publicidad_buscarPublicidad(Publicidad* publicidades, int tamArray, int idPublicidad);

int publicidad_inicializarArray(Publicidad* publicidades, int tamArray);

int publicidad_listaPorCuit(Publicidad *publicidades,int tamArray,char *cuit);


#endif // PUBLICIDAD_H_INCLUDED
