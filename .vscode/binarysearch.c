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

/*
 * BINARY SEARCH ALGORITHM
 * 
 * Binary Search is an efficient algorithm for finding an item from a sorted list of items.
 * It works by repeatedly dividing the search interval in half and comparing the target 
 * value to the middle element of the interval.
 * 
 * Algorithm Steps:
 * 1. Compare target with the middle element of the array
 * 2. If target equals middle element, return the index
 * 3. If target is greater than middle element, search the right half
 * 4. If target is smaller than middle element, search the left half
 * 5. Repeat until target is found or interval is empty
 * 
 * Prerequisites:
 * - Array must be sorted in ascending or descending order
 * - Random access to array elements (arrays work best)
 * 
 * Algorithm Properties:
 * - Divide and conquer approach
 * - Logarithmic time complexity
 * - Requires sorted input
 * - More efficient than linear search for large datasets
 * 
 * Time Complexities:
 * - Best Case:    O(1) - when target is at the middle position
 * - Average Case: O(log n) - typical case
 * - Worst Case:   O(log n) - when target is at the end or not present
 * 
 * Space Complexity: 
 * - Iterative: O(1) - constant space
 * - Recursive: O(log n) - due to function call stack
 * 
 * Advantages:
 * - Much faster than linear search for large datasets
 * - Predictable performance
 * 
 * Disadvantages:
 * - Requires sorted array
 * - Not suitable for linked lists (no random access)
 * 
 * Bookish Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the sorted array arr[] and the number of elements n.
 * Step 3: Read the key element to be searched.
 * Step 4: Set front = 0 and end = n - 1.
 * Step 5: Repeat Steps 6–10 while front <= end.
 * Step 6: Calculate mid = (front + end) / 2.
 * Step 7: If key == arr[mid], print "Element found at index mid" and go to Step 12.
 * Step 8: If key < arr[mid], set end = mid - 1.
 * Step 9: If key > arr[mid], set front = mid + 1.
 * Step 10: Go back to Step 5.
 * Step 11: If loop ends without finding key, print "Element not found".
 * Step 12: Stop.
 */