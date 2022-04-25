/*
Implement using linked-list, with tail pointer:
	enqueue(value) - adds value at position at tail
	dequeue() - returns value and removes least recently added element (front)
	empty()
Implement using fixed-sized array:
	enqueue(value) - adds item at end of available storage
	dequeue() - returns value and removes least recently added element
	empty()
	full()
Cost:
	a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n) because you'd need the next to last element, causing a full traversal each dequeue
	enqueue: O(1) (amortized, linked list and array [probing])
	dequeue: O(1) (linked list and array)
	empty: O(1) (linked list and array)
*/
///////////////////////////////////////////////////////BIBLIOTECAS///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////DEFINES/////////////////////////////////////////////////////////
#define	ARR_LENGTH	16
////////////////////////////////////////////////////////VARIABLES////////////////////////////////////////////////////////

///////////////////////////////////////////////////////ESTRUCTURAS///////////////////////////////////////////////////////
typedef struct
{
	int read;
	int write;
	int arr[ARR_LENGTH];
} Queue;
/////////////////////////////////////////////////PROTOTIPOS DE FUNCIONES/////////////////////////////////////////////////
//CONSIGNA
void enqueue(Queue*, int value);	//Agrega valor al final de la lista. 
int dequeue(Queue*);				//Elimina y devuelve el valor primer valor agregado.
bool emptyQueue(Queue*);			//Devuelve true si esta vacía la fila.

//AUXILIARES
void initQueue(Queue*);				//Inicializo.

////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
//AUXILIARES
void initQueue(Queue *q){
	q->read = 0;
	q->write = 0;
}

void enqueue(Queue *q, int value){
	if (q->write == ARR_LENGTH-1 && q->read != 0) {
		q->write = 0;
	}
	if (q->write == ARR_LENGTH-1 && q->read == 0) {
		printf("NOP, FILA LLENA\n");
	}
	else{
		if (q->write == q->read-1) {
			printf("\nNOP\n");
		}
		else{
			*(q->arr + q->write) = value;
			q->write++;
		}
	}
	
}

int dequeue(Queue *q){
	if (emptyQueue(q)) {
		return -1;
	}
	else{
		if (q->read == ARR_LENGTH-1) {
			q->read = 0;
		}
		q->read++;
		return *(q->arr + q->read - 1);
	}
}

bool emptyQueue(Queue *q){
	return q->read == q->write;
}
///////////////////////////////////////////////////////////FIN///////////////////////////////////////////////////////////