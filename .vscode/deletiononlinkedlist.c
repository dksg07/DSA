#include <stdio.h>
#include <stdlib.h>

// Structure for a node in linked list
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

//----------------------------------------------------------------
// createNode() - Creates a new node with given data
//----------------------------------------------------------------
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

//----------------------------------------------------------------
// displayList() - Display all elements in linked list
//----------------------------------------------------------------
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
        printf("%d", temp->data);
        temp = temp->next;
        
        // Print arrow if not the last element
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    
    printf("\n");
}

//----------------------------------------------------------------
// insertAtBeginning() - Insert a node at the beginning
//----------------------------------------------------------------
void insertAtBeginning(int data) {
    // Create a new node
    struct Node* newNode = createNode(data);
    
    // Make new node point to current head
    newNode->next = head;
    
    // Update head to point to new node
    head = newNode;
}

//----------------------------------------------------------------
// insertAtEnd() - Insert a node at the end
//----------------------------------------------------------------
void insertAtEnd(int data) {
    // Create a new node
    struct Node* newNode = createNode(data);
    
    // If list is empty, make new node the head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // Otherwise, find the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the new node at the end
    temp->next = newNode;
}

//----------------------------------------------------------------
// 1. deleteFirst() - Delete the first node
//----------------------------------------------------------------
void deleteFirst() {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // Save reference to head node
    struct Node* temp = head;
    
    // Update head to point to the second node
    head = head->next;
    
    // Free the old head node
    printf("Deleted first node with data: %d\n", temp->data);
    free(temp);
}

//----------------------------------------------------------------
// 2. deleteLast() - Delete the last node
//----------------------------------------------------------------
void deleteLast() {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // If only one node exists
    if (head->next == NULL) {
        printf("Deleted last node with data: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    
    // Find second last node
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Delete the last node
    printf("Deleted last node with data: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

//----------------------------------------------------------------
// 3. deleteAtPosition() - Delete the node at given position
//----------------------------------------------------------------
void deleteAtPosition(int position) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // If position is 0, delete first node
    if (position == 0) {
        deleteFirst();
        return;
    }
    
    // Find node at position-1
    struct Node* temp = head;
    int i;
    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    // If position is beyond the length of the list
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is beyond list length\n", position);
        return;
    }
    
    // Save reference to the node to be deleted
    struct Node* nodeToDelete = temp->next;
    
    // Update the link to bypass the deleted node
    temp->next = temp->next->next;
    
    // Free the node
    printf("Deleted node at position %d with data: %d\n", position, nodeToDelete->data);
    free(nodeToDelete);
}

//----------------------------------------------------------------
// 4. deleteByValue() - Delete the first occurrence of a value
//----------------------------------------------------------------
void deleteByValue(int value) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // If head node contains the value
    if (head->data == value) {
        deleteFirst();
        return;
    }
    
    // Find the node with the value
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    // If value not found
    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }
    
    // Bypass the node to be deleted
    prev->next = temp->next;
    
    // Free the node
    printf("Deleted node with value %d\n", value);
    free(temp);
}

//----------------------------------------------------------------
// 5. deleteAllOccurrences() - Delete all occurrences of a value
//----------------------------------------------------------------
void deleteAllOccurrences(int value) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // Counter for deleted nodes
    int count = 0;
    
    // Delete all matching nodes at the beginning
    while (head != NULL && head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        count++;
    }
    
    // If list becomes empty
    if (head == NULL) {
        printf("Deleted %d occurrence(s) of value %d\n", count, value);
        return;
    }
    
    // Check rest of the list
    struct Node* temp = head;
    
    while (temp->next != NULL) {
        if (temp->next->data == value) {
            // Save node to be deleted
            struct Node* nodeToDelete = temp->next;
            
            // Bypass the node
            temp->next = temp->next->next;
            
            // Free the node
            free(nodeToDelete);
            count++;
        } else {
            // Move to next node only if no deletion
            temp = temp->next;
        }
    }
    
    printf("Deleted %d occurrence(s) of value %d\n", count, value);
}

//----------------------------------------------------------------
// 6. deleteAfterNode() - Delete node after a given node
//----------------------------------------------------------------
void deleteAfterNode(struct Node* prevNode) {
    // Check if previous node is NULL
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    // Check if it's the last node
    if (prevNode->next == NULL) {
        printf("No node to delete after given node\n");
        return;
    }
    
    // Save reference to the node to be deleted
    struct Node* nodeToDelete = prevNode->next;
    
    // Update the link
    prevNode->next = nodeToDelete->next;
    
    // Free the node
    printf("Deleted node with data %d after node with data %d\n", 
           nodeToDelete->data, prevNode->data);
    free(nodeToDelete);
}

//----------------------------------------------------------------
// 7. deleteEntireList() - Delete the entire list
//----------------------------------------------------------------
void deleteEntireList() {
    // Check if list is empty
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    
    // Counter for deleted nodes
    int count = 0;
    
    // Delete each node
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
        count++;
    }
    
    // Reset head pointer
    head = NULL;
    printf("Deleted entire list with %d node(s)\n", count);
}

//----------------------------------------------------------------
// 8. deleteAlternateNodes() - Delete alternate nodes
//----------------------------------------------------------------
void deleteAlternateNodes() {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    // Counter for deleted nodes
    int count = 0;
    
    struct Node* current = head;
    
    while (current != NULL && current->next != NULL) {
        // Save node to be deleted
        struct Node* nodeToDelete = current->next;
        
        // Update the link
        current->next = current->next->next;
        
        // Free the node
        free(nodeToDelete);
        count++;
        
        // Move to next node (after skipping one)
        current = current->next;
    }
    
    printf("Deleted %d alternate node(s)\n", count);
}

//----------------------------------------------------------------
// main() - Entry point of the program
//----------------------------------------------------------------
int main() {
    // Demonstration of all deletion types in linked list
    printf("---- LINKED LIST DELETION OPERATIONS ----\n\n");
    
    // Create a list for demonstration
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(20);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(30);
    insertAtEnd(60);
    
    printf("Initial ");
    displayList();
    
    // 1. Delete first node
    deleteFirst();
    printf("After deleting first node: ");
    displayList();
    
    // 2. Delete last node
    deleteLast();
    printf("After deleting last node: ");
    displayList();
    
    // 3. Delete at position
    deleteAtPosition(2);
    printf("After deleting node at position 2: ");
    displayList();
    
    // 4. Delete by value
    deleteByValue(20);
    printf("After deleting first occurrence of 20: ");
    displayList();
    
    // 5. Delete all occurrences
    // First, add more instances of a value
    insertAtBeginning(30);
    insertAtEnd(30);
    printf("After adding more 30s: ");
    displayList();
    
    deleteAllOccurrences(30);
    printf("After deleting all occurrences of 30: ");
    displayList();
    
    // 6. Delete after node (delete after first node)
    if (head != NULL) {
        deleteAfterNode(head);
        printf("After deleting node after first node: ");
        displayList();
    }
    
    // 8. Delete alternate nodes
    // First, build a longer list
    insertAtBeginning(5);
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    printf("New list for alternate deletion: ");
    displayList();
    
    deleteAlternateNodes();
    printf("After deleting alternate nodes: ");
    displayList();
    
    // 7. Delete entire list (last operation)
    deleteEntireList();
    printf("After deleting entire list: ");
    displayList();
    
    return 0;
}

/*
 * LINKED LIST DELETION OPERATIONS
 * 
 * Linked List is a linear data structure where elements are stored in nodes,
 * and each node points to the next node in the sequence.
 * 
 * This implementation demonstrates all common types of deletion operations
 * in a singly linked list.
 * 
 * Deletion Operations Implemented:
 * 
 * 1. Delete First Node: O(1)
 *    - Removes the first node (head) of the list
 *    - Updates the head pointer
 * 
 * 2. Delete Last Node: O(n)
 *    - Removes the last node of the list
 *    - Requires traversal to find the second-last node
 * 
 * 3. Delete at Position: O(n)
 *    - Removes a node at a specific position
 *    - Requires traversal to find the node at position-1
 * 
 * 4. Delete by Value: O(n)
 *    - Removes the first occurrence of a node with a specific value
 *    - Requires searching for the value
 * 
 * 5. Delete All Occurrences: O(n)
 *    - Removes all nodes with a specific value
 *    - Requires full traversal of the list
 * 
 * 6. Delete After Node: O(1)
 *    - Removes the node that follows a specific node
 *    - Requires reference to the previous node
 * 
 * 7. Delete Entire List: O(n)
 *    - Removes all nodes from the list
 *    - Frees all allocated memory
 * 
 * 8. Delete Alternate Nodes: O(n)
 *    - Removes every other node from the list
 *    - Skips one node after each deletion
 */

/*
 * DELETE FIRST NODE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is empty" and go to Step 6.
 * Step 3: Create a temporary pointer and point it to head.
 * Step 4: Move head to the next node (head = head->next).
 * Step 5: Free the memory of the node pointed by the temporary pointer.
 * Step 6: Stop.
 */

/*
 * DELETE LAST NODE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is empty" and go to Step 8.
 * Step 3: If there is only one node (head->next is NULL):
 *         a. Free the head node.
 *         b. Set head to NULL.
 *         c. Go to Step 8.
 * Step 4: Initialize a temp pointer to head.
 * Step 5: Traverse until temp->next->next is NULL (finding second last node).
 * Step 6: Free the memory of temp->next (last node).
 * Step 7: Set temp->next to NULL.
 * Step 8: Stop.
 */

/*
 * DELETE AT POSITION ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is empty" and go to Step 9.
 * Step 3: If position is 0, call deleteFirst() and go to Step 9.
 * Step 4: Initialize a temp pointer to head.
 * Step 5: Traverse temp to position-1 or until end of list is reached.
 * Step 6: If temp is NULL or temp->next is NULL, display "Position is beyond list length" and go to Step 9.
 * Step 7: Create a pointer to the node to be deleted (temp->next).
 * Step 8: Update temp->next to temp->next->next and free the node to be deleted.
 * Step 9: Stop.
 */

/*
 * DELETE BY VALUE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is empty" and go to Step 9.
 * Step 3: If head node has the value, call deleteFirst() and go to Step 9.
 * Step 4: Initialize temp and prev pointers (temp = head, prev = NULL).
 * Step 5: Traverse while temp is not NULL and temp's data is not the target value.
 * Step 6: If temp is NULL, display "Value not found" and go to Step 9.
 * Step 7: Set prev->next to temp->next.
 * Step 8: Free the temp node.
 * Step 9: Stop.
 */

/*
 * DELETE ALL OCCURRENCES ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is empty" and go to Step 10.
 * Step 3: Initialize a counter for deleted nodes to 0.
 * Step 4: While head is not NULL and head's data equals the target value:
 *         a. Save the head node address in a temp pointer.
 *         b. Move head to next node.
 *         c. Free the temp node.
 *         d. Increment the counter.
 * Step 5: If list became empty, display deletion count and go to Step 10.
 * Step 6: Initialize temp pointer to head.
 * Step 7: Traverse while temp->next is not NULL.
 * Step 8: If temp->next's data equals target value:
 *         a. Save the node address in a pointer.
 *         b. Update temp->next to skip this node.
 *         c. Free the saved node.
 *         d. Increment the counter.
 *         e. Do not move temp (recheck the new next node).
 *       Else:
 *         f. Move temp to next node.
 * Step 9: Display deletion count.
 * Step 10: Stop.
 */

/*
 * DELETE AFTER NODE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If given previous node is NULL, display error and go to Step 7.
 * Step 3: If previous node is the last node (prev->next is NULL), display "No node to delete" and go to Step 7.
 * Step 4: Create a pointer to the node to be deleted (prev->next).
 * Step 5: Set prev->next to skip the node to be deleted (prev->next = nodeToDelete->next).
 * Step 6: Free the node to be deleted.
 * Step 7: Stop.
 */

/*
 * DELETE ENTIRE LIST ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is already empty" and go to Step 8.
 * Step 3: Initialize counter for deleted nodes to 0.
 * Step 4: Initialize current pointer to head and next pointer to NULL.
 * Step 5: While current is not NULL:
 *         a. Save the next node address (next = current->next).
 *         b. Free the current node.
 *         c. Move current to next.
 *         d. Increment the counter.
 * Step 6: Set head to NULL.
 * Step 7: Display deletion count.
 * Step 8: Stop.
 */

/*
 * DELETE ALTERNATE NODES ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If the list is empty, display "List is empty" and go to Step 8.
 * Step 3: Initialize counter for deleted nodes to 0.
 * Step 4: Initialize current pointer to head.
 * Step 5: While current is not NULL and current->next is not NULL:
 *         a. Save the node to be deleted (nodeToDelete = current->next).
 *         b. Update current->next to skip this node (current->next = current->next->next).
 *         c. Free the saved node.
 *         d. Increment the counter.
 *         e. Move current to the next node (which was originally two nodes away).
 * Step 6: Display deletion count.
 * Step 7: Stop.
 */
