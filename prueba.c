///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "queues.h"
///////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////
int main(){
	Queue q;
	initQueue(&q);

	for (int i = 0; i < 22; ++i) {
		enqueue(&q,i+1);
	}

	printf("%d\n\n", emptyQueue(&q));

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", dequeue(&q));
	}

	for (int i = 0; i < 10; ++i) {
		enqueue(&q,i+37);
	}

	for (int i = 0; i < 22; ++i) {
		printf("%d\n", dequeue(&q));
	}

	printf("\n%d\n", emptyQueue(&q));


	return 0;
}
////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////