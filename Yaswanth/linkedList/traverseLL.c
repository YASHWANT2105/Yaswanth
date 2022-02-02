#include "linkedList.h"

void traverseLinkedList(struct node * head)
{
   struct node * temp;
   temp = head;
   int i = 0;

   while (temp != NULL)
   {
      printf ("Node (%d): Info (a = %d)\n", i, temp->a);
      temp = temp->next;
      i++;
   }
}
