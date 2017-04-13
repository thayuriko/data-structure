#include <stdio.h>
#include <stdlib.h>

typedef struct teste
{
    int valor;
    struct teste *proximo;
} Teste;

void troca(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i,j;
    // Ponteiros devem sempre ser inicializados como nulos
    int *pi1 = NULL;
    int *pi2 = NULL;

    i = 6;
    // pi1 recebe o endere�o de mem�ria de i
    pi1 = &i;
    pi2 = pi1;
    // j dereferencia o valor de pi2 (acessa o valor de i) e soma 2
    j = *pi2 + 2;
    *pi2 = 7;
    j = i + 2;
    // pi1 recebe o endere�o de mem�ria de j
    pi2 = &j;
    troca(&i,&j);
    printf("%i \n",j);

    int ii;
    int k[4];
    k[0] = 1;
    k[1] = 2;
    k[2] = 3;
    // as duas linhas seguintes acessam o mesmo elemento do vetor,
    // j� que vetor � um tipo de ponteiro em C
    k[3] = 4;
    *(k+3) = 5;
    for (ii = 0; ii < 4; ii++)
    {
        printf("%i \n",k[ii]);
    }

    // as duas trocas abaixo acessam os mesmos elementos,
    // demonstrando duas maneiras diferentes de acessar vetores
    // (uma explorando a aritm�tica de ponteiros)
    troca(&(k[0]),&(k[2]));
    for (ii = 0; ii < 4; ii++)
    {
        printf("%i \n",k[ii]);
    }

    troca(k,k+2);
    for (ii = 0; ii < 4; ii++)
    {
        printf("%i \n",k[ii]);
    }

    // outra maneira de se criar um vetor: criando um ponteiro
    // para o primeiro elemento e alocando a mem�ria necess�ria
    int *l;
    l = malloc(sizeof(int*)*2);
    l[0] = 11;
    l[1] = 22;
    for (ii = 0; ii < 2; ii++)
    {
        printf("%i \n",l[ii]);
    }
    troca(l,l+1);
    for (ii = 0; ii < 2; ii++)
    {
        printf("%i \n",l[ii]);
    }

    // a aritm�tica de ponteiros permite esta opera��o, mas quando
    // o c�digo dereferencia (acessa) o valor do endere�o de mem�ria
    // contido no ponteiro n�o h� nada nele (vetor de apenas duas
    // posi��es)
    troca(l,l+3);
    for (ii = 0; ii < 2; ii++)
    {
        printf("%i \n",l[ii]);
    }

    // no C o gerenciamento de mem�ria � manual, n�o esquecer de limp�-la
    // ap�s o uso
    //free(l);
    //l = NULL; //para n�o ter uso acidental de l (o programa trava ao inv�s
    //de um endere�o de mem�ria n�o especificado ser acessado)

    // o programa imprime lixo na tela pois n�o h� nenhum valor no endere�o
    // de mem�ria aleat�rio do ponteiro jkl
    int *jkl;
    printf("%i \n",*jkl);

    int *mno = NULL;
    //*mno = 6; // trava o programa, tentativa de dereferenciar um ponteiro vazio!

    Teste *pT1 = NULL;
    Teste *pT2 = NULL;
    // utilizando aqui a mesma l�gica do vetor feito anteriormente
    pT1 = malloc(sizeof(Teste));
    pT2 = malloc(sizeof(Teste));
    (*pT1).valor = 2;
    printf("%i \n",(*pT1).valor);

    // como este acesso � bastante comum no C, -> � uma nota��o da linguagem
    pT1->valor = 3;
    printf("%i \n",pT1->valor);
    pT2->valor = 4;
    pT1->proximo = pT2;
    pT2->proximo = NULL;
    return 0;
}
