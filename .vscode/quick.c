#include <stdio.h> // printf ke liye standard header

// ------------------------------------------------------------
// partition() - Array ko do parts me todta hai pivot ke basis pe
// ------------------------------------------------------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element choose karte hain (last element)
    int i = low - 1;        // Chhota element ka index (start me -1 from low)

    // Loop to compare each element with pivot
    for (int j = low; j <= high - 1; j++) {
        // Agar current element pivot se chhota ya equal hai
        if (arr[j] <= pivot) {
            i++; // Chhota element ka area ek step aage
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Pivot ko correct position pe rakh do
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1); // Pivot ka final index return karo
}

// ------------------------------------------------------------
// quickSort() - Recursively array ko sort karta hai
// ------------------------------------------------------------
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition karo aur pivot ka position lo
        int pi = partition(arr, low, high);

        // Left side of pivot sort karo
        quickSort(arr, low, pi - 1);

        // Right side of pivot sort karo
        quickSort(arr, pi + 1, high);
    }
}

// ------------------------------------------------------------
// main() - Program ka entry point
// ------------------------------------------------------------
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Size calculate karo

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Quick Sort call
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
// heisdk

/**
 * Quick Sort Algorithm Implementation
 * 
 * Quick sort is a highly efficient divide-and-conquer sorting algorithm that works by
 * selecting a 'pivot' element from the array and partitioning the other elements into
 * two sub-arrays according to whether they are less than or greater than the pivot.
 * 
 * Properties:
 * - Divide-and-conquer algorithm
 * - In-place sorting (requires only O(log n) additional memory for recursion stack)
 * - Not stable (does not preserve relative order of equal elements)
 * - Comparison-based sorting algorithm
 * 
 * Time Complexities:
 * - Best Case: O(n log n) - occurs when pivot divides array into equal halves
 * - Average Case: O(n log n) - expected performance with random input
 * - Worst Case: O(n²) - occurs when pivot is always smallest/largest element
 * 
 * Space Complexity:
 * - Best/Average Case: O(log n) - for recursion stack
 * - Worst Case: O(n) - when recursion depth equals array size
 * 
 * The algorithm's performance heavily depends on the pivot selection strategy.
 * Common optimizations include choosing median-of-three as pivot or using
 * randomized pivot selection to avoid worst-case scenarios.
 * 
 * Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Call quickSort(arr, 0, n-1).
 * Step 4: In quickSort function:
 *         If low < high:
 * Step 5: Call partition(arr, low, high) and get pivot index pi.
 * Step 6: Recursively call quickSort(arr, low, pi-1).
 * Step 7: Recursively call quickSort(arr, pi+1, high).
 * Step 8: In partition function:
 * Step 9: Choose pivot = arr[high] (last element as pivot).
 * Step 10: Set i = low - 1 (index of smaller element).
 * Step 11: For j = low to high-1:
 * Step 12: If arr[j] <= pivot, increment i and swap arr[i] with arr[j].
 * Step 13: Swap arr[i+1] with arr[high] (place pivot in correct position).
 * Step 14: Return i+1 (pivot index).
 * Step 15: Print the sorted array.
 * Step 16: Stop.
 */