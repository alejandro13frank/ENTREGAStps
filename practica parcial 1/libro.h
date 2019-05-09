#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#define TEXT_SIZ 51

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char titulo[TEXT_SIZE];//varString
    int codigoDeAutor;//varInt


}Libro;


#endif // LIBRO_H_INCLUDED

int libro_Inicializar(Libro array[], int size);                                    //cambiar libro
int libro_buscarEmpty(Libro array[], int size, int* posicion);                    //cambiar libro
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice);                    //cambiar libro
int libro_alta(Libro array[], int size, int* contadorID);                          //cambiar libro
int libro_baja(Libro array[], int sizeArray);                                      //cambiar libro
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado);
int libro_modificar(Libro array[],Autor arrayAutores[], int sizeArray, int sizeAutores);                                //cambiar libro
int libro_ordenarPorString(Libro array[],int size);                              //cambiar libro
int libro_listar(Libro array[], int size);                      //cambiar libro


