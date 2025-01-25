#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node
{
  int data;
  struct Node *next;
};

// Define the structure for the queue
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

  // If queue is empty, then new node is front and rear both
  if (q->rear == NULL)
  {
    q->front = q->rear = temp;
    return;
  }

  // Add the new node at the end of queue and change rear
  q->rear->next = temp;
  q->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct Queue *q)
{
  // If queue is empty, return NULL
  if (q->front == NULL)
  {
    return -1;
  }

  // Store previous front and move front one node ahead
  struct Node *temp = q->front;
  q->front = q->front->next;

  // If front becomes NULL, then change rear also as NULL
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
    return -1;
  }
  return q->front->data;
}

// Function to get the rear element of the queue
int rear(struct Queue *q)
{
  if (q->rear == NULL)
  {
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

// Main function to test the queue implementation
int main()
{
  struct Queue *q = createQueue();
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);

  printf("Queue: ");
  displayQueue(q);

  printf("Dequeued: %d\n", dequeue(q));
  printf("Queue after dequeue: ");
  displayQueue(q);

  printf("Front element: %d\n", front(q));
  printf("Rear element: %d\n", rear(q));

  return 0;
}