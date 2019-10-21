/*
 ============================================================================
 Name        : Palindromic.c
 Author      : doremi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int RevNum(int num)
{
	int reverse = 0;

	while(num != 0 ) {
		reverse = reverse*10;
		reverse += num%10;
		num = num/10;
	}

	return reverse;
}


int main(void) {

	int value = 0, rev = 0, i, counter = 0;
	int record[1000] = {0};

	do {

		memset(record, 0, 1000);
		counter = 0;

		printf("please input the number\n");
		scanf("%d", &value);


		for(i = 0;  i < value; ++i) {

			rev = RevNum(i);

			if(rev == i) {
				record[counter] = i;
				counter++;
			}

		}

		printf("the palindromic number is:\n");

		for(i = 0; i < counter; ++i) {

			printf("%d ", record[i]);

			if((i%10) == 0) printf("\n");

		}

		printf("\n");

	}while(value != -1);

	return EXIT_SUCCESS;
}
