#include<stdio.h>
    int main(){
        int size = 5;
        int array[size];
        for(int i = 0; i<5; i++){
            printf("enter element at index %d: ",i);
            scanf("%d",&array[i]);
        }
        
        printf("\nArray elements are:\n");
        for(int i = 0; i<5; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
        
        return 0;
    }