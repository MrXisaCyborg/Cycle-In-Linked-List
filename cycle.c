#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect cycle using Floyd’s Algorithm
int hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Cycle detected
        }
    }
    return 0; // No cycle
}

// Main function to test the cycle detection
int main() {
    // Create nodes
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Introduce a cycle: point last node to second node
    head->next->next->next->next->next = head->next;

    // Check for cycle
    if (hasCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle found in the linked list.\n");
    }

    return 0;
}
