#include <stdio.h>
#include <stdlib.h>

// Node structure for Linked List
struct Node {
    int data;        // Data part of node
    struct Node* next; // Pointer to next node
};

// Global head pointer (initially NULL - empty list)
struct Node* head = NULL;

// ------------------------------------------------------------
// createNode() - Creates a new node with given data
// ------------------------------------------------------------
struct Node* createNode(int data) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Initialize the node
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

// ------------------------------------------------------------
// insertAtBeginning() - Insert a node at the beginning
// ------------------------------------------------------------
void insertAtBeginning(int data) {
    // Create a new node
    struct Node* newNode = createNode(data);
    
    // Make new node point to current head
    newNode->next = head;
    
    // Update head to point to new node
    head = newNode;
    
    printf("Inserted %d at the beginning\n", data);
}

// ------------------------------------------------------------
// insertAtEnd() - Insert a node at the end
// ------------------------------------------------------------
void insertAtEnd(int data) {
    // Create a new node
    struct Node* newNode = createNode(data);
    
    // If list is empty, make new node the head
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d in empty list\n", data);
        return;
    }
    
    // Otherwise, find the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the new node at the end
    temp->next = newNode;
    
    printf("Inserted %d at the end\n", data);
}

// ------------------------------------------------------------
// insertAfter() - Insert after a specific node with given value
// ------------------------------------------------------------
void insertAfter(int afterValue, int newData) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, cannot insert after %d\n", afterValue);
        return;
    }
    
    // Search for the node with afterValue
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }
    
    // If node with afterValue not found
    if (temp == NULL) {
        printf("Node with value %d not found\n", afterValue);
        return;
    }
    
    // Create new node
    struct Node* newNode = createNode(newData);
    
    // Insert new node after the found node
    newNode->next = temp->next;
    temp->next = newNode;
    
    printf("Inserted %d after %d\n", newData, afterValue);
}

// ------------------------------------------------------------
// deleteNode() - Delete a node with given value
// ------------------------------------------------------------
void deleteNode(int value) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // If head node itself holds the value to be deleted
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node with value %d\n", value);
        return;
    }
    
    // Search for the node to be deleted
    struct Node* current = head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    // If value not found in linked list
    if (current == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }
    
    // Unlink the node from list and free memory
    prev->next = current->next;
    free(current);
    
    printf("Deleted node with value %d\n", value);
}

// ------------------------------------------------------------
// searchNode() - Search for a node with given value
// ------------------------------------------------------------
int searchNode(int value) {
    struct Node* current = head;
    int position = 0;
    
    // Traverse the list
    while (current != NULL) {
        // If value found, return position
        if (current->data == value) {
            return position;
        }
        
        // Move to next node and increment position
        current = current->next;
        position++;
    }
    
    // Value not found
    return -1;
}

// ------------------------------------------------------------
// displayList() - Display all elements in the linked list
// ------------------------------------------------------------
void displayList() {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // Traverse and print each node
    struct Node* temp = head;
    printf("Linked List: ");
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        
        // Print arrow if not the last element
        if (temp != NULL) {
            printf("-> ");
        }
    }
    
    printf("\n");
}

// ------------------------------------------------------------
// countNodes() - Count number of nodes in the linked list
// ------------------------------------------------------------
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    
    // Traverse and count each node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// ------------------------------------------------------------
// freeList() - Free all nodes in the linked list
// ------------------------------------------------------------
void freeList() {
    struct Node* current = head;
    struct Node* next = NULL;
    
    // Traverse and free each node
    while (current != NULL) {
        next = current->next; // Save next node
        free(current);        // Free current node
        current = next;       // Move to next node
    }
    
    head = NULL; // Reset head
    printf("Freed all nodes from memory\n");
}

// ------------------------------------------------------------
// main() - Entry point of the program
// ------------------------------------------------------------
int main() {
    // Demonstrate linked list operations
    printf("---- Linked List Implementation ----\n\n");
    
    // Insert elements
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);
    insertAfter(10, 15);
    displayList();
    
    // Search and count
    int position = searchNode(15);
    if (position != -1) {
        printf("Value 15 found at position: %d\n", position);
    } else {
        printf("Value 15 not found\n");
    }
    
    printf("Total nodes: %d\n", countNodes());
    
    // Delete operations
    deleteNode(5);
    displayList();
    deleteNode(30);
    displayList();
    deleteNode(100); // Try to delete non-existent value
    
    // Free memory before exit
    freeList();
    
    return 0;
}

/*
 * Linked List Data Structure
 * 
 * A linked list is a linear data structure where each element (node) contains data 
 * and a reference (link) to the next node in the sequence. The last node points to NULL,
 * indicating the end of the list.
 * 
 * Types of Linked Lists:
 * 1. Singly Linked List - Each node points to the next node
 * 2. Doubly Linked List - Each node points to both next and previous nodes
 * 3. Circular Linked List - Last node points back to the first node
 * 
 * Properties:
 * - Dynamic data structure (can grow/shrink during execution)
 * - Non-contiguous memory allocation
 * - Efficient insertion and deletion operations
 * - Random access not allowed (sequential access only)
 * 
 * Time Complexities:
 * - Access: O(n) - Need to traverse from head
 * - Search: O(n) - Need to compare each element
 * - Insertion: O(1) - If we have reference to the position
 * - Deletion: O(1) - If we have reference to the node
 * 
 * Space Complexity: O(n) - Linear space for n nodes
 * 
 * Advantages:
 * - Dynamic size (no need to declare size beforehand)
 * - Efficient insertions/deletions (no shifting required)
 * - Memory efficient (allocated as needed)
 * 
 * Disadvantages:
 * - Extra memory for storing pointers
 * - Sequential access only (no random access)
 * - Reverse traversing not possible in singly linked list
 * 
 * Common Operations and Their Bookish Algorithms:
 */

/*
 * INSERTION ALGORITHM (At Beginning)
 * 
 * Step 1: Start
 * Step 2: Create a new node with given data.
 * Step 3: Set new node's next pointer to current head.
 * Step 4: Set head pointer to new node.
 * Step 5: Stop.
 */

/*
 * INSERTION ALGORITHM (At End)
 * 
 * Step 1: Start
 * Step 2: Create a new node with given data.
 * Step 3: If list is empty, make new node the head and go to Step 7.
 * Step 4: Initialize temp pointer to head.
 * Step 5: Traverse the list until temp->next is NULL.
 * Step 6: Set temp->next to point to the new node.
 * Step 7: Stop.
 */

/*
 * DELETION ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If list is empty, display "List is empty" and go to Step 8.
 * Step 3: If head node contains the value to delete:
 *         a. Save head node address in temp.
 *         b. Move head to next node.
 *         c. Free temp node.
 *         d. Go to Step 8.
 * Step 4: Initialize current pointer to head and prev pointer to NULL.
 * Step 5: Traverse the list while current is not NULL and current's data is not target value:
 *         a. Set prev to current.
 *         b. Move current to next node.
 * Step 6: If current is NULL, display "Value not found" and go to Step 8.
 * Step 7: Otherwise:
 *         a. Set prev->next to current->next.
 *         b. Free current node.
 * Step 8: Stop.
 */

/*
 * SEARCH ALGORITHM
 * 
 * Step 1: Start
 * Step 2: Initialize current pointer to head and position counter to 0.
 * Step 3: Repeat Steps 4-5 while current is not NULL.
 * Step 4: If current node's data equals target value:
 *         a. Return position counter.
 * Step 5: Increment position counter and move current to next node.
 * Step 6: If loop completes without finding value, return -1 (not found).
 * Step 7: Stop.
 */

/*
 * TRAVERSAL ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If list is empty, display "List is empty" and go to Step 6.
 * Step 3: Initialize temp pointer to head.
 * Step 4: Repeat Step 5 while temp is not NULL.
 * Step 5: Print temp's data and move temp to next node.
 * Step 6: Stop.
 */
