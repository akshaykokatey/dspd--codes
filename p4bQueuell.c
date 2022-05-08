// QUEUE USING LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

Queue *front = NULL, *rear = NULL;

Queue *create(int data)
{
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

bool isEmpty()
{
    if (front == NULL)
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
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    if (temp == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(int data)
{
    if (!isFull())
    {
        if (isEmpty())
        {
            rear = create(data);
            front = rear;
        }
        else
        {
            Queue *temp;
            temp = create(data);
            rear->next = temp;
            rear = temp;
        }
    }
    else
    {
        printf("Queue overflow\n");
    }
}
int Dequeue()
{
    int data = -1;
    if (!isEmpty())
    {
        Queue *temp;
        data = front->data;
        if (front == rear)
        {

            temp = front;
            front = NULL;
            rear = NULL;
            free(temp);
        }
        else
        {
            temp = front;

            front = front->next;
            free(temp);
        }
    }
    else
    {
        printf("Queue underflow\n");
    }
    return data;
}
void display()
{
    if (!isEmpty())
    {
        Queue *start = front;
        while (start != NULL)
        {
            printf("Elements : %d\n", start->data);
            start = start->next;
        }
    }
    else
    {
        printf("Queue underflow\n");
    }
}
int main()
{
    int choice, data;
    bool exit = true;

    while (exit)
    {

        printf("Enter 1 for Enqueue the element\n");
        printf("Enter 2 for Dequeue the element\n");
        printf("Enter 3 for Queue traversal\n");
        printf("Enter 4 for exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the element you want to push\n");
            scanf("%d", &data);
            Enqueue(data);
            break;
        case 2:
            printf("The Deleted element is %d\n", Dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit = false;
            break;
        }
    }
}