#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node *next;
};
 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
 
void removeAtIndex(struct Node** head, int index) {
    if (*head == NULL || index < 0) return;
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
 
void removeElement(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
 
void display(struct Node* head) {
    struct Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
 
int main() {
        int n1,n2,n3;
    struct Node* dynamicArray = NULL;
    printf("enter the elements \n");
    scanf("%d %d %d",&n1,&n2,&n3);
    append(&dynamicArray, n1);
    append(&dynamicArray, n2);
    append(&dynamicArray, n3);
    printf("Dynamic Array: ");
    display(dynamicArray);
    removeAtIndex(&dynamicArray, 1);
    printf("Dynamic Array after removing index 1: ");
    display(dynamicArray);
    removeElement(&dynamicArray, 10);
    printf("Dynamic Array after removing element 10: ");
    display(dynamicArray);
    return 0;
}
