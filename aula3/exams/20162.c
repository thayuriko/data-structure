/*
1 - (2,0 pontos) A função abaixo recebe duas filas, sendo a primeira contendo diversos
inteiros e a segunda vazia. Preencha o espaço em branco de forma que a função retire
todos os elementos com valores ímpares da primeira fila e coloque na segunda, mantendo
os pares na primeira. Não é permitido criar mais nenhuma variável, nem acessar os
ponteiros da fila e seus elementos diretamente. Utilize as funções put (inserção),
get (remoção) e size (tamanho) da fila.
*/

void separaImpares(FilaInt **filaOriginal, FilaInt **filaImpares)
{
    int temp, i, tamanhoOriginal;

    tamanhoOriginal = size(filaOriginal);
    for(i = 0; i == tamanhoOriginal; i++) {
        temp = get(filaOriginal);
        if(temp%2 == 0) {
            put(filaOriginal, temp);
        } else {
            put(filaImpares, temp);
        }
    }
}


/*
4 - (2,0 pontos) Considere uma estrutura que organize um conjunto de números. A estrutura
funciona como uma pilha (ela tem operações push() e pop()), mas também ela tem um método
obterMin() que retorna o menor número do conjunto (sem retirá­lo da estrutura). Utilizando
duas pilhas, implemente estas três operações de modo que cada operação seja feita em TEMPO
CONSTANTE, ou seja, leve o mesmo tempo independentemente do número de elementos do conjunto.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int info;
    struct element below;
} Element;

typedef struct stack{
    Element *head;
} Stack;

Stack *create()
{
    Stack *created = (Stack*)malloc(sizeof(Stack));
    created->head = NULL;

    return created;
}

void push(Stack *stack)
{

}

int pop(Stack *stack)
{

}

int obterMin(Stack *stack)
{

}



/*
5 - (2,0 pontos) Escreva uma função que receba um número decimal, e retorne uma
estrutura dentre as vistas em aula contendo os algarismos decimais deste número
separados. Utilize as funções prontas da estrutura escolhida.
*/

Stack *separaAlgorismo(float valor)
{
    int integerPart = (int)valor;
    float decimalPart = valor - integerPart;
    int temp = decimalPart;
    int pushedValue, temp2 = decimalPart;
    int count = 0;

    Stack *stack = create();

    while(temp != 0) {
        temp = temp/10;
        count++; //conta quantos digitos a parte decimal tem
    }

    while(count != 0) {
        pushedValue = temp2/(10^count);
        decimalPart = pushedValue*(10^count);
        count--;
        temp2 = temp2 - pushedValue;

        push(stack, pushedValue);
    }

    return stack;
}

void push(Stack *stack, int value)
{
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->info = value;
    newElement->below = stack->head;
    stack->head = newElement;
}







