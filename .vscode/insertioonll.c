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
// 1. insertAtBeginning() - Insert a node at the beginning
//----------------------------------------------------------------
void insertAtBeginning(int data) {
    // Create a new node
    struct Node* newNode = createNode(data);
    
    // Make new node point to current head
    newNode->next = head;
    
    // Update head to point to new node
    head = newNode;
    
    printf("Inserted %d at the beginning\n", data);
}

//----------------------------------------------------------------
// 2. insertAtEnd() - Insert a node at the end
//----------------------------------------------------------------
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

//----------------------------------------------------------------
// 3. insertAfterNode() - Insert after a specific node
//----------------------------------------------------------------
void insertAfterNode(struct Node* prevNode, int data) {
    // Check if previous node is NULL
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    // Create a new node
    struct Node* newNode = createNode(data);
    
    // Make new node's next point to previous node's next
    newNode->next = prevNode->next;
    
    // Make previous node point to new node
    prevNode->next = newNode;
    
    printf("Inserted %d after node containing %d\n", data, prevNode->data);
}

//----------------------------------------------------------------
// 4. insertAfterValue() - Insert after a specific value
//----------------------------------------------------------------
void insertAfterValue(int afterValue, int newData) {
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
    
    // Create new node and insert after found node
    insertAfterNode(temp, newData);
}

//----------------------------------------------------------------
// 5. insertAtPosition() - Insert at a specific position
//----------------------------------------------------------------
void insertAtPosition(int data, int position) {
    // If position is 0, insert at beginning
    if (position == 0) {
        insertAtBeginning(data);
        return;
    }
    
    // Create new node
    struct Node* newNode = createNode(data);
    
    // Traverse to the position
    struct Node* temp = head;
    int currentPos = 0;
    
    // Find the node just before the position
    while (temp != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }
    
    // If position is beyond the list length
    if (temp == NULL) {
        printf("Position %d is beyond the list length\n", position);
        free(newNode);
        return;
    }
    
    // Insert the node at the position
    newNode->next = temp->next;
    temp->next = newNode;
    
    printf("Inserted %d at position %d\n", data, position);
}

//----------------------------------------------------------------
// 6. insertBeforeValue() - Insert before a specific value
//----------------------------------------------------------------
void insertBeforeValue(int beforeValue, int newData) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty, cannot insert before %d\n", beforeValue);
        return;
    }
    
    // If head contains the beforeValue
    if (head->data == beforeValue) {
        insertAtBeginning(newData);
        return;
    }
    
    // Search for the node just before the node with beforeValue
    struct Node* current = head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != beforeValue) {
        prev = current;
        current = current->next;
    }
    
    // If node with beforeValue not found
    if (current == NULL) {
        printf("Node with value %d not found\n", beforeValue);
        return;
    }
    
    // Create new node
    struct Node* newNode = createNode(newData);
    
    // Insert before found node
    newNode->next = current;
    prev->next = newNode;
    
    printf("Inserted %d before %d\n", newData, beforeValue);
}

//----------------------------------------------------------------
// 7. insertSorted() - Insert in a sorted linked list
//----------------------------------------------------------------
void insertSorted(int data) {
    // Create new node
    struct Node* newNode = createNode(data);
    
    // Special case for empty list
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at the beginning of sorted list\n", data);
        return;
    }
    
    // Locate the node before insertion point
    struct Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    // Insert new node after current
    newNode->next = current->next;
    current->next = newNode;
    
    printf("Inserted %d in sorted position\n", data);
}

//----------------------------------------------------------------
// freeList() - Free all nodes in the linked list
//----------------------------------------------------------------
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

//----------------------------------------------------------------
// main() - Entry point of the program
//----------------------------------------------------------------
int main() {
    // Demonstration of all insertion types in linked list
    printf("---- LINKED LIST INSERTION OPERATIONS ----\n\n");
    
    // 1. Insert at beginning
    insertAtBeginning(50);
    insertAtBeginning(40);
    insertAtBeginning(30);
    printf("After inserting at beginning: ");
    displayList();
    
    // 2. Insert at end
    insertAtEnd(60);
    insertAtEnd(70);
    printf("After inserting at end: ");
    displayList();
    
    // 3. Insert after specific node (3rd node)
    struct Node* temp = head;
    int pos = 0;
    while (temp != NULL && pos < 2) {
        temp = temp->next;
        pos++;
    }
    if (temp != NULL) {
        insertAfterNode(temp, 45);
    }
    printf("After inserting after 3rd node: ");
    displayList();
    
    // 4. Insert after value
    insertAfterValue(50, 55);
    printf("After inserting 55 after 50: ");
    displayList();
    
    // 5. Insert at position
    insertAtPosition(35, 2);
    printf("After inserting 35 at position 2: ");
    displayList();
    
    // 6. Insert before value
    insertBeforeValue(40, 38);
    printf("After inserting 38 before 40: ");
    displayList();
    
    // Create a new sorted list for demonstration
    printf("\n---- SORTED INSERTION DEMONSTRATION ----\n");
    freeList(); // Clear previous list
    
    // 7. Insert in sorted order
    insertSorted(30);
    insertSorted(10);
    insertSorted(50);
    insertSorted(20);
    insertSorted(40);
    printf("After inserting in sorted order: ");
    displayList();
    
    // Free memory
    freeList();
    
    return 0;
}

/*
 * LINKED LIST INSERTION OPERATIONS
 * 
 * Linked List is a linear data structure where elements are stored in nodes,
 * and each node points to the next node in the sequence.
 * 
 * This implementation demonstrates all common types of insertion operations
 * in a singly linked list.
 * 
 * Insertion Operations Implemented:
 * 
 * 1. Insert at Beginning: O(1)
 *    - Adds a new node at the start of the list
 *    - Requires updating the head pointer
 * 
 * 2. Insert at End: O(n)
 *    - Adds a new node at the end of the list
 *    - Requires traversing to the last node
 * 
 * 3. Insert after a specific node: O(1)
 *    - Adds a new node after a given node
 *    - Requires reference to the previous node
 * 
 * 4. Insert after a specific value: O(n)
 *    - Adds a new node after the first occurrence of a value
 *    - Requires searching for the value first
 * 
 * 5. Insert at a specific position: O(n)
 *    - Adds a new node at a given position
 *    - Requires traversing to that position
 * 
 * 6. Insert before a specific value: O(n)
 *    - Adds a new node before the first occurrence of a value
 *    - Requires tracking previous node during search
 * 
 * 7. Insert in a sorted list: O(n)
 *    - Adds a new node while maintaining sorted order
 *    - Special cases for insertion at beginning
 * 
 */

/*
 * INSERT AT BEGINNING ALGORITHM
 * 
 * Step 1: Start
 * Step 2: Create a new node with given data.
 * Step 3: Set new node's next pointer to current head.
 * Step 4: Update head to point to the new node.
 * Step 5: Stop.
 */

/*
 * INSERT AT END ALGORITHM
 * 
 * Step 1: Start
 * Step 2: Create a new node with given data.
 * Step 3: If list is empty, make head point to new node and go to Step 7.
 * Step 4: Initialize temp pointer to head.
 * Step 5: Traverse until temp->next is NULL (finding last node).
 * Step 6: Make last node's next pointer point to new node.
 * Step 7: Stop.
 */

/*
 * INSERT AFTER NODE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: Check if given previous node is NULL. If NULL, report error and go to Step 6.
 * Step 3: Create a new node with given data.
 * Step 4: Set new node's next pointer to previous node's next.
 * Step 5: Set previous node's next pointer to new node.
 * Step 6: Stop.
 */

/*
 * INSERT AFTER VALUE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If list is empty, report "list empty" and go to Step 8.
 * Step 3: Initialize temp pointer to head.
 * Step 4: Traverse list until a node with the target value is found or end is reached.
 * Step 5: If end is reached (temp is NULL), report "value not found" and go to Step 8.
 * Step 6: Create a new node with given data.
 * Step 7: Insert new node after the found node.
 * Step 8: Stop.
 */

/*
 * INSERT AT POSITION ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If position is 0, insert at beginning and go to Step 9.
 * Step 3: Create a new node with given data.
 * Step 4: Initialize temp pointer to head and position counter to 0.
 * Step 5: Traverse list until position-1 is reached or list ends.
 * Step 6: If list ends before reaching position-1, report "position beyond list length" and go to Step 9.
 * Step 7: Set new node's next to temp's next.
 * Step 8: Set temp's next to new node.
 * Step 9: Stop.
 */

/*
 * INSERT BEFORE VALUE ALGORITHM
 * 
 * Step 1: Start
 * Step 2: If list is empty, report "list empty" and go to Step 10.
 * Step 3: If head node contains the target value, insert at beginning and go to Step 10.
 * Step 4: Initialize current pointer to head and prev pointer to NULL.
 * Step 5: Traverse list until a node with target value is found or end is reached.
 * Step 6: If end is reached (current is NULL), report "value not found" and go to Step 10.
 * Step 7: Create a new node with given data.
 * Step 8: Set new node's next to current.
 * Step 9: Set prev's next to new node.
 * Step 10: Stop.
 */

/*
 * INSERT IN SORTED LIST ALGORITHM
 * 
 * Step 1: Start
 * Step 2: Create a new node with given data.
 * Step 3: If list is empty or new value is less than head's data:
 *         a. Set new node's next to head.
 *         b. Update head to point to new node.
 *         c. Go to Step 7.
 * Step 4: Initialize current pointer to head.
 * Step 5: Traverse while current's next is not NULL and current's next's data is less than new value.
 * Step 6: Insert new node between current and current's next.
 * Step 7: Stop.
 */
