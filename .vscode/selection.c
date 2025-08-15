#include <stdio.h> 

int main() {
    // Apna unsorted array
    int arr[] = {64, 25, 12, 22, 11};

    // Total elements ka count nikalnae k liye
    int n = sizeof(arr) / sizeof(arr[0]);

    // ---------- Selection Sort Start ----------
    // Outer loop: yeh loop har position ko set karega correct element ke saath
    for (int i = 0; i < n - 1; i++) {
        
        // Maan lo ki current index ka element hi sabse chhota hai
        int minIndex = i;

        // Inner loop: current index ke baad ke elements me chhota element dhoondho
        for (int j = i + 1; j < n; j++) {
            // Agar koi element minIndex wale element se chhota mil jaye
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // uska index store kar lo
            }
        }

        // Agar minIndex change hua hai to swap karo
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    // ---------- Selection Sort End ----------

    // Sorted array print karna
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
// heisdk

/**
 * Selection Sort Algorithm
 * 
 * A simple comparison-based sorting algorithm that works by repeatedly finding
 * the minimum element from the unsorted portion of the array and placing it
 * at the beginning of the sorted portion.
 * 
 * Algorithm Properties:
 * - In-place sorting: Uses O(1) extra memory space
 * - Unstable: Does not preserve relative order of equal elements
 * - Not adaptive: Performance doesn't improve on partially sorted arrays
 * - Comparison-based: Uses element comparisons to determine order
 * 
 * Time Complexities:
 * - Best Case: O(n²) - Even when array is already sorted
 * - Average Case: O(n²) - For randomly ordered elements
 * - Worst Case: O(n²) - When array is sorted in reverse order
 * 
 * Space Complexity: O(1) - Only uses constant extra memory
 * 
 * Number of Swaps: O(n) - At most n-1 swaps (better than bubble sort)
 * Number of Comparisons: O(n²) - Always performs n(n-1)/2 comparisons
 * 
 * Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Set loop counter i = 0.
 * Step 4: Repeat Steps 5–10 while i < n - 1.
 * Step 5: Set minIndex = i (assume current element is minimum).
 * Step 6: Set inner loop counter j = i + 1.
 * Step 7: Repeat Steps 8–9 while j < n.
 * Step 8: If arr[j] < arr[minIndex], set minIndex = j.
 * Step 9: Increment j by 1 and go back to Step 7.
 * Step 10: If minIndex ≠ i, swap arr[i] and arr[minIndex].
 * Step 11: Increment i by 1 and go back to Step 4.
 * Step 12: Print the sorted array.
 * Step 13: Stop.
 */