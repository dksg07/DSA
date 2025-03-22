#include <iostream> // For input and output operations

// Function to ensure the heap property for a subtree rooted at index 'i'
void heapify(int arr[], int n, int i) {
    int largest = i; // Start with the root
    int left = 2 * i + 1; // Index of left child
    int right = 2 * i + 2; // Index of right child

    // Check if the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if the root isn't the largest
    if (largest != i) {
        std::swap(arr[i], arr[largest]); // Swap root with the largest child
        heapify(arr, n, largest); // Recursively fix the affected subtree
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build a max heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) // Start from the last non-leaf node
        heapify(arr, n, i);

    // Step 2: One by one extract the elements from the heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // Move the current root to the end
        heapify(arr, i, 0); // Fix the reduced heap
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n"; // Newline for neat output
}

// Main function - the entry point of the program
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Array to sort
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements

    heapSort(arr, n); // Sort the array using heapSort

    std::cout << "Sorted array is \n"; // Display the result
    printArray(arr, n); // Print the sorted array
    return 0; // Indicate successful execution
}