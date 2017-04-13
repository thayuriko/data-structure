#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct pilha {
    Elemento *topo;
} Pilha;

Pilha *inicializaPilha() {
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
	p->topo = NULL;
    return p;
}

void colocaDado(int d, Pilha *p) {
    Elemento *novoDado;
    novoDado = (Elemento *)malloc(sizeof(Elemento));
    novoDado->dado = d;
    novoDado->proximo = p->topo;
    p->topo = novoDado;
}

int retiraDado(Pilha *p) {
    int saida = p->topo->dado;
	Elemento *aux = p->topo;
    p->topo = p->topo->proximo;
	free(aux);
	aux = NULL;
    return saida;
}

void imprimePilha(Pilha *p) {
    Elemento *iterador;
    iterador = p->topo;
    while (iterador != NULL) {
        printf("%i",iterador->dado);
        iterador = iterador->proximo;
    }
	printf("\n");
}


int main(void)
{
    Pilha *p = inicializaPilha();
    colocaDado(1,p);
    colocaDado(2,p);
    colocaDado(3,p);
    colocaDado(4,p);
    retiraDado(p);
    imprimePilha(p);
    return 0;
}
