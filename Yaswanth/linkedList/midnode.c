#include "linkedList.h"
	
int midNodes(struct node * head,int a,int b)
{
    int k,mid,i;
    int numNode=0;
    struct node * temp;
    temp = head;
    numNode = calculateNumNode(head);
    if(a>=0 && a<numNode && b>=0 && b<numNode)
    {	    
      mid=a+b/2;
      for(i=0;i<mid;i++)
      {
       temp=temp->next;
      }
      k=temp->a;
      return k;
    }
    else
    {
       fprintf (stderr, "Invalid indices (%d, %d).\nValid Indices range must be [0, %d].\n", a, b, numNode-1);
      
    }
}
