#include<stdio.h>
int main(){
    int twodarray[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int key;
    printf("enter key to search :");
    scanf("%d", &key);
    int flag = 0 ;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(twodarray[i][j]==key){
                printf("The index at which the key %d is present is : %d %d",key,i,j);
                flag=1;
                return;
            }
        }
    }
    if (flag == 0){
        printf("Element NOT found");
    }
    return 0;


}