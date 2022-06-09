#include <stdio.h>

#define MONTH_OF_YEAR 12

// the days of month
int months[MONTH_OF_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int sum(int *arr, int size) {
    
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return sum;
}



int main(int argc, char** argv) {
    
    int days = 0;
    int month = 0;
    int day = 0;
    int total = 0;
    
    
    printf("please input days:");
    scanf("%d", &days);
        
    total = sum(months, MONTH_OF_YEAR);
    
    if (days > total) {
        printf("the input value is large than one year!!!\n");
        printf("Please try again!!!\n");
        return 0;
    }
    
    
    // process
    for (int i = 0; i < MONTH_OF_YEAR; i++) {
        
        if (days < months[i]) {
            month = i+1;
            day = days;
            break;
        } 
        
        days = days - months[i];
        
    }
    printf("result: %d/%d\n", month, day);
    

    return 0;
}