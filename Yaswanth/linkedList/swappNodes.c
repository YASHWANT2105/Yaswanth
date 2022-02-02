#include "linkedList.h"

struct node * swapNode (struct node * head, int id1, int id2)
{
  int loc[2];
  struct node *temp[2];
  int numNode = 0;
  int i;

  if (id1 > id2)
  {
     loc[1] = id1;
     loc[0] = id2;
  }
  else if (id1 < id2)
  {
     loc[0] = id1;
     loc[1] = id2;
  }
  else
  {
     printf ("Indices are equal. So, no need to swap.\n");
     return head;
  }

  numNode = calculateNumNode(head);

  if (loc[0] >= 0 && loc[0] < numNode && loc[1] >= 0 && loc[1] < numNode )
  {
     //Valid indices
     temp[0] = head;
     temp[1] = head;

     i = 0;
     while (i < loc[0])
     {
        temp[0] = temp[0]->next;
	i++;
     }

     i=0;
     while (i< loc[1])
     {
        temp[1] = temp[1]->next;
	i++;
     }

     head = deleteNode(head, loc[1], DO_NOT_DELETE);
     head = deleteNode(head, loc[0], DO_NOT_DELETE);

     head = insertNode(head, loc[0], temp[1]);
     head = insertNode(head, loc[1], temp[0]);
  }
  else
  {
     fprintf (stderr, "Invalid indices (%d, %d).\nValid Indices range must be [0, %d].\n", loc[0], loc[1], numNode-1);
  }

  return head;
}
