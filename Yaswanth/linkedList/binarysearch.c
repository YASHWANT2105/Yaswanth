#include "linkedList"
int binarysearch(struct node * head, int key)
{
   struct node * temp;
   temp = head;
   int i,mid;
   k=midNodes(head,k,num-1)
   while(1)
   {
      for(i=0;i<k;i++)
      { 
	   temp=temp->next;
      }
      mid=temp->a;
      if(mid==key)
      {
       return k;
      }
     else if(mid<key)
     {
      k=midNodes(head,k,num-1)
     }
     else
     {
      k=midNodes(head,k,num-1)
     }
   }
}
  

