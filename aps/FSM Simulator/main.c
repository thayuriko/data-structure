#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct state{
    int stateNo;
    int isFinalState;
    struct state *next0;
    struct state *next1;
}State;

typedef struct graph{
    State *start;
}Graph;

Graph *createGraph()
{
    Graph *newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->start = NULL;

    return newGraph;
}

void deleteStates(int totalStates, Graph *graph)
{
    State *tmp = graph->start;
    State *removed;

    int i;

    for(i=totalStates; i>0; i--){
        removed = tmp;
        tmp = (removed+i);
        removed->next0 = NULL;
        removed->next1 = NULL;

        free(removed);
    }
}

void readStates(int totalStates, Graph *graph, char *sequence)
{
    int strSize = strlen(sequence);
    char resultSequence[100];
    int i;

    State *tmp = graph->start;

    for(i=0; i<strSize; i++){
        if(sequence[i] == '1'){
            tmp = tmp->next1;
            resultSequence[i] = tmp->stateNo;
        } else if(sequence[i] == '0'){
            tmp = tmp->next0;
            resultSequence[i] = tmp->stateNo;
        }
    }

    printf("\nO estado final eh s%d, e a sequencia de estados eh \n*[s%d]", tmp->stateNo, graph->start->stateNo);

    tmp = graph->start;

    for(i=0; i<strSize; i++){
        if(sequence[i] == '0'){
            printf("->[s%d]", tmp->next0->stateNo);
            tmp = tmp->next0;
        } else {
            printf("->[s%d]", tmp->next1->stateNo);
            tmp = tmp->next1;
        }
    }

    if(tmp->isFinalState == 1){
        printf("\n(* indica o estado inicial)\n\nEntrada aceita");
    } else {
        printf("\n(* indica o estado inicial)\n\nEntrada rejeitada");
    }
}

void printParameters(int totalStates, Graph *graph)
{
    int i = 0;

    State *tmp = graph->start;

    printf("\n\nM = (Q, Sigma, delta, q0, F), onde\n     Q = {");

    for(i=0; i<totalStates-1; i++){
        printf("s%d, ", i);
    }

    printf("s%d}", totalStates-1);
    printf("\n     Sigma = {0, 1}\n     delta = ----------------");
    printf("\n             | q  | 0  | 1  |");

    for(i=-graph->start->stateNo; i<totalStates-graph->start->stateNo; i++){
        tmp = (graph->start+i);
        printf("\n             | s%d | s%d | s%d |", tmp->stateNo, tmp->next0->stateNo, tmp->next1->stateNo);
    }

    printf("\n             ----------------\n     q0 = s0\n     F = {");

    int j = 0;
    for(i=0; i<totalStates; i++){
        tmp = (graph->start+i);
        if(tmp->isFinalState == 1){
            if(j == 0){
                printf("s%d", tmp->stateNo);
                j++;
            } else {
                printf(", s%d", tmp->stateNo);
            }
        }
    }
    printf("}");
}

void createStates(int states, Graph *graph)
{
    State *stateNode = (State*)malloc(sizeof(State)*states);

    int add, i, initialState, finalState;

    printf("\nO estado inicial q0 eh: s");
    scanf("%d", &initialState);

    if(initialState >= states){
        return;
    }

    printf("\n(<estado_atual>, <entrada>) = <prox_estado>\n");

    for(i=0; i<states; i++){
        if(i == 0){
            graph->start = (stateNode+initialState);
        }

        (stateNode+i)->stateNo = i;
        (stateNode+i)->isFinalState = 0;

        printf("(s%d, 0) = s", i);
        scanf("%d", &add);
        (stateNode+i)->next0 = (stateNode+add);

        printf("(s%d, 1) = s", i);
        scanf("%d", &add);
        (stateNode+i)->next1 = (stateNode+add);

        printf("Eh um estado final (0/1)? ");
        scanf("%d", &finalState);
        (stateNode+i)->isFinalState = finalState;
    }

    printParameters(states, graph);
}

void symbolSequence(int states, Graph *graph)
{
    int choice, i;
    char sequence[100];

    printf("\n//-----------------------------\nInsira uma sequencia de acoes (ex. 01001001): ");
    scanf("%s", sequence);

    for(i=0; i<strlen(sequence); i++){
        if(sequence[i] != '1' && sequence[i] != '0'){
            printf("String invalida\n");

            symbolSequence(states, graph);
            return;
        }
    }

    readStates(states, graph, sequence);

    printf("\n\nDeseja inserir uma nova sequencia (0/1)? ");
    scanf("%d", &choice);

    if(choice == 1){
        symbolSequence(states, graph);
    }

    return;
}

int main()
{
    system("cls");
    int states = 1;

    Graph *graph = createGraph();

    printf("Informe quantos estados a maquina possui: ");
    scanf("%d", &states);

    createStates(states, graph);
    symbolSequence(states, graph);
    deleteStates(states, graph);

    return 0;
}
