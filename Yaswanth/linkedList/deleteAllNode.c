#include "linkedList.h"

struct node * deleteAllNodes(struct node * head)
{
   struct node * temp = NULL;

   while (head != NULL)
   {
     temp = head->next;
     free(head);
     head = temp;
   }
   return head;
}
