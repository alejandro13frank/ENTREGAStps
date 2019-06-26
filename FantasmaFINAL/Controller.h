#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED
#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayListFantasma);
int controller_loadFromBinary(char* path , LinkedList* pArrayListFantasma);
int controller_addFantasma(LinkedList* pArrayListFantasma);
int controller_editFantasma(LinkedList* pArrayListFantasma);
int controller_removeFantasma(LinkedList* pArrayListFantasma);
int controller_ListFantasma(LinkedList* pArrayListFantasma);
int controller_sortFantasma(LinkedList* pArrayListFantasma);
int controller_saveAsText(char* path , LinkedList* pArrayListFantasma);
int controller_saveAsBinary(char* path , LinkedList* pArrayListFantasma);
int controller_searchIdFantasma(LinkedList* pArrayListFantasma, int id);
int controller_ListFantasmaMagia(LinkedList* this, LinkedList* that);
#endif
