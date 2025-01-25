#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *newNode(int data)
{
  struct Node *stackNode = (struct Node *)malloc(sizeof(struct Node));
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node *root)
{
  return !root;
}

// Function to push an element onto the stack
void push(struct Node **root, int data)
{
  struct Node *stackNode = newNode(data);
  stackNode->next = *root;
  *root = stackNode;
  printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node **root)
{
  if (isEmpty(*root))
    return -1;
  struct Node *temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);
  return popped;
}

// Function to peek the top element of the stack
int peek(struct Node *root)
{
  if (isEmpty(root))
    return -1;
  return root->data;
}

// Function to print all elements in the stack
void printStack(struct Node *root)
{
  while (root != NULL)
  {
    printf("%d -> ", root->data);
    root = root->next;
  }
  printf("NULL\n");
}

// Main function to test the stack implementation
int main()
{
  struct Node *root = NULL;

  push(&root, 10);
  push(&root, 20);
  push(&root, 30);

  printf("Top element is %d\n", peek(root));

  printf("Stack elements are: ");
  printStack(root);

  printf("%d popped from stack\n", pop(&root));
  printf("Top element is %d\n", peek(root));

  printf("Stack elements are: ");
  printStack(root);

  return 0;
}