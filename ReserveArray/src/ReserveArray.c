/*
 ============================================================================
 Name        : ReserveArray.c
 Author      : doremi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(void) {

	int array[100], n, c, end;

	printf("please input the length of array\n");
	scanf("%d", &n);

	end = n-1;


	for(c = 0; c < n; ++c) {
		scanf("%d", &array[c]);
	}

	printf("the array:\n");
	for(c = 0; c < n; ++c) {
		printf("%d", array[c]);
	}
	printf("\n");

	//swap
	for(c = 0; c < n/2; ++c) {

		array[c] = array[c] + array[end];
		array[end] = array[c] - array[end];
		array[c] = array[c] - array[end];

		--end;
	}

	printf("\n");

	printf("the reverse array:\n");
	for(c = 0; c < n; ++c) {
		printf("%d", array[c]);
	}


	while(!kbhit());


//	puts("!!!Hello Doremi!!!"); /* prints !!!Hello Doremi!!! */
	return 0;
}
