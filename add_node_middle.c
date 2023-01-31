#include <stdio.h>
#include <stdlib.h>

// structure for a node in the linked list
struct Node {
  int data;
  struct Node *next;
};

// function to add a new node with value 'data' after node 'prev'
void addNodeAfter(struct Node *prev, int data) {
  // check if the prev node is NULL
  if (prev == NULL) {
    printf("Previous node cannot be NULL");
    return;
  }

  // allocate memory for the new node
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

  // set the data of the new node
  new_node->data = data;

  // set the next pointer of the new node to the next node of prev
  new_node->next = prev->next;

  // set the next pointer of prev to the new node
  prev->next = new_node;
}

// function to print the linked list
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  // initialize the head node of the linked list
  struct Node *head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  head->data = 1;
  head->next = NULL;

  // add a node with value 2
  addNodeAfter(head, 2);

  // add a node with value 3
  addNodeAfter(head->next, 3);

  // print the linked list
  printf("Linked list: ");
  printList(head);

  return 0;
}
