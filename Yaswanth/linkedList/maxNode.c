#include "linkedList.h"

int maxNode (struct node * head, int upperBound)
{
   int numNode;
   int i;
   int max;
   int loc;
   struct node * temp = NULL;
   numNode = calculateNumNode(head);

   if (upperBound >= numNode && upperBound < 0)
   {
      printf ("Invalid upper bound.\n");
   }
   else
   {
      temp = head;
      max = temp->a;
      i = 0;
      loc = 0;
      while (i <= upperBound)
      {
         if (max < temp->a)
	 {
	    max = temp->a;
	    loc = i;
	 }
         temp = temp->next;
         i++;
      }

      return loc;
   }
   return -1;
}
