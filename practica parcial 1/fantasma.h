#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString1[TEXT_SIZE];
    char varString2[TEXT_SIZE];
    char varString3[TEXT_SIZE];
    int varInt1;
    int varInt2;
    int varInt3;
    float varFloat1;
    float varFloat2;
    float varFloat3;
}Fantasma;


#endif // FANTASMA_H_INCLUDED

int fantasma_Inicializar(Fantasma array[], int size);
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion);
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion);
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion);
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice);
int fantasma_alta(Fantasma array[], int size, int* contadorID);
int fantasma_baja(Fantasma array[], int sizeArray);
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado);
int fantasma_modificar(Fantasma array[], int sizeArray);
int fantasma_ordenarPorString(Fantasma array[],int size);
int fantasma_listar(Fantasma array[], int size);

