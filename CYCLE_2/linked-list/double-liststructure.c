#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    return newNode;
}

int main() {
    struct Node* head = NULL;
    int option, data, position;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at position\n");
        printf("4. Delete at head\n");
        printf("5. Delete at tail\n");
        printf("6. Delete at position\n");
        printf("7. Traverse\n");
        printf("8. Get size\n");
        printf("9. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newNode = createNode(data);
                newNode->next = head;
                if (head) head->prev = newNode;
                head = newNode;
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newNodeTail = createNode(data);
                if (head == NULL) head = newNodeTail;
                else {
                    struct Node* temp = head;
                    while (temp->next) temp = temp->next;
                    temp->next = newNodeTail;
                    newNodeTail->prev = temp;
                }
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter data: ");
                scanf("%d", &data);
                if (position == 0) {
                    struct Node* newNodePos = createNode(data);
                    newNodePos->next = head;
                    if (head) head->prev = newNodePos;
                    head = newNodePos;
                } else {
                    struct Node* newNodePos = createNode(data);
                    struct Node* temp = head;
                    for (int i = 0; i < position - 1 && temp; i++) temp = temp->next;
                    if (temp) {
                        newNodePos->next = temp->next;
                        newNodePos->prev = temp;
                        if (temp->next) temp->next->prev = newNodePos;
                        temp->next = newNodePos;
                    } else printf("Invalid position\n");
                }
                break;
            case 4:
                if (head) {
                    struct Node* temp = head;
                    head = temp->next;
                    if (head) head->prev = NULL;
                    free(temp);
                } else printf("List is empty\n");
                break;
            case 5:
                if (head) {
                    struct Node* temp = head;
                    while (temp->next) temp = temp->next;
                    if (temp->prev) temp->prev->next = NULL;
                    else head = NULL;
                    free(temp);
                } else printf("List is empty\n");
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                if (position == 0) {
                    if (head) {
                        struct Node* temp = head;
                        head = temp->next;
                        if (head) head->prev = NULL;
                        free(temp);
                    } else printf("List is empty\n");
                } else {
                    struct Node* temp = head;
                    for (int i = 0; i < position && temp; i++) temp = temp->next;
                    if (temp) {
                        if (temp->prev) temp->prev->next = temp->next;
                        if (temp->next) temp->next->prev = temp->prev;
                        free(temp);
                    } else printf("Invalid position\n");
                }
                break;
            case 7:
                struct Node* temp = head;
                while (temp) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
                break;
            case 8:
                temp = head;
                int size = 0;
                while (temp) {
                    size++;
                    temp = temp->next;
                }
                printf("Size of the list: %d\n", size);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}
