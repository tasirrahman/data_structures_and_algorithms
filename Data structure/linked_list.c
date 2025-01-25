#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Main function to test the linked list implementation
int main()
{
  struct Node *head = NULL;

  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);

  printList(head);

  return 0;
}