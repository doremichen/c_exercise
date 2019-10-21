/*
 ============================================================================
 Name        : QuickSort.c
 Author      : doremi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;}


void quicksort(int number[], int left, int right) {
	int i, j, s;
	if(left < right)
	{
		s = number[left];
		i = left;
		j = right+1;

		while(1)
		{
			while(i+1 < MAX && number[++i] < s);
			while(j-1 > -1 && number[--j] > s);
			if(i >= j) break;

			SWAP(number[i], number[j]);
		}

		number[left] = number[j];
		number[j] = s;

		quicksort(number, left, j-1);
		quicksort(number, j+1, right);


	}
    printf("\n");
	printf("After sorting:\n");
	for(i = 0; i < MAX; i++)
    {
		printf("%d ", number[i]);
    }

}


int main(void) {
//	puts("!!!Hello Doremi!!!"); /* prints !!!Hello Doremi!!! */

	int number[MAX] = {0};
	int i;

	srand(time(NULL));
	printf("Before sorting:\n");

	for(i = 0; i < MAX; i++)
	{
		number[i] = rand()%100;
		printf("%d ", number[i]);
	}
    printf("\n");

	quicksort(number, 0, MAX-1);

	return EXIT_SUCCESS;
}
