#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/**
 * STACK DATA STRUCTURE
 * 
 * Definition: A stack is a linear data structure that follows the Last In First Out (LIFO) principle,
 * where the last element added is the first one to be removed.
 * 
 * Properties:
 * 1. LIFO (Last In First Out) behavior
 * 2. Operations occur at one end only (called the "top")
 * 3. Basic operations: push (insert), pop (remove), peek/top (view top element)
 * 4. Can be implemented using arrays or linked lists
 * 
 * Time Complexities:
 * - Push: O(1)
 * - Pop: O(1)
 * - Peek: O(1)
 * - IsEmpty: O(1)
 * - IsFull: O(1) (for array implementation only)
 * 
 * Space Complexity: O(n) where n is the maximum number of elements in the stack
 * 
 * Applications:
 * 1. Function call management (Call Stack)
 * 2. Expression evaluation and conversion
 * 3. Undo mechanisms in text editors
 * 4. Backtracking algorithms
 * 5. Browser history (back button functionality)
 * 6. Check for balanced parentheses in expressions
 */

/*******************************************/
/* IMPLEMENTATION 1: ARRAY-BASED STACK    */
/*******************************************/

#define MAX_SIZE 100

// Array-based stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} ArrayStack;

// Initialize array stack
void initArrayStack(ArrayStack* stack) {
    stack->top = -1;
}

// Check if array stack is empty
bool isArrayStackEmpty(ArrayStack* stack) {
    return stack->top == -1;
}

// Check if array stack is full
bool isArrayStackFull(ArrayStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the array stack
bool arrayStackPush(ArrayStack* stack, int data) {
    if (isArrayStackFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return false;
    }
    stack->arr[++stack->top] = data;
    return true;
}

// Pop an element from the array stack
bool arrayStackPop(ArrayStack* stack, int* data) {
    if (isArrayStackEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return false;
    }
    *data = stack->arr[stack->top--];
    return true;
}

// Peek the top element without removing it
bool arrayStackPeek(ArrayStack* stack, int* data) {
    if (isArrayStackEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return false;
    }
    *data = stack->arr[stack->top];
    return true;
}

// Get the size of the array stack
int arrayStackSize(ArrayStack* stack) {
    return stack->top + 1;
}

// Display the array stack elements
void displayArrayStack(ArrayStack* stack) {
    if (isArrayStackEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Array Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

/*******************************************/
/* IMPLEMENTATION 2: LINKED LIST STACK    */
/*******************************************/

// Node structure for linked list implementation
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list based stack structure
typedef struct {
    Node* top;
    int size;
} LinkedListStack;

// Initialize linked list stack
void initLinkedListStack(LinkedListStack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Check if linked list stack is empty
bool isLinkedListStackEmpty(LinkedListStack* stack) {
    return stack->top == NULL;
}

// Push an element onto the linked list stack
void linkedListStackPush(LinkedListStack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push %d\n", data);
        return;
    }
    
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop an element from the linked list stack
bool linkedListStackPop(LinkedListStack* stack, int* data) {
    if (isLinkedListStackEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return false;
    }
    
    Node* temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return true;
}

// Peek the top element without removing it
bool linkedListStackPeek(LinkedListStack* stack, int* data) {
    if (isLinkedListStackEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return false;
    }
    
    *data = stack->top->data;
    return true;
}

// Get the size of the linked list stack
int linkedListStackSize(LinkedListStack* stack) {
    return stack->size;
}

// Display the linked list stack elements
void displayLinkedListStack(LinkedListStack* stack) {
    if (isLinkedListStackEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    Node* current = stack->top;
    printf("Linked List Stack (top to bottom): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free memory allocated for linked list stack
void freeLinkedListStack(LinkedListStack* stack) {
    Node* current = stack->top;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    stack->top = NULL;
    stack->size = 0;
}

/*******************************************/
/* IMPLEMENTATION 3: DYNAMIC ARRAY STACK  */
/*******************************************/

typedef struct {
    int* arr;
    int top;
    int capacity;
} DynamicStack;

// Initialize dynamic stack
bool initDynamicStack(DynamicStack* stack, int initialCapacity) {
    stack->capacity = initialCapacity;
    stack->top = -1;
    stack->arr = (int*)malloc(initialCapacity * sizeof(int));
    return stack->arr != NULL;
}

// Check if dynamic stack is empty
bool isDynamicStackEmpty(DynamicStack* stack) {
    return stack->top == -1;
}

// Check if dynamic stack is full
bool isDynamicStackFull(DynamicStack* stack) {
    return stack->top == stack->capacity - 1;
}

// Resize dynamic stack
bool resizeDynamicStack(DynamicStack* stack) {
    int newCapacity = stack->capacity * 2;
    int* newArr = (int*)realloc(stack->arr, newCapacity * sizeof(int));
    
    if (newArr == NULL) {
        return false;
    }
    
    stack->arr = newArr;
    stack->capacity = newCapacity;
    return true;
}

// Push an element onto the dynamic stack
bool dynamicStackPush(DynamicStack* stack, int data) {
    if (isDynamicStackFull(stack)) {
        // Try to resize
        if (!resizeDynamicStack(stack)) {
            printf("Memory allocation failed! Cannot push %d\n", data);
            return false;
        }
    }
    
    stack->arr[++stack->top] = data;
    return true;
}

// Pop an element from the dynamic stack
bool dynamicStackPop(DynamicStack* stack, int* data) {
    if (isDynamicStackEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return false;
    }
    
    *data = stack->arr[stack->top--];
    return true;
}

// Peek the top element without removing it
bool dynamicStackPeek(DynamicStack* stack, int* data) {
    if (isDynamicStackEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return false;
    }
    
    *data = stack->arr[stack->top];
    return true;
}

// Get the size of the dynamic stack
int dynamicStackSize(DynamicStack* stack) {
    return stack->top + 1;
}

// Display the dynamic stack elements
void displayDynamicStack(DynamicStack* stack) {
    if (isDynamicStackEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Dynamic Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Free memory allocated for dynamic stack
void freeDynamicStack(DynamicStack* stack) {
    free(stack->arr);
    stack->arr = NULL;
    stack->top = -1;
    stack->capacity = 0;
}

/**
 * BOOKISH ALGORITHM: PUSH OPERATION
 * 
 * Step 1: Start
 * Step 2: Check if the stack is full
 * Step 3: If the stack is full, display "Stack Overflow" message and go to Step 7
 * Step 4: Increment the top pointer by 1
 * Step 5: Assign the data to the stack at the top pointer
 * Step 6: The element is inserted successfully
 * Step 7: Stop
 */

/**
 * BOOKISH ALGORITHM: POP OPERATION
 * 
 * Step 1: Start
 * Step 2: Check if the stack is empty
 * Step 3: If the stack is empty, display "Stack Underflow" message and go to Step 7
 * Step 4: Retrieve the element at the top pointer
 * Step 5: Decrement the top pointer by 1
 * Step 6: Return the retrieved element
 * Step 7: Stop
 */

/**
 * BOOKISH ALGORITHM: PEEK OPERATION
 * 
 * Step 1: Start
 * Step 2: Check if the stack is empty
 * Step 3: If the stack is empty, display "Stack is empty" message and go to Step 6
 * Step 4: Retrieve the element at the top pointer without modifying the top
 * Step 5: Return the retrieved element
 * Step 6: Stop
 */

// Main function to demonstrate different stack implementations
int main() {
    int choice, data, stackType;
    
    // Array-based stack
    ArrayStack arrayStack;
    initArrayStack(&arrayStack);
    
    // Linked list-based stack
    LinkedListStack listStack;
    initLinkedListStack(&listStack);
    
    // Dynamic array-based stack
    DynamicStack dynamicStack;
    initDynamicStack(&dynamicStack, 5);
    
    printf("\n=== STACK DEMONSTRATION ===\n");
    
    do {
        printf("\nChoose stack implementation:\n");
        printf("1. Array-based Stack\n");
        printf("2. Linked List-based Stack\n");
        printf("3. Dynamic Array-based Stack\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &stackType);
        
        if (stackType == 0) break;
        
        if (stackType < 1 || stackType > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        
        do {
            printf("\nStack Operations:\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Peek\n");
            printf("4. Check if Empty\n");
            printf("5. Get Size\n");
            printf("6. Display Stack\n");
            printf("7. Return to Stack Type Selection\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            
            switch (choice) {
                case 1: // Push
                    printf("Enter data to push: ");
                    scanf("%d", &data);
                    
                    switch (stackType) {
                        case 1:
                            if (arrayStackPush(&arrayStack, data)) {
                                printf("%d pushed to array stack\n", data);
                            }
                            break;
                        case 2:
                            linkedListStackPush(&listStack, data);
                            printf("%d pushed to linked list stack\n", data);
                            break;
                        case 3:
                            if (dynamicStackPush(&dynamicStack, data)) {
                                printf("%d pushed to dynamic stack\n", data);
                            }
                            break;
                    }
                    break;
                    
                case 2: // Pop
                    switch (stackType) {
                        case 1:
                            if (arrayStackPop(&arrayStack, &data)) {
                                printf("Popped %d from array stack\n", data);
                            }
                            break;
                        case 2:
                            if (linkedListStackPop(&listStack, &data)) {
                                printf("Popped %d from linked list stack\n", data);
                            }
                            break;
                        case 3:
                            if (dynamicStackPop(&dynamicStack, &data)) {
                                printf("Popped %d from dynamic stack\n", data);
                            }
                            break;
                    }
                    break;
                    
                case 3: // Peek
                    switch (stackType) {
                        case 1:
                            if (arrayStackPeek(&arrayStack, &data)) {
                                printf("Top element of array stack: %d\n", data);
                            }
                            break;
                        case 2:
                            if (linkedListStackPeek(&listStack, &data)) {
                                printf("Top element of linked list stack: %d\n", data);
                            }
                            break;
                        case 3:
                            if (dynamicStackPeek(&dynamicStack, &data)) {
                                printf("Top element of dynamic stack: %d\n", data);
                            }
                            break;
                    }
                    break;
                    
                case 4: // Check if Empty
                    switch (stackType) {
                        case 1:
                            printf("Array stack is %s\n", isArrayStackEmpty(&arrayStack) ? "empty" : "not empty");
                            break;
                        case 2:
                            printf("Linked list stack is %s\n", isLinkedListStackEmpty(&listStack) ? "empty" : "not empty");
                            break;
                        case 3:
                            printf("Dynamic stack is %s\n", isDynamicStackEmpty(&dynamicStack) ? "empty" : "not empty");
                            break;
                    }
                    break;
                    
                case 5: // Get Size
                    switch (stackType) {
                        case 1:
                            printf("Array stack size: %d\n", arrayStackSize(&arrayStack));
                            break;
                        case 2:
                            printf("Linked list stack size: %d\n", linkedListStackSize(&listStack));
                            break;
                        case 3:
                            printf("Dynamic stack size: %d\n", dynamicStackSize(&dynamicStack));
                            break;
                    }
                    break;
                    
                case 6: // Display Stack
                    switch (stackType) {
                        case 1:
                            displayArrayStack(&arrayStack);
                            break;
                        case 2:
                            displayLinkedListStack(&listStack);
                            break;
                        case 3:
                            displayDynamicStack(&dynamicStack);
                            break;
                    }
                    break;
                    
                case 7: // Return to stack type selection
                    break;
                    
                default:
                    printf("Invalid choice! Please try again.\n");
            }
            
        } while (choice != 7);
        
    } while (stackType != 0);
    
    // Clean up resources
    freeLinkedListStack(&listStack);
    freeDynamicStack(&dynamicStack);
    
    printf("\nStack demonstration completed.\n");
    return 0;
}
