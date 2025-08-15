#include <stdio.h>

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    // Outer loop: har pass me ek largest element end me chala jaata hai
    for (int i = 0; i < n - 1; i++) {  

        // Inner loop: current pass me adjacent elements compare hote hain
        for (int j = 0; j < n - i - 1; j++) {  
            
            // Agar current element next se bada hai to swap karo
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Har pass ke baad last i elements sorted ho jaate hain
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};                  // Initial array
    int n = sizeof(arr) / sizeof(arr[0]);         // Array size calculate

    printf("Original array: ");
    for (int i = 0; i < n; i++)                   // Print original
        printf("%d ", arr[i]);

    bubbleSort(arr, n);                           // Sorting function call

    printf("\nSorted array:   ");
    for (int i = 0; i < n; i++)                   // Print sorted
        printf("%d ", arr[i]);

    return 0;
}
// heisdk

/**
 * Bubble Sort Algorithm
 * 
 * A simple comparison-based sorting algorithm that repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * 
 * Algorithm Properties:
 * - Comparison-based sorting algorithm
 * - In-place sorting (requires only O(1) extra memory)
 * - Stable sorting (maintains relative order of equal elements)
 * - Adaptive (performs better on partially sorted arrays)
 * 
 * Time Complexities:
 * - Best Case:    O(n) - when array is already sorted
 * - Average Case: O(n²) - when elements are in random order
 * - Worst Case:   O(n²) - when array is sorted in reverse order
 * 
 * Space Complexity: O(1) - only uses constant extra space
 * 
 * Note: Despite its simplicity, bubble sort is inefficient for large datasets
 * due to its quadratic time complexity. It's primarily used for educational
 * purposes or very small datasets.
 * 
 * Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Set a loop counter i = 0.
 * Step 4: Repeat Steps 5–8 while i < n - 1.
 * Step 5: Set another loop counter j = 0.
 * Step 6: Repeat Steps 7–8 while j < n - i - 1.
 * Step 7: If arr[j] > arr[j + 1], swap arr[j] and arr[j + 1].
 * Step 8: Increment j by 1 and go back to Step 6.
 * Step 9: Increment i by 1 and go back to Step 4.
 * Step 10: Print the sorted array.
 * Step 11: Stop.
 */