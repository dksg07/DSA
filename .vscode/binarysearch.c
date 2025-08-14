#include<stdio.h>
int main(){
    int arr[]={0,1,1,2,4,6,6,8,8,10}; // Sorted array for binary search
    int size=sizeof(arr)/sizeof(arr[0]);
    // binary search
    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);
    int front=0,end=size-1; // Fixed: end should be size-1
    while(front<=end){
        int mid = (front+end)/2;
        if (key==arr[mid]){
            printf("Element found at index %d.\n", mid);
            return 0;
        }
        else if(key<arr[mid]){
            end = mid-1;
        }
        else{
            front = mid+1;
        }
    }

    printf("Element not found using binary search.\n");
    return 0;
}