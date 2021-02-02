/*
 ============================================================================
 Name        : CPointerTest.c
 Author      : AdamChen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int (*p)[3];
    int *q;

    printf("%d\n", *(*(a+1)+1));

    p = a;
    q = (int *)a;

    printf("%d\n", *(*(p+1)+1));
    printf("%d\n", *(a[1]+1));
    printf("%d\n", a[1][1]);
    printf("%d\n", *(q+6));

    return EXIT_SUCCESS;
}
