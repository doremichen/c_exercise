/*
 ============================================================================
 Name        : Queue.c
 Author      : Doremi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
} SqQueue;


int InitQueue(SqQueue *Q)
{
	int i = 0;

	while(i < MAXSIZE)
	{
		Q->data[i] = 0;
		i++;
	}

	Q->front = 0;
	Q->rear = 0;

	return OK;
}

int QueueLength(SqQueue *Q)
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

int EnQueue(SqQueue *Q, int data)
{
	if((Q->rear + 1)%MAXSIZE == Q->front)
	{
		printf("full\n");
		return ERROR;
	}

	Q->data[Q->rear] = data;
	Q->rear= (Q->rear + 1)%MAXSIZE;

	return OK;
}

int DeQueue(SqQueue *Q, int *data)
{
	if(Q->front == Q->rear)
	{
		printf("empty\n");
		return ERROR;
	}

	*data = Q->data[Q->front];
	Q->front= (Q->front + 1)%MAXSIZE;

	return OK;
}


int print_Data(SqQueue *Q)
{
	int i = 0;
	int getValue = 0;
	int size = QueueLength(Q);

	while(i < size)
	{
		DeQueue(Q, &getValue);
		printf("%d\n", getValue);
		i++;
	}

	return OK;
}

int main(void) {
	SqQueue SQ;

	InitQueue(&SQ);

	EnQueue(&SQ, 1111);
	EnQueue(&SQ, 111);
	EnQueue(&SQ, 11);
	EnQueue(&SQ, 1);

	print_Data(&SQ);

//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
