#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[250];
    int precio;    //deberia ir con float, pero no la tenemos ahora en la biblioteca.
    int tipo;
}Pantalla;

int pantalla_inicializarArray(Pantalla* pantallas, int tamArray);
int pantalla_buscarVacio(Pantalla* pantallas, int tamArray);
int pantalla_Alta(Pantalla* pantallas, int tamArray);
int pantalla_Baja(Pantalla* pantallas, int tamArray);
int pantalla_Modificacion(Pantalla* pantallas, int tamArray);
int pantalla_buscarPantalla(Pantalla* pantallas, int tamArray, int idPantalla);
int pantalla_GenerarID(int *idPantalla);


#endif // PANTALLA_H_INCLUDED
