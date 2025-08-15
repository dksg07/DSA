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

/*
 * LINEAR SEARCH ALGORITHM
 * 
 * Linear Search is a sequential search algorithm that finds the position of a target value 
 * within an array by checking each element of the array sequentially until a match is found 
 * or the whole array has been searched.
 * 
 * Algorithm Steps:
 * 1. Start from the leftmost element of the array
 * 2. Compare the target element with each element of the array one by one
 * 3. If target matches with an element, return the index
 * 4. If target doesn't match with any element, return "not found"
 * 
 * Algorithm Properties:
 * - Simple and straightforward implementation
 * - Works on both sorted and unsorted arrays
 * - No preprocessing required
 * - Sequential access pattern
 * 
 * Time Complexities:
 * - Best Case:    O(1) - when target is at the first position
 * - Average Case: O(n) - when target is somewhere in the middle
 * - Worst Case:   O(n) - when target is at the last position or not present
 * 
 * Space Complexity: O(1) - only uses constant extra space
 * 
 * Use Cases:
 * - Small datasets where simplicity is preferred
 * - Unsorted arrays where binary search cannot be applied
 * - When the cost of sorting outweighs the benefit of faster search
 * 
 * Bookish Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Read the key element to be searched.
 * Step 4: Set loop counter i = 0.
 * Step 5: Repeat Steps 6–7 while i < n.
 * Step 6: If arr[i] == key, print "Element found at index i" and go to Step 9.
 * Step 7: Increment i by 1 and go back to Step 5.
 * Step 8: If loop ends without finding key, print "Element not found".
 * Step 9: Stop.
 */