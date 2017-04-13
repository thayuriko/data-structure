#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

int main(void)
{
    Elemento *e1,*e2,*e3;
    e1 = (Elemento *)malloc(sizeof(Elemento));
    e2 = (Elemento *)malloc(sizeof(Elemento));
    e3 = (Elemento *)malloc(sizeof(Elemento));
    e1->valor = 1;
    e2->valor = 2;
    e3->valor = 3;
    e1->proximo = e2;
    e2->proximo = e3;
    e3->proximo = NULL;
    Elemento *iterador = e1;
    while (iterador != NULL) {
        printf("%i \n",iterador->valor);
        iterador = iterador->proximo;
    }
    return 0;
}
