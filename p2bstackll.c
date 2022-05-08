//2B STACK USING LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct stack
{

    int data;
    struct stack *down;
} Stack;
Stack *top = NULL;
Stack *create(int data)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data = data;
    temp->down = NULL;
    return temp;
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    Stack *another = (Stack *)malloc(sizeof(Stack));
    if (another == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int pop()
{
    int data = -1;

    Stack *temp1;
    if (!isEmpty())
    {
        temp1 = top;
        data = top->data;
        top = top->down;
        free(temp1);
    }
    else
    {
        printf("Stack underflow\n");
    }
    return data;
}

void push(int data)
{
    if (!isFull())
    {
        Stack *temp;
        temp = create(data);
        temp->down = top;
        top = temp;
    }
    else
    {
        printf("Stack overflow\n");
    }
}
int peek()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        printf("Stack underflow");
        return -1;
    }
}
void display()
{
    if (!isEmpty())
    {
        Stack *run = top;
        while (run != NULL)
        {
            printf("Element : %d\n", run->data);
            run = run->down;
        }
    }
    else
    {
        printf("Stack underflow\n");
    }
}

int main()
{
    int choice, data;
    bool exit = true;

    while (exit)
    {

        printf("Enter 1 for push the element\n");
        printf("Enter 2 for pop the element\n");
        printf("Enter 3 for peek the element\n");
        printf("Enter 4 for stack traversal\n");
        printf("Enter 5 for exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the element you want to push\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("The popped element is %d\n", pop());
            break;
        case 3:
            printf("Top element is %d\'n" + peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit = false;
            break;
        }
    }
}