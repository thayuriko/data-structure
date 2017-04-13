#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

Elemento insert(Elemento *top);
Elemento remover(Elemento *top);

void read(Elemento *top);

int main()
{
    int choice = 0;

    Elemento *e1,*e2,*e3, *top;
    e1 = (Elemento *)malloc(sizeof(Elemento));
    e2 = (Elemento *)malloc(sizeof(Elemento));
    e3 = (Elemento *)malloc(sizeof(Elemento));
    top = (Elemento *)malloc(sizeof(Elemento));

    e1->valor = 1;
    e2->valor = 2;
    e3->valor = 3;
    top = e3;

    e1->proximo = NULL;
    e2->proximo = e1;
    e3->proximo = e2;
    top->proximo = e3;

    while(choice != 4)
    {
        printf("\n\nEscolha qual acao realizar:\n1 - Inserir 1 elemento no topo;\n2 - Remover o elemento do topo;\n3 - Imprimir a ordem dos elementos;\n4 - Sair\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            *top = insert(top);
            break;
        case 2:
            *top = remover(top);
            break;
        case 3:
            read(top);
            break;
        case 4:
            break;
        default:
            printf("Opcao invalida\n\n");
            break;
        }
    }

    free(e1);
    free(e2);
    free(e3);

    return 0;
}

Elemento insert(Elemento *top)
{
    int newValue;
    Elemento *eNew;

    eNew = (Elemento *)malloc(sizeof(Elemento));

    printf("\nInforme o valor numérico do novo elemento: \n");
    scanf("%d", &newValue);
    eNew->valor = newValue;
    eNew->proximo = top;

    top = eNew;



    return *top;
}

Elemento remover(Elemento *top)
{
    Elemento *aux;
    aux = (Elemento *)malloc(sizeof(Elemento));
    aux = top;

    top = aux->proximo;
    aux->proximo = NULL;

    free(aux);

    return *top;
}

void read(Elemento *top)
{
    Elemento *iterador = top;

    while (iterador != NULL) {
        printf("%i \n",iterador->valor);
        iterador = iterador->proximo;
    }
}
