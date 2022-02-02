#include "linkedList.h"
struct node * bubbleSort (struct node * head)
{
  int numNode=0;
  int i;
  struct node *temp[2];
  numNode = calculateNumNode(head);
  temp[0]=head;
  temp[2]=head;
  temp[1]=temp[0]->next;


  if (numNode <= 1)
  {
    printf ("Insufficient Nodes for sorting.\n");
  }
  else
  {
    for(i=0;i<(numNode-1);i++)
    {
       
       
           if(temp[0]->a > temp[1]->a)
	   {
	         
              head = swapNode(head, i, i+1);
	    }
	    temp[0]=temp[1];
	    temp[1]=temp[0]->next;
	     
           	
     }
   }
   return head;
 
}
