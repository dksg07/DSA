#include <stdio.h> 
// merge() - Yeh function do sorted halves ko merge karta hai

void merge(int arr[], int left, int mid, int right) {
    // Pehle dono halves ke sizes nikalte hain
    int n1 = mid - left + 1; // Left half ka size
    int n2 = right - mid;    // Right half ka size

    // Temporary arrays banate hain left aur right ke liye
    int L[n1], R[n2];

    // Left half ke elements copy karo
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Right half ke elements copy karo
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge karne ke liye indexes
    int i = 0;     // Left array index
    int j = 0;     // Right array index
    int k = left;  // Original array index (merge position)

    // Dono arrays me se chhota element leke merge karo
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {   // Agar left ka element chhota ya equal hai
            arr[k] = L[i];
            i++;
        } else {              // Agar right ka element chhota hai
            arr[k] = R[j];
            j++;
        }
        k++; // Next position pe move
    }

    // Agar left array me elements bache hain to unhe copy karo
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Agar right array me elements bache hain to unhe copy karo
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ------------------------------------------------------------
// mergeSort() - Recursively array ko sort karta hai
// ------------------------------------------------------------
void mergeSort(int arr[], int left, int right) {
    if (left < right) { // Jab tak ek se zyada elements bache hain
        int mid = left + (right - left) / 2; // Middle index find karo

        // Left half sort karo
        mergeSort(arr, left, mid);

        // Right half sort karo
        mergeSort(arr, mid + 1, right);

        // Dono sorted halves ko merge karo
        merge(arr, left, mid, right);
    }
}

// ------------------------------------------------------------
// main() - Entry point of program
// ------------------------------------------------------------
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]);   // Array size nikalna

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Merge Sort function call
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0; 
}
// heisdk

/**
 * Merge Sort Algorithm
 * 
 * A divide-and-conquer sorting algorithm that recursively divides the array
 * into smaller subarrays, sorts them, and then merges them back together.
 * 
 * Properties:
 * - Stable: Maintains relative order of equal elements
 * - Not in-place: Requires O(n) additional memory space
 * - Divide-and-conquer: Recursively breaks problem into smaller subproblems
 * - Comparison-based: Uses element comparisons to determine order
 * 
 * Time Complexities:
 * - Best Case: O(n log n) - When array is already sorted
 * - Average Case: O(n log n) - For random order of elements
 * - Worst Case: O(n log n) - When array is reverse sorted
 * 
 * Space Complexity: O(n) - Due to auxiliary arrays used during merging
 * 
 * The algorithm works by:
 * 1. Dividing the array into two halves
 * 2. Recursively sorting both halves
 * 3. Merging the sorted halves back together
 * 
 * Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Call mergeSort(arr, 0, n-1).
 * Step 4: In mergeSort function:
 *         If left < right:
 * Step 5: Calculate mid = left + (right - left) / 2.
 * Step 6: Recursively call mergeSort(arr, left, mid).
 * Step 7: Recursively call mergeSort(arr, mid+1, right).
 * Step 8: Call merge(arr, left, mid, right).
 * Step 9: In merge function:
 * Step 10: Create temporary arrays for left and right subarrays.
 * Step 11: Copy elements to temporary arrays.
 * Step 12: Merge temporary arrays back into original array in sorted order.
 * Step 13: Print the sorted array.
 * Step 14: Stop.
 */