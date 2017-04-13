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

void menu(Pilha *p)
{
	int valor = 0;
	char operador;
	int valores[100];
	int i = 0;
	int result = 0;
	
	scanf("%c", &operador);
	while(operador != '+')
    {
//		printf("\n\nEscolha qual acao realizar:\n1 - Inserir 1 elemento no topo;\n2 - Remover o elemento do topo;\n3 - Imprimir a ordem dos elementos;\n4 - Sair\n");
	    scanf("%d", &valor);
	    colocaDado(valor, p);
	    printf("%i\n", p->topo->dado);
	    i++;
	}
	
//	switch(operador)
//	    {
//	    case '+':
		if(operador == '+') {
	    	result = p->topo->dado + p->topo->proximo->dado;
	        retiraDado(p->topo);
	        retiraDado(p->topo->proximo);
	        colocaDado(result, p);
	        imprimePilha(p);
	    }
//	        break;
//	    case '-':
//	        result = p->topo->dado - p->topo->proximo->dado;
//	        retiraDado(p);
//	        retiraDado(p);
//	        colocaDado(result, p);
//	        
//	        break;
//	    case "*":
//	        imprimePilha(p);
//	        break;
//	    case 4:
//	        break;
//	    default:
//	        printf("Opcao invalida\n\n");
//	        break;
//	    }
}

int main(void)
{
    Pilha *p = inicializaPilha();
    char stop;
    
    scanf("%c",&stop);
    
    while(stop != 's') {
    	menu(p);
	}
    
    return 0;
}

