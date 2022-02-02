#include "linkedList.h"

struct node * selectionSort (struct node * head)
{
   int numNode;
   int i;
   int maxLoc;
   numNode = calculateNumNode(head);

   if (numNode <= 1)
   {
      printf ("Insufficient Nodes for sorting.\n");
   }
   else
   {
      for (i = 0; i < numNode-1; i++)
      {
         maxLoc = maxNode(head, numNode-1-i);
	 //printf ("id1 = %d | id2 = %d\n", maxLoc, numNode-1-i);
	 head = swapNode(head, maxLoc, numNode-1-i);
      }
   }
   return head;
}
