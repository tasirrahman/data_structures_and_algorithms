#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
  if (top == MAX - 1)
  {
    printf("Stack overflow\n");
    return;
  }
  stack[++top] = x;
}

int pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    return -1;
  }
  return stack[top--];
}

int isOperator(char ch)
{
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch)
{
  switch (ch)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return 0;
  }
}

int applyOperation(int a, int b, char op)
{
  switch (op)
  {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  default:
    return 0;
  }
}

int evaluateInfix(char *exp)
{
  int i;
  int values[MAX];
  int valuesTop = -1;
  char ops[MAX];
  int opsTop = -1;

  for (i = 0; exp[i]; i++)
  {
    if (exp[i] == ' ')
      continue;

    if (isdigit(exp[i]))
    {
      int val = 0;
      while (i < strlen(exp) && isdigit(exp[i]))
      {
        val = (val * 10) + (exp[i] - '0');
        i++;
      }
      values[++valuesTop] = val;
      i--;
    }
    else if (exp[i] == '(')
    {
      ops[++opsTop] = exp[i];
    }
    else if (exp[i] == ')')
    {
      while (opsTop != -1 && ops[opsTop] != '(')
      {
        int val2 = values[valuesTop--];
        int val1 = values[valuesTop--];
        char op = ops[opsTop--];
        values[++valuesTop] = applyOperation(val1, val2, op);
      }
      opsTop--;
    }
    else if (isOperator(exp[i]))
    {
      while (opsTop != -1 && precedence(ops[opsTop]) >= precedence(exp[i]))
      {
        int val2 = values[valuesTop--];
        int val1 = values[valuesTop--];
        char op = ops[opsTop--];
        values[++valuesTop] = applyOperation(val1, val2, op);
      }
      ops[++opsTop] = exp[i];
    }
  }

  while (opsTop != -1)
  {
    int val2 = values[valuesTop--];
    int val1 = values[valuesTop--];
    char op = ops[opsTop--];
    values[++valuesTop] = applyOperation(val1, val2, op);
  }

  return values[valuesTop];
}

int main()
{
  char exp[MAX];
  printf("Enter infix expression: ");
  fgets(exp, MAX, stdin);
  printf("Result: %d\n", evaluateInfix(exp));
  return 0;
}