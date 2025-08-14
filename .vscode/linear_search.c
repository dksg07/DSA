#include<stdio.h>
int main(){
    int arr[]={6,2,6,8,1,1,0,4,8,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    // linear search
    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);

    int i;
    for(i=0 ;i<size ;i++){
        if(arr[i]==key){
            printf("The key %d found at index %d.\n",key,i);
            break;
        }
    }
    
    if(i == size){
        printf("Key NOT found\n");
    }
    return 0;

}