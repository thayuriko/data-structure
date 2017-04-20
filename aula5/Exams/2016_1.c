#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int value;
	struct node *next;
	struct node *previous;
}Node;

typedef struct list{
	int count;
	Node *head;
	Node *tail;
}List;

/*
1 ­ Faca uma funcao que apague da lista os nos cujas posições sao encontradas em uma lista2. 
Por exemplo, para uma lista1 = {A, B, C, D, E} e uma lista2 = {2, 4, 8}, 
o segundo e o quarto elemento da lista lista1 devem ser apagados (ja que o oitavo nao existe), 
e, apos esta operacao, a lista lista1 deve ser igual a {A, C, E}. 
Para esta questao, novos elementos NAO podem ser alocados na memoria (as funcoes inserirElemento()
 e removerElemento()) nao podem ser utilizadas. Ambas as listas sao duplamente encadeadas. (2,0 pontos)
Obs.: considere que a lista2 está ordenada de forma crescente.
*/

void popAtIndexArray(List *list, List *positions)
{
	Node *positionsTmp = positions->tail;
	int indexToBePopped = positionsTmp->value;
	int i;

	while(positionsTmp->previous != NULL){
		
		Node *tmp = list->head;
		Node *poppedNode = tmp;

		if(indexToBePopped > list->count){
			
			positionsTmp = positionsTmp->previous;
			indexToBePopped = positionsTmp->value;
		} else {

			for(i=1; i==indexToBePopped; i++){
				tmp = tmp->next;
			}

			tmp->next->previous = tmp->previous;
			tmp->previous->next = poppedNode->next;
			free(poppedNode);
		}
	}
}

/*
2 ­ Como um polinomio pode ser representado por uma lista? Cada nó deve representar um termo e deve
 conter as respectivas potências, bem como o coeficiente desse termo. Exemplo: o polinômio 
 P(x) = 4x3 ­ 5x2 ­ 3x + 8 seria representado como P = {(3,4), (2,­5), (1,­3), (0,8)}. 
 Escreva funções para fazer o seguinte: (5,0 pontos)
a. calcular P(x) para determinado x
b. somar dois polinômios desse tipo;
c. multiplicar dois polinômios desse tipo;
d. calcular a derivada parcial de um polinômio desse tipo;
e. integrar um polinômio desse tipo (recebendo o valor da constante K);
Obs.: a questao ‘a’ deve retornar um valor, e as questoes de ‘b’ até ‘e’ devem retornar novas listas 
representando polinômio resultado. Use uma lista já implementada (funções inserir, remover e tamanho prontas).
*/

typedef struct mathList{
	int power;
	int constant;
	struct mathList *next;
	struct mathList *previous;
}MathList;

typedef struct polynomial{
	MathList *head;
	MathList *tail;
}Polynomial;

int polynomialResult(MathList *list, int x)
{
	double result = 0;
	int base, exponent, multiplier;
	Polynomial *tmp = list->head;

	while(tmp != NULL){
		base = x;
		exponent = tmp->power;
		multiplier = tmp->constant;
		result = result + multiplier*pow(base, exponent);

		tmp = tmp->next;
	}

	return result;
}

MathList *summation(MathList *list1, MathList *list2)
{
	
}























