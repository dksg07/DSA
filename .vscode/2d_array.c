#include<stdio.h>
int main(){
    int TwoDArray[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter element at index %d %d :",i,j);
            scanf("%d",&TwoDArray[i][j]);
        }
    }
    printf("Your Two D Array \n:");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",TwoDArray[i][j]);
        }
        printf("\n");

    }
    return 0;
}