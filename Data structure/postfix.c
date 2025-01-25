#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
  if (top >= MAX - 1)
  {
    printf("Stack Overflow\n");
    return;
  }
  stack[++top] = value;
}

int pop()
{
  if (top < 0)
  {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack[top--];
}

int evaluatePostfix(char *exp)
{
  for (int i = 0; exp[i]; ++i)
  {
    if (isdigit(exp[i]))
    {
      push(exp[i] - '0');
    }
    else
    {
      int val1 = pop();
      int val2 = pop();
      switch (exp[i])
      {
      case '+':
        push(val2 + val1);
        break;
      case '-':
        push(val2 - val1);
        break;
      case '*':
        push(val2 * val1);
        break;
      case '/':
        push(val2 / val1);
        break;
      }
    }
  }
  return pop();
}

int main()
{
  char exp[MAX];
  printf("Enter a postfix expression: ");
  scanf("%s", exp);
  printf("The result of the postfix expression is: %d\n", evaluatePostfix(exp));
  return 0;
}