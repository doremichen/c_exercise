/**
 * Demo stars
 */
#include <stdio.h>

int main(int argc, char *argv[]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3+i; j++) {
            if (j < 2-i) {
                printf(" ");
            } else {
                printf("#");
            }
            
        }
        printf("\n");
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3+(2-i); j++) {
            if (j < i) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    
    
    printf("==============================\n");
    
    for (int i = 0; i < 5; i++) {
        if (i <= 2) {
            for (int j = 0; j < 5-(2-i); j++) {
                if (j < (2-i)) {
                    printf(" ");
                } 
                else {
                    printf("#");
                }
                
            }
            
        } 
        else {
            for (int j = 0; j < 5-(i-2); j++) {
                if (j < (i-2)) {
                    printf(" ");
                }
                else {
                    printf("#");
                }
                
            }
            
        }
        
        printf("\n");
    }
    

    return 0;
}