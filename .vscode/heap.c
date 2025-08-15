#include <stdio.h> 

// ------------------------------------------------------------
// heapify() - Given index ko "heap property" maintain karwata hai
// ------------------------------------------------------------
void heapify(int arr[], int n, int i) {
    int largest = i;         // Assume current index sabse bada hai
    int left = 2 * i + 1;    // Left child ka index
    int right = 2 * i + 2;   // Right child ka index

    // Agar left child exist karta hai aur bada hai largest se
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Agar right child exist karta hai aur bada hai largest se
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Agar largest change hua hai to swap karo
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify karo affected subtree ko
        heapify(arr, n, largest);
    }
}

// ------------------------------------------------------------
// heapSort() - Array ko heap bana ke sort karta hai
// ------------------------------------------------------------
void heapSort(int arr[], int n) {
    // Step 1: Max heap banate hain (bottom-up approach)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Ek-ek karke max element ko end me le jao
    for (int i = n - 1; i > 0; i--) {
        // Root (max) ko last element ke sath swap karo
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Reduced heap ko phir se heapify karo
        heapify(arr, i, 0);
    }
}

// ------------------------------------------------------------
// main() - Program ka starting point
// ------------------------------------------------------------
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Size calculate karo

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Heap Sort call
    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
// heisdk
/*
 * Heap Sort Algorithm
 * 
 * Definition:
 * Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure.
 * It divides the input into a sorted and an unsorted region, and iteratively shrinks the
 * unsorted region by extracting the largest element and moving it to the sorted region.
 * 
 * Properties:
 * - Not stable (does not preserve relative order of equal elements)
 * - In-place sorting algorithm (requires only O(1) extra memory)
 * - Comparison-based sorting algorithm
 * - Not adaptive (performance doesn't improve on partially sorted data)
 * 
 * Time Complexities:
 * - Best Case:    O(n log n) - when all elements are distinct
 * - Average Case: O(n log n) - typical random input
 * - Worst Case:   O(n log n) - even when input is already sorted
 * 
 * Space Complexity: O(1) - constant extra space
 * 
 * Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Build Max Heap:
 *         For i = n/2 - 1 down to 0:
 * Step 4: Call heapify(arr, n, i).
 * Step 5: Extract elements from heap:
 *         For i = n-1 down to 1:
 * Step 6: Swap arr[0] with arr[i] (move max to end).
 * Step 7: Call heapify(arr, i, 0) to restore heap property.
 * Step 8: In heapify function:
 * Step 9: Find largest among root and its children.
 * Step 10: If largest is not root, swap and recursively heapify affected subtree.
 * Step 11: Print the sorted array.
 * Step 12: Stop.
 */