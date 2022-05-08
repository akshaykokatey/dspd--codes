// 5A.Insertion in single linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *first = NULL, *last = NULL, *new;
Node *create()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter the data for insertion\n");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}
void display()
{
    Node *temp1 = first;
    while (temp1 != NULL)
    {
        printf("Element : %d\n", temp1->data);
        temp1 = temp1->next;
    }
}
int count()
{
    int n = 0;
    Node *t = first;
    while (t != NULL)
    {
        t = t->next;
        n++;
    }
    return n;
}
void insert()
{
    Node *temp, *prev = NULL, *curr = first;
    int choice, position, i = 1;
    printf("Enter the choice for creation of node\n");
    printf("1.inserting at starting\n");
    printf("2.inserting in intermediate place\n");
    printf("3.inserting in last\n");
    scanf("%d", &choice);
    if (first != NULL)
    {
        switch (choice)
        {
        case 1:
            temp = create();
            temp->next = first;
            first = temp;
            new = temp;
            break;
        case 2:
            printf("Enter the position of node from 1 to %d\n", count());
            scanf("%d", &position);
            while (i < position && curr != NULL)
            {
                prev = curr;
                curr = curr->next;
                i++;
            }
            if (curr != NULL)
            {
                temp = create();
                if (position == 1)
                {
                    temp->next = first;
                    first = temp;
                    new = temp;
                }
                else
                {
                    prev->next = temp;
                    temp->next = curr;
                    new = temp;
                }
            }
            else
            {
                printf("please enter appropriate position\n");
            }
            break;
        case 3:
            temp = create();
            last->next = temp;
            last = temp;
            new = temp;
            break;
        }
    }
    else
    {
        temp = create();
        first = temp;
        last = temp;
        new = temp;
    }
}
void delete ()
{
    Node *temp, *prev = NULL, *curr = first;
    int choice, position, i = 1;
    printf("Enter the choice for Deletion of node\n");
    printf("1.Deleting at starting\n");
    printf("2.Deleting in intermediate place\n");
    printf("3.Deleting in last\n");
    scanf("%d", &choice);
    if (first != NULL)
    {
        switch (choice)
        {
        case 1:
            temp = first;
            first = first->next;
            free(temp);
            break;
        case 2:
            printf("Enter the position of node from 1 to %d\n", count());
            scanf("%d", &position);
            while (i < position && curr != NULL)
            {
                prev = curr;
                curr = curr->next;
                i++;
            }
            if (curr != NULL)
            {
                temp = curr;
                prev->next = curr->next;
                free(temp);
            }
            else
            {
                printf("please enter appropriate position\n");
            }
            break;
        case 3:
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            temp = curr;
            last = prev;
            last->next = NULL;
            free(temp);
            break;
        }
    }
    else
    {
        printf("List is Empty\n");
    }
}
int main()
{
    insert();
    insert();
    insert();
    delete ();
    display();
    delete ();
    display();
    delete ();
    display();
}