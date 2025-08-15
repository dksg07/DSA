#include <stdio.h> // yeh library input-output ke liye hoti hai (printf, scanf)

int main() {
    // Apna array banaya jisme random numbers hai (unsorted)
    int arr[] = {6, 2, 6, 8, 1, 1, 0, 4, 8, 2};

    // Array ka size nikalna: total bytes / ek element ka size
    int n = sizeof(arr) / sizeof(arr[0]);

    // ---------------- Insertion Sort Start ----------------
    // Loop i = 1 se shuru hoga kyunki pehla element (index 0) apne aap sorted hai
    for (int i = 1; i < n; i++) {

        // current me hum woh element store karenge jisko insert karna hai sahi jagah pe
        int current = arr[i];

        // j ko i ke ek pehle wale index pe set kiya, yeh sorted part ka last index hoga
        int j = i - 1;

        // Jab tak j 0 se bada hai aur arr[j] current se bada hai
        // tab tak elements ko right shift karte rahenge
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j]; // element ko ek step right me shift kiya
            j--; // ek step left move kiya
        }

        // Ab current element ko uske sahi position pe insert kar diya
        arr[j + 1] = current;
    }
    // ---------------- Insertion Sort End ----------------

    // Sorted array print karna
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // har element ke baad ek space
    }

    return 0; 
}
// heisdk
/**
 * Insertion Sort Algorithm
 * 
 * A simple sorting algorithm that builds the final sorted array one item at a time.
 * It works by taking elements from the unsorted portion and inserting them into
 * their correct position in the sorted portion of the array.
 * 
 * Algorithm Properties:
 * - Stable: Equal elements maintain their relative order
 * - In-place: Requires only O(1) additional memory
 * - Adaptive: Performs better on nearly sorted data
 * - Online: Can sort data as it receives it
 * 
 * Time Complexities:
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n²) - when elements are in random order
 * - Worst Case: O(n²) - when array is sorted in reverse order
 * 
 * Space Complexity: O(1) - constant extra space
 * 
 * Use Cases:
 * - Small datasets (typically n < 50)
 * - Nearly sorted arrays
 * - As a subroutine in hybrid algorithms like Quicksort
 * 
 * Algorithm Steps:
 * Step 1: Start
 * Step 2: Read the array arr[] and the number of elements n.
 * Step 3: Set loop counter i = 1 (assuming first element is sorted).
 * Step 4: Repeat Steps 5–11 while i < n.
 * Step 5: Set current = arr[i] (element to be inserted).
 * Step 6: Set j = i - 1 (last index of sorted portion).
 * Step 7: Repeat Steps 8–9 while j >= 0 AND arr[j] > current.
 * Step 8: Set arr[j + 1] = arr[j] (shift element to right).
 * Step 9: Decrement j by 1 and go back to Step 7.
 * Step 10: Set arr[j + 1] = current (insert element at correct position).
 * Step 11: Increment i by 1 and go back to Step 4.
 * Step 12: Print the sorted array.
 * Step 13: Stop.
 */