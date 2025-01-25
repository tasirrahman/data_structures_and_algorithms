#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
  int data;
  struct Node *next;
};

// Queue structure
struct Queue
{
  struct Node *front, *rear;
};

// Function to create a new node
struct Node *newNode(int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

// Function to create a new queue
struct Queue *createQueue()
{
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int data)
{
  struct Node *temp = newNode(data);
  if (q->rear == NULL)
  {
    q->front = q->rear = temp;
    return;
  }
  q->rear->next = temp;
  q->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct Queue *q)
{
  if (q->front == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }
  struct Node *temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL)
  {
    q->rear = NULL;
  }
  int data = temp->data;
  free(temp);
  return data;
}

// Function to get the front element of the queue
int front(struct Queue *q)
{
  if (q->front == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }
  return q->front->data;
}

// Function to get the rear element of the queue
int rear(struct Queue *q)
{
  if (q->rear == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }
  return q->rear->data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
  return q->front == NULL;
}

// Function to display the queue
void displayQueue(struct Queue *q)
{
  struct Node *temp = q->front;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Main function to test the queue
int main()
{
  struct Queue *q = createQueue();
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);

  printf("Queue: ");
  displayQueue(q);

  printf("Front element: %d\n", front(q));
  printf("Rear element: %d\n", rear(q));

  printf("Dequeued: %d\n", dequeue(q));
  printf("Queue after dequeue: ");
  displayQueue(q);

  return 0;
}