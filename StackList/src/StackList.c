/*
 ============================================================================
 Name        : StackList.c
 Author      : doremi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

#define OK 1
#define ERROR 0

#define ARRAYSIZE(P) (sizeof(p)/sizeof(p[0]))

typedef int SElemType;
typedef int Status;

typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

Status Push(LinkStack *S, SElemType e) {
	int pushtemp = 0;
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	pushtemp = S->top->data;
	printf("%d\n", pushtemp);
	return OK;
}


Status Pop(LinkStack *S, SElemType *e) {
	if(S->top == NULL)
	{
		return ERROR;
	}

	LinkStackPtr s = S->top;
	*e = s->data;
	S->top = s->next;
	S->count--;
	free(s);

	return OK;

}

int StackLength(LinkStack *S) {
	return S->count;
}

void InitStack(LinkStack *S)
{
	S->top = NULL;
	S->count = 0;
}

int main(void) {
//	puts("!!!Hello Doremi!!!"); /* prints !!!Hello Doremi!!! */
	int i = 0;
	int popTemp =  0;
	LinkStack stack;

	InitStack(&stack);

	printf("push...\n");
	for(i = 0; i < MAXSIZE; i++)
	{
		Push(&stack, 3*i);
	}
    printf("pop...\n");
    for(i = 0; i < MAXSIZE; i++)
    {
    	Pop(&stack, &popTemp);
    	printf("%d\n", popTemp);
    }

	return EXIT_SUCCESS;
}
