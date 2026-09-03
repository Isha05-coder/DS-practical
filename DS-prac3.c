#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning() {
    struct Node *newNode;
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd() {
    struct Node *newNode, *temp;
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertPosition() {
    struct Node *newNode, *temp;
    int value, pos, i;

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertBeginning();
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

void deleteEnd() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deletePosition() {
    struct Node *temp, *deleteNode;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);
}

void displayBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("Beginning = %d\n", head->data);
    }
}

void displayPosition() {
    struct Node *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
    } else {
        printf("Element = %d\n", temp->data);
    }
}

void displayEnd() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("End = %d\n", temp->data);
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Position\n");
        printf("6. Delete from End\n");
        printf("7. Display Beginning\n");
        printf("8. Display Position\n");
        printf("9. Display End\n");
        printf("10. Display List\n");
        printf("11. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertPosition();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deletePosition();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                displayBeginning();
                break;

            case 8:
                displayPosition();
                break;

            case 9:
                displayEnd();
                break;

            case 10:
                display();
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}