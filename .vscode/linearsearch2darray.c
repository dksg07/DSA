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
                printf("The index at which the key %d is present is : %d %d\n",key,i,j);
                flag=1;
                return 0;
            }
        }
    }
    if (flag == 0){
        printf("Element NOT found");
    }
    return 0;
}

/*
 * LINEAR SEARCH IN 2D ARRAY ALGORITHM
 * 
 * Linear Search in 2D Array is an extension of the basic linear search algorithm
 * that searches for a target element in a two-dimensional array by checking each
 * element row by row until the target is found or all elements are checked.
 * 
 * Algorithm Steps:
 * 1. Start from the first row (index 0)
 * 2. For each row, iterate through all columns
 * 3. Compare each element with the target value
 * 4. If target is found, return the row and column indices
 * 5. If target is not found after checking all elements, return "not found"
 * 
 * Algorithm Properties:
 * - Simple nested loop implementation
 * - Works on both sorted and unsorted 2D arrays
 * - Searches in row-major order (row by row)
 * - No preprocessing required
 * 
 * Time Complexities:
 * - Best Case:    O(1) - when target is at position [0][0]
 * - Average Case: O(m×n) - when target is somewhere in the middle
 * - Worst Case:   O(m×n) - when target is at the last position or not present
 *   where m = number of rows, n = number of columns
 * 
 * Space Complexity: O(1) - only uses constant extra space
 * 
 * Use Cases:
 * - Searching in small 2D matrices
 * - When the matrix is unsorted
 * - When simplicity is preferred over performance
 * 
 * Note: For sorted 2D arrays, more efficient algorithms like binary search
 * or staircase search can be used for better performance.
 * 
 * Bookish Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the 2D array arr[m][n] with m rows and n columns.
 * Step 3: Read the key element to be searched.
 * Step 4: Set flag = 0 (to track if element is found).
 * Step 5: Set outer loop counter i = 0.
 * Step 6: Repeat Steps 7–12 while i < m.
 * Step 7: Set inner loop counter j = 0.
 * Step 8: Repeat Steps 9–11 while j < n.
 * Step 9: If arr[i][j] == key, print "Element found at position (i,j)", 
 *         set flag = 1, and go to Step 14.
 * Step 10: Increment j by 1 and go back to Step 8.
 * Step 11: Increment i by 1 and go back to Step 6.
 * Step 12: If flag == 0, print "Element not found".
 * Step 13: Stop.
 */