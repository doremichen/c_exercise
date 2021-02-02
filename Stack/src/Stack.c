/*
 ============================================================================
 Name        : Stack.c
 Author      : AdamChen
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
    int top;
} sqStack;

int InitStack(sqStack *pSt)
{
    int i = 0;
    for(i = 0; i < MAXSIZE; i++)
    {
        pSt->data[i] = 0;
    }

    pSt->top = 0;

    return OK;
}

int Push(sqStack *pSt, int data)
{
    if(pSt->top ==  MAXSIZE)
    {
        printf("stack buffer full\n");
        return ERROR;
    }

    pSt->top++;
    pSt->data[pSt->top] =  data;

    return OK;
}

int Pop(sqStack *pSt, int *data)
{
    if(pSt->top == 0)
    {
        printf("empty\n");
        return ERROR;
    }

    *data = pSt->data[pSt->top];
    pSt->top--;

    return OK;
}

int print_data(sqStack *pSt)
{
    int i;

    if(pSt->top == 0)
    {
        printf("No element in Stack\n");

        return ERROR;
    }

    for(i = 1; i <= pSt->top; i++)
    {
        printf("%d\n", pSt->data[i]);
    }

    return OK;
}

int main(void) {
    sqStack stack;
    int getvalue;

    InitStack(&stack);

    Push(&stack, 22);
    Push(&stack, 34);
    Push(&stack, 66);

    print_data(&stack);

    printf("--------------\n");

    Pop(&stack, &getvalue);

    printf("========> %d\n", getvalue);

    print_data(&stack);

//    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
    return EXIT_SUCCESS;
}
