#include "linkedList.h"

// if freeFlag is 0 do not free the memory of the candidate because that will for just swapping

struct node * deleteNode (struct node * head, int loc, int freeFlag)
{
   int numNode = 0;
   int i;
   struct node * temp = NULL;
   struct node * temp1 = NULL;
   if (head == NULL) // list is empty
   {
      fprintf (stderr, "List is empty.\n");
   }
   else // List is not empty
   {
      numNode = calculateNumNode (head);

      if (loc >= 0 && loc < numNode) //valid location
      {
         if (loc == 0) //Deleting the head node
	 {
	    temp = head->next;
	    if (freeFlag == 1)
	    {
	       free (head);
	    }
	    head = temp;
	 }
	 else
	 {
            i = 0;
	    temp = head;
	    temp1 = head->next;
	    while (i < (loc - 1))
	    {
	       temp = temp1;
	       temp1 = temp1->next;
	       i++;
	    }
	    if (loc == numNode - 1) //deleting the tail node
	    {
	      
               if (freeFlag == 1)
	       {
	          free (temp1);
	       }
	       temp->next = NULL;
	    }
	    else // Deleting a node in between head and tail node
	    {
	       temp->next = temp1->next;
	       if (freeFlag == 1)
	       {
	          free(temp1);
	       }
	    }
	 }
      }
      else //Invalid location
      {
         fprintf (stderr, "Index is invalid.\nValid indices [0, %d].\n", numNode-1);
      }
   }
   return head;
}
