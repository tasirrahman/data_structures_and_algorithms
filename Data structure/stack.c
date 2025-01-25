#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack
{
  int data[MAX];
  int top;
} Stack;

void initStack(Stack *s)
{
  s->top = -1;
}

int isFull(Stack *s)
{
  return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
  return s->top == -1;
}

void push(Stack *s, int value)
{
  if (isFull(s))
  {
    printf("Stack overflow\n");
    return;
  }
  s->data[++(s->top)] = value;
}

int pop(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow\n");
    return -1;
  }
  return s->data[(s->top)--];
}

int peek(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty\n");
    return -1;
  }
  return s->data[s->top];
}

void display(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty\n");
    return;
  }
  for (int i = s->top; i >= 0; i--)
  {
    printf("%d ", s->data[i]);
  }
  printf("\n");
}

int main()
{
  Stack s;
  initStack(&s);

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("Stack elements: ");
  display(&s);

  printf("Top element: %d\n", peek(&s));

  printf("Popped element: %d\n", pop(&s));
  printf("Stack elements after pop: ");
  display(&s);

  return 0;
}