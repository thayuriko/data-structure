/*
3 - Possuo uma pilha vazia. Possuo também uma fila carregada com os elementos
> 6 4 9 5 7 8 2 > (elemento à direita é o próximo a sair).
Essas duas estruturas foram submetidas ao seguinte código (lembrando que
push( ) insere na pilha, pop( ) retira da pilha, queue( ) insere na fila
e dequeue( ) retira da fila):

A. push( dequeue() );
B. queue( dequeue() );
C. push( dequeue() );
D. push( pop() );
E. queue( pop() );
F. dequeue();
G. dequeue();
H. push(dequeue());
I. pop();
J. queue(pop());

Forneça os estados da fila e da pilha após cada instrução.
*/

/*
                      PILHA                FILA
A. push(2):           > 2 >          > 6 4 9 5 7 8 >
B: queue(8):          > 2 >          > 8 6 4 9 5 7 >
C. push(7):           > 2 7 >          > 8 6 4 9 5 >
D. push(7):           > 2 7 >          > 8 6 4 9 5 >
E. queue(7):          > 2 >          > 7 8 6 4 9 5 >
F. dequeue():         > 2 7 >            > 8 6 4 9 >
G. dequeue():         > 2 7 >              > 8 6 4 >
H. push(dequeue()):   > 2 7 4 >              > 8 6 >
I. pop():             > 2 7 >                > 8 6 >
J. queue(7):          > 2 >                > 7 8 6 >
*/
