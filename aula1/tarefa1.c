/*
1. Criar 3 structs teste
2. Atribuir valor para elas
3. Colocar elas em sequência
4. Imprimir elas em sequência usando repetição (laços)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct teste
{
    int valor;
    struct teste *proximo;
} Teste;

int main()
{
    int k[3];
    int i;
    i = 0;

    //1
    Teste *pT1 = NULL;
    Teste *pT2 = NULL;
    Teste *pT3 = NULL;

    pT1 = malloc(sizeof(Teste));
    pT2 = malloc(sizeof(Teste));
    pT3 = malloc(sizeof(Teste));

    //2
    pT1->valor = 0;
    pT2->valor = 5;
    pT3->valor = 3;

    //3
    pT1->proximo = pT2;
    pT2->proximo = pT3;
    pT3->proximo = NULL;

    k[0] = pT1->valor;
    k[1] = pT2->valor;
    k[2] = pT3->valor;

    //4
    for(i=0;i<3;i++)
    {
        printf("%i \n",k[i]);
    }

    return 0;
}
