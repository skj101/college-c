#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

int main() {
    struct Node* head = NULL;
    int option, data;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Delete at head\n");
        printf("4. Delete at tail\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newNodeHead = createNode(data);
                if (head) {
                    newNodeHead->next = head->next;
                    head->next = newNodeHead;
                }
                head = newNodeHead;
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newNodeTail = createNode(data);
                if (head) {
                    newNodeTail->next = head->next;
                    head->next = newNodeTail;
                    head = newNodeTail;
                } else {
                    head = newNodeTail;
                }
                break;
            case 3:
                if (head) {
                    struct Node* temp = head->next;
                    if (temp == head) {
                        free(temp);
                        head = NULL;
                    } else {
                        head->next = temp->next;
                        free(temp);
                    }
                } else {
                    printf("List is empty\n");
                }
                break;
            case 4:
                if (head) {
                    struct Node* temp = head->next;
                    if (temp == head) {
                        free(temp);
                        head = NULL;
                    } else {
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        free(head);
                        head = temp;
                    }
                } else {
                    printf("List is empty\n");
                }
                break;
            case 5:
                if (head) {
                    struct Node* temp = head->next;
                    do {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    } while (temp != head->next);
                    printf("\n");
                } else {
                    printf("List is empty\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}
