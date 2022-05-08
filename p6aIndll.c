// P6A.INSERTION IN DOUBLE LINKED LIST
#include <stdio.h> 
#include <stdlib.h>

struct node			//structure of doubly Node 
{
  int data;
  struct node *prev;
  struct node *next;
} *head, *last;

void insert_At_Position (int data, int pos)
{
  int i;
  struct node *new_node, *extra;
  if (head == NULL)
    {
      printf (" No data found in the list!\n");
    }
  else
    {
      extra = head;
      i = 0;
      while (i < pos - 2 && extra != NULL) { extra = extra->next;
	  i++;
	}
      if (extra != NULL)
	{
	  new_node = (struct node *) malloc (sizeof (struct node));
	  new_node->data = data;
	  new_node->next = extra->next;	
	  new_node->prev = extra;	
	  if (extra->next != NULL)
	    {
	      extra->next->prev = new_node;
	    }
	  extra->next = new_node;
	}
      else
	{
	  printf ("Invalid position ,Please enter valid position : \n");
	}
    }
}

void list (int n)			//print list of nodes
{
  int i, data;
  struct node *new_node;
  if (n >= 1)
    {
      head = (struct node *) malloc (sizeof (struct node));
      printf ("Enter data for node1 : ");
      scanf ("%d", &data);
      head->data = data;
      head->prev = NULL;
      head->next = NULL;
      last = head;
      for (i = 2; i <= n; i++) { new_node = (struct node *) malloc (sizeof (struct node)); printf ("Enter data of node %d : ", i); scanf ("%d", &data); new_node->data = data;
	  new_node->prev = last;	// Now Link new node with the previous node
	  new_node->next = NULL;
	  last->next = new_node;	// Then Link previous node with the new node
	  last = new_node;	// Let Make new node as last node
	}
    }
}

void print_List ()
{
  struct node *extra;
  int n = 1;
  if (head == NULL)
    {
      printf ("\nList is empty\n");
    }
  else
    {
      extra = head;
      printf ("The doubly Linked List is here :\n");
      while (extra != NULL)	// Print the list
	{
	  printf ("%d   ", extra->data);
	  n++;
	  extra = extra->next;	// Move the current pointer to next node 
	}
    }
}

int main ()
{
  int n, data, pos, num;
  head = last = NULL;
  printf ("Enter the size of linked list : \n");	// Input the size of nodes
  scanf ("%d", &n);
  list (n);
  print_List ();
  printf ("\nEnter data for insertion at the nth of the list :\n ");
  scanf ("%d", &data);
  printf ("\nEnter the position : ");
  scanf ("%d", &pos);
  insert_At_Position (data, pos);
  print_List ();
  return 0;
}