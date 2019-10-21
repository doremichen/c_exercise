/*
 ============================================================================
 Name        : MergeArray.c
 Author      : doremi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void swap(int *a, int *b) {

	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;

}


int main(void) {

	int c, j, n, m, t, array1[100], array2[100], merge[100];

	printf("please input the length of array1\n");
	scanf("%d", &n);

	printf("please input %d element in array1.\n", n);
	for(c = 0; c < n; ++c) {
		scanf("%d", &array1[c]);
	}

	printf("please input the length of array2\n");
	scanf("%d", &m);

	printf("please input %d element in array2.\n", m);
	for(c = 0; c < m; ++c) {
		scanf("%d", &array2[c]);
	}

	printf("the element in array1 is\n");
	for(c = 0; c < n; ++c) {
		printf("%d", array1[c]);
	}

	printf("\n");

	printf("the element in array2 is\n");
	for(c = 0; c < m; ++c) {
		printf("%d", array2[c]);
	}

	printf("\n");

	for(c = 0; c < n; ++c) {
		merge[c] = array1[c];
	}

	for(c = 0; c < m; ++c) {
		t = c + n;
		merge[t] = array2[c];
	}

	printf("before sort: the merge array is\n");

	for(c = 0; c < m+n; ++c) {
		printf("%d", merge[c]);
	}

	printf("\n");

	for(c = 0; c < m+n; ++c) {
		for(j = c+1; j < m+n; ++j) {
			if(merge[c] > merge[j]) {
				swap(&merge[c], &merge[j]);
			}
		}
	}


	printf("after sort: the merge array is\n");

	for(c = 0; c < m+n; ++c) {
		printf("%d", merge[c]);
	}



	while(!kbhit());


//	puts("!!!Hello Doremi!!!"); /* prints !!!Hello Doremi!!! */
	return EXIT_SUCCESS;
}
