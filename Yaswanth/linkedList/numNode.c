#include "linkedList.h"

int calculateNumNode(struct node * head)
{
   int numNode = 0;
   
   struct node * temp;
   temp = head;

   while (temp != NULL)
   {
      temp = temp->next;
      numNode++;
   }

   return numNode;
}
