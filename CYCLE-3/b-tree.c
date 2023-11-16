#include <stdio.h>
#include <stdlib.h>

typedef struct BTreeNode {
    int numKeys;
    int* keys;
    struct BTreeNode** children;
    int leaf;
} BTreeNode;

BTreeNode* createNode(int order) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->numKeys = 0;
    newNode->leaf = 1;
    newNode->keys = (int*)malloc((order - 1) * sizeof(int));
    newNode->children = (BTreeNode**)malloc(order * sizeof(BTreeNode*));

    for (int i = 0; i < order; ++i)
        newNode->children[i] = NULL;

    return newNode;
}

int search(BTreeNode* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i])
        ++i;

    if (i < root->numKeys && key == root->keys[i])
        return 1;

    return (root->leaf) ? 0 : search(root->children[i], key);
}

BTreeNode* insertNonFull(BTreeNode* node, int key, int order) {
    int i = node->numKeys - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            --i;
        }

        node->keys[i + 1] = key;
        ++node->numKeys;
    } else {
        while (i >= 0 && key < node->keys[i])
            --i;

        ++i;

        if (node->children[i] && node->children[i]->numKeys == order - 1) {
            splitChild(node, i, node->children[i], order);

            if (key > node->keys[i])
                ++i;
        }

        node->children[i] = insertNonFull(node->children[i], key, order);
    }

    return node;
}

BTreeNode* insert(BTreeNode* root, int key, int order) {
    if (root->numKeys == order - 1) {
        BTreeNode* newNode = createNode(order);
        newNode->children[0] = root;
        splitChild(newNode, 0, root, order);
        newNode = insertNonFull(newNode, key, order);
        return newNode;
    } else {
        return insertNonFull(root, key, order);
    }
}

void splitChild(BTreeNode* parent, int index, BTreeNode* child, int order) {
    BTreeNode* newNode = createNode(order);
    newNode->leaf = child->leaf;
    newNode->numKeys = order / 2;

    for (int i = 0; i < order / 2; ++i)
        newNode->keys[i] = child->keys[i + order / 2];

    if (!child->leaf) {
        for (int i = 0; i < order / 2 + 1; ++i)
            newNode->children[i] = child->children[i + order / 2];
    }

    child->numKeys = order / 2 - 1;

    for (int i = parent->numKeys; i > index; --i)
        parent->children[i + 1] = parent->children[i];

    parent->children[index + 1] = newNode;

    for (int i = parent->numKeys - 1; i >= index; --i)
        parent->keys[i + 1] = parent->keys[i];

    parent->keys[index] = child->keys[order / 2 - 1];
    ++parent->numKeys;
}

void display(BTreeNode* root, int level, int order) {
    if (root) {
        printf("Level %d: ", level);

        for (int i = 0; i < root->numKeys; ++i)
            printf("%d ", root->keys[i]);

        printf("\n");

        for (int i = 0; i <= root->numKeys; ++i)
            display(root->children[i], level + 1, order);
    } else if (level != 0) {
        printf("Level %d: (empty)\n", level);
    }
}

int main() {
    int order;
    printf("Enter the order of the B-tree (max 5): ");
    scanf("%d", &order);

    if (order < 2 || order > 5) {
        printf("Invalid order. Exiting...\n");
        return 1;
    }

    BTreeNode* root = createNode(order);
    int choice, key;

    do {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key, order);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key found!\n");
                else
                    printf("Key not found.\n");
                break;
            case 3:
                display(root, 0, order);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
