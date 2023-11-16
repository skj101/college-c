#include <stdio.h>
#include <stdlib.h>

// Node structure for a binomial heap
struct Node {
    int key, degree;
    struct Node *parent, *child, *sibling;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = newNode->child = newNode->sibling = NULL;
    return newNode;
}

// Function to merge two binomial trees of the same degree
struct Node* merge(struct Node* tree1, struct Node* tree2) {
    if (!tree1) return tree2;
    if (!tree2) return tree1;

    // Ensure tree1's root has a smaller key
    if (tree1->key > tree2->key) {
        struct Node* temp = tree1;
        tree1 = tree2;
        tree2 = temp;
    }

    // Merge tree2 into tree1
    tree2->parent = tree1;
    tree2->sibling = tree1->child;
    tree1->child = tree2;
    tree1->degree++;

    return tree1;
}

// Function to perform union of two binomial heaps
struct Node* unionBinomialHeap(struct Node* heap1, struct Node* heap2) {
    struct Node* result = NULL;
    struct Node* carry = NULL;
    struct Node* tree1 = heap1;
    struct Node* tree2 = heap2;

    // Merge individual binomial trees of the same degree
    while (tree1 || tree2 || carry) {
        struct Node* t1 = (tree1) ? tree1->sibling : NULL;
        struct Node* t2 = (tree2) ? tree2->sibling : NULL;

        int carryKey = (carry) ? carry->key : 0;

        // Merge three trees: tree1, tree2, and the carry tree
        struct Node* minTree = merge(merge(tree1, tree2), createNode(carryKey));
        result = merge(result, minTree);

        // Update carry tree for the next iteration
        carry = (minTree->degree == 0) ? NULL : minTree;

        tree1 = t1;
        tree2 = t2;
    }

    return result;
}

// Function to insert a key into a binomial heap
struct Node* insert(struct Node* heap, int key) {
    // Create a new binomial heap with a single key
    struct Node* newHeap = createNode(key);
    // Union the existing heap with the new heap
    return unionBinomialHeap(heap, newHeap);
}

// Function to extract the minimum key from a binomial heap
struct Node* extractMin(struct Node* heap) {
    if (!heap) return NULL;

    struct Node* minNode = heap;
    struct Node* prev = NULL;
    struct Node* current = heap;

    // Find the tree with the minimum root key
    while (current->sibling) {
        if (current->sibling->key < minNode->key) {
            minNode = current->sibling;
            prev = current;
        }
        current = current->sibling;
    }

    // Remove the tree with the minimum root
    if (prev) prev->sibling = minNode->sibling;
    else heap = minNode->sibling;

    // Union the removed tree's children with the heap
    struct Node* child = minNode->child;
    free(minNode);

    return unionBinomialHeap(heap, child);
}

// Function to display the binomial heap
void display(struct Node* heap) {
    if (!heap) return;

    printf("Binomial Heap: ");
    // Traverse through the binomial trees and display keys
    while (heap) {
        printf("%d ", heap->key);
        display(heap->child);
        heap = heap->sibling;
    }
    printf("\n");
}

// Driver program
int main() {
    struct Node* binomialHeap = NULL;

    int choice, key;

    // Interactive menu for user actions
    do {
        printf("\n1. Insert\n2. Delete Min\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                binomialHeap = insert(binomialHeap, key);
                break;
            case 2:
                binomialHeap = extractMin(binomialHeap);
                break;
            case 3:
                display(binomialHeap);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
