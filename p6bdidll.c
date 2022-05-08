// DELETION IN DOUBLE LINKED LIST
#include <stdio.h> 
#include <stdlib.h> 
struct node
{				// node structure
  int data;
  struct node *nextpt;
  struct node *prevpt;
} *lastpt, *headpt;
void delete_At_Pos(int pos)
{
  struct node *extra;
  int i,cur;
  extra = headpt;
  for (i = 1; i < pos && cur != NULL; i++) { extra = extra->nextpt;
    }
  if (extra != NULL)
    {
      extra->prevpt->nextpt = extra->nextpt;
      extra->nextpt->prevpt = extra->prevpt;
      free (extra);		// remove the extra node
    }
  else
    {
      printf ("Enter valid position!\n");
    }
}
void list(int n)
{
  struct node *new_node;
  int data, l;
  if (n >= 1)			// list is empty
    {
      headpt = (struct node *) malloc (sizeof (struct node));
      printf ("Enter the data of node : ");
      scanf ("%d", &data);
      headpt->data = data;
      headpt->prevpt = NULL;
      headpt->nextpt = NULL;
      lastpt = headpt;
      for (l = 2; l <= n; l++)
	{
	  new_node = (struct node *) malloc (sizeof (struct node));
	  printf ("Enter the data of node : ", l);
	  scanf ("%d", &data);
	  new_node->data = data;
	  new_node->prevpt = lastpt;
	  new_node->nextpt = NULL;
	  lastpt->nextpt = new_node;
	  lastpt = new_node;
	}
    }
}
void print()       // Print the linked list
{
  struct node *extra;
  int n = 1;
  if (headpt == NULL)
    {
      printf ("List is empty");
    }
  else
    {
      extra = headpt;
      while (extra != NULL)	
	{
	  printf ("%d  ", extra->data);
	  n++;
	  extra = extra->nextpt;
	}
    }
}
int main ()
{
  int n, pos;
  headpt = lastpt = NULL;
  printf ("Enter the size of nodes: ");
  scanf ("%d", &n);
  list (n);
  printf ("The Doubly Linked List is :\n");
  print ();

  printf ("\nEnter the position : ");
  scanf ("%d", &pos);
  delete_At_Pos (pos);
  printf ("After Deleting the node in the Linked List is :\n");
  print ();
  return 0;
}