#include "linkedList.h"

int linearSearchLL(struct node * head, int key)
{
   struct node * temp;
   temp = head;
   int i;

   i = 0;
   while (temp != NULL)
   {
      if (temp->a == key)
      {
         return i;
      }
      temp = temp->next;
      i++;
   }
   return -1;
}
