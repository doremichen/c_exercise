/*
 ============================================================================
 Name        : DualLinkedList.c
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

typedef struct DulNode_tag * DulLinkList;

typedef struct DulNode_tag
{
    int data;
    struct DulNode_tag *prior;
    struct DulNode_tag *next;
    int size;
} DulNode;


void CreateLinkList(DulNode **ppNode)
{
    (*ppNode)->data = 0;
    (*ppNode)->next = (*ppNode);
    (*ppNode)->prior = (*ppNode);
    (*ppNode)->size = 0;
}

int InsertList(DulLinkList *L, int i, int e)
{
    int j;
    DulLinkList p, q;
    p = *L;
    j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    (*L)->size = (*L)->size + 1;
    q = (DulLinkList)malloc(sizeof(DulNode));
    q->data = e;
    q->prior = p;
    q->next = p->next;
    p->next->prior =q;
    p->next = q;

    return OK;

}

int DeleteList(DulLinkList *L, int i, int *e)
{
    int j;
    DulLinkList p, q;
    p = (*L)->next;
    j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    (*L)->size--;
    *e = p->data;
    q = p->prior;

    q->next = p->next;
    p->next->prior = q;

    free(p);

    return OK;
}


int printf_data(DulLinkList L)
{
    DulLinkList p;
    int size = L->size;
    if(L->next == L->prior)
    {
        printf("No element...\n");
        return ERROR;
    }

    p = L->next;

//    printf("%d\n", L->size);
    while(size)
    {
        printf("%d\n", p->data);
        p = p->next;
        size--;
    }

    return OK;
}



int main(void) {

    DulLinkList pHnode =  NULL;
    int getvalue = 0;
    pHnode = (DulLinkList)malloc(sizeof(DulNode));

    CreateLinkList(&pHnode);

    InsertList(&pHnode, 1, 100);
    InsertList(&pHnode, 2, 200);
    InsertList(&pHnode, 3, 500);
    printf_data(pHnode);

    printf("------------------\n");

    DeleteList(&pHnode, 2, &getvalue);

    printf_data(pHnode);


//    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
    return EXIT_SUCCESS;
}
