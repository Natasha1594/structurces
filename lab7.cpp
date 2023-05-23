#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
//write  down a complete c/c++ program to test your linear linked list implementation. additionally, write another fumction, DisplayList( )which will be used to list the linked list content. function to calculate the size (length - number of elements) of the given linked list.Consider the following prototype:

//int sizeLL (struct node *header);
//Complete your implementation using the following code:
//struct node *header;
//header = (struct node *)malloc(sizeof(struct node));
//header->data = 2;
//header->next = (struct node *)malloc(sizeof(struct node));
//header->next->data = 4;
//header->next->next = (struct node *)malloc(sizeof(struct node));
//header->next->next->data = 6;
//header->next->next->next = NULL;
//DisplayList(header);






// Structure for a node
struct node {
    int data;
    struct node* next;
};

// Function to display the linked list
void DisplayList(struct node* header) {
    struct node* current = header;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to calculate the size of the linked list
int sizeLL(struct node* header) {
    int count = 0;
    struct node* current = header;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Create the linked list
    struct node* header = (struct node*)malloc(sizeof(struct node));
    header->data = 2;
    header->next = (struct node*)malloc(sizeof(struct node));
    header->next->data = 4;
    header->next->next = (struct node*)malloc(sizeof(struct node));
    header->next->next->data = 6;
    header->next->next->next = NULL;

    // Display the linked list
    printf("Linked List: ");
    DisplayList(header);

    // Calculate the size of the linked list
    int size = sizeLL(header);
    printf("Size of the linked list: %d\n", size);

    // Free the allocated memory
    struct node* current = header;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

