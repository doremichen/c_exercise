/*
 ============================================================================
 Name        : BiTree.c
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

typedef struct BiTNode_tag *BiTree;

struct BiTNode_tag
{
    int data;
    BiTree lchild, rchild;

} BiTNode;


int CreateBiTree(BiTree *T)
{
    char ch;

//    printf("please input element: ");
    scanf("%c", &ch);

    if(ch == '#')
    {
//        printf("[CreateBiTree]: ch == '#'\n");
        *T = NULL;
    }
    else
    {
////        printf("[CreateBiTree]: ch != '#'\n");
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->lchild= NULL;
        (*T)->rchild= NULL;
        if(!*T)
        {
            printf("No memeory\n");
            return ERROR;
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
//        CreateBiTree(&(*T)->rchild);
    }


//    printf("[CreateBiTree]\n");
//    do {
//        printf("next? or enter -1 to leave\n");
//        scanf("%d", &next);
//        printf("input elment\n");
//        scanf("%c", &ch);

//        if(*ch == '#')
//        {
//            printf("[CreateBiTree]: ch == '#'\n");
//            *T = NULL;
//        }
//        else
//        {
//            printf("[CreateBiTree]: ch != '#'\n");
//            *T = (BiTree)malloc(sizeof(BiTNode));
//            if(!*T)
//            {
//                printf("No memeory\n");
//                return ERROR;
//            }
//            (*T)->data = *ch;
//            CreateBiTree(&(*T)->lchild, ch);
//            CreateBiTree(&(*T)->rchild, ch);
//
//        }


//    }while(next != -1);

    return OK;
}


int PreOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        printf("[PreOrderTraverse]: empty tree\n");
        return ERROR;
    }
    printf("[PreOrderTraverse]: %c\n", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return OK;
}

int main(void) {

    BiTree pBiTree = NULL;

    CreateBiTree(&pBiTree);
//    char ch;
//
//    do{
//        scanf("%c", &ch);
//
//        CreateBiTree(&pBiTree, &ch);
//
//    } while(ch != '$');

    printf("Test Done...\n");
//    CreateBiTree(&pBiTree, &ch);
//
////    printf("[main]: ok~\n");
//    fprintf(stderr, "[main]: ok~\n");
    PreOrderTraverse(pBiTree);

//    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//    system("PAUSE");
    return EXIT_SUCCESS;
}
