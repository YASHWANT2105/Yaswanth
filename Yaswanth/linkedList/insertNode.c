#include "linkedList.h"

// Whenever a new node is required then pass newNode variable as NULL
// In Swapping two node, we don't need to allocate a new node
struct node * insertNode (struct node * head, int loc, struct node * newNode)
{
   int i;
   int numNode;
   struct node * temp;

   if (loc < 0)
   {
      printf ("Invalid Request.\n");
   }
   else if (loc == 0) // insert node at 0th place
   {
      if (newNode == NULL)
      {
         newNode = (struct node *) malloc (sizeof (struct node));

         memset (newNode, 0, sizeof (struct node));

         printf ("Enter the value you want to store at info part of the Node (a):\t");
         scanf ("%d", &(newNode->a));
      }
 
      if (head == NULL) // creating the first node when linked List is empty
      {
	 newNode->next = NULL;
      }
      else // Inserting a node at 0th location when linked list is not empty
      {
	 newNode->next = head;
      }
      head = newNode;
   }
   else // insert node not at 0th place
   {
      if (head == NULL)
      {
         printf ("Invalid Request.\n");
	 printf ("List is empty.\n");
      }
      else
      {
         numNode = calculateNumNode(head);
	 if (loc > numNode)
	 {
	    printf ("invalid location.\n");
	    printf ("Please enter the index in the range [0, %d]. \n", numNode);
	 }
         else // different handling for last node and in-between head and tail node
	 {
	    if (newNode == NULL)
	    {
	       newNode = (struct node *) malloc (sizeof (newNode));
	       memset (newNode, 0, sizeof (newNode));

	       printf ("Enter the value you want to store at info part of the Node (a):\t");
               scanf ("%d", &(newNode->a));
            }
	    if (loc == numNode) //adding a new tail node
	    {
	       temp = NULL;
	       temp = head;

	       while (temp->next != NULL) //reach till the tail node
	       {
                  temp = temp->next;
	       }

	       temp->next = newNode;
	       newNode->next = NULL;
	    }
	    else //Insert a node in-between head node and tail node
	    {
               temp = NULL;
	       temp = head;
	       i = 0;
	       while (i < loc-1)
	       {
	          temp = temp->next;
		  i++;
	       }

	       newNode->next = temp->next;
	       temp->next = newNode;
	    }
	 }
      }
   }
   return head;
}
