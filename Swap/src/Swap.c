/*
 ============================================================================
 Name        : Swap.c
 Author      : AdamChen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


int main(void) {
    int a = -7;
    int b = 100;

    printf("%d, %d\n", a, b);

    Swap(&a, &b);


    printf("%d, %d\n", a, b);



    return EXIT_SUCCESS;
}
