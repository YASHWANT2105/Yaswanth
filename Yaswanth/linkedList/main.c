#include "linkedList.h"

int main()
{
  int choice;
  int key;
  int keyLoc;
  struct node * head;
  int loc;
  int id1;
  int id2;
  int upBound;
  int maxLoc;
  head = NULL;

  while (1)
  {
     printf ("0. Exit\n");
     printf ("1. Insert Node\n");
     printf ("2. Delete a Node\n");
     printf ("3. Linear Search\n");
     printf ("4. Binary Search\n");
     printf ("5. Bubble Sort\n");
     printf ("6. Selection Sort\n");
     printf ("7. Insertion sort\n");
     printf ("8. Find the middle node of a linked list\n");
     printf ("9. Delete All nodes\n");
     printf ("10. Traverse the Linked List\n");
     printf ("11. Swap two nodes\n");
     printf ("12. Largest node in a range.\n");
     printf("13. mid element of linkedlist.\n");

     printf ("Enter the option:\t");
     scanf ("%d", &choice);

     switch (choice)
     {
       case 0:
	       printf ("Exiting the program.\n");
	       if (head != NULL)
	       {
		  printf ("Deleting all the nodes from the linked list.\n");
	          head = deleteAllNodes (head);
	       }
	       exit (EXIT_SUCCESS);
	       break;
       case 1:
	       printf ("Inserting a node...\n");
	       printf ("Enter the location (index) to insert the node:\t");
	       scanf ("%d", &loc);
	       head = insertNode (head, loc, NULL);
	       break;
       case 2:
	       printf ("Deleting a node...\n");
               printf ("Enter the index of the node you want to delete:\t");
	       scanf ("%d", &loc);
	       head = deleteNode (head, loc, DELETE);
	       break;
       case 3:
	       printf ("Enter the key to search.\n");
	       scanf ("%d", &key);
               keyLoc = linearSearchLL (head, key);
	       if (keyLoc == -1)
	       {
	          printf ("Key could not be found.\n");
	       }
	       else
	       {
	          printf ("Index of the given key is %d.\n", keyLoc);
	       }
	       break;
       case 4:
	        printf ("Enter the key to search.\n");
		scanf ("%d", &key);
	        keyLoc = binarysearch (head, key);
					                     
	        printf ("Index of the given key is %d.\n", keyLoc);
		break;
       case 5:
	       
	       printf (" bubble sort ....\n");
	       head=bubbleSort(head);
               break;
       case 6:
	       printf ("Selection sort...\n");
	       head = selectionSort (head);
               break;
       case 7:
	       //To-do
	       printf ("Function for insertion sort yet to be developed.\n");
	       break;
       case 8:
	       //To-do
	       printf ("Function for finding the middle node of a linked list yet to be developed.\n");
	       break;
       case 9:
	       printf ("Deleting the nodes....\n");
	       head = deleteAllNodes(head);
	       break;
	       
       case 10:
	       if (head != NULL)
	       {
	          printf ("Nodes of the linked list\n");
	          traverseLinkedList (head);
	       }
	       else
	       {
	          printf ("Linked List is empty.\n");
	       }
	       break;
       case 11:
	       if (head != NULL)
	       {
	          printf ("Enter the two indices to swap.\t");
		  scanf ("%d %d", &id1, &id2);
		  head = swapNode (head, id1, id2);
	       }
	       else
	       {
	          printf ("List is empty.\n");
	       }
	       break;
       case 12:
	       if (head == NULL)
	       {
	          printf ("List is empty.\n");
	       }
	       else
	       {
	         printf ("Enter the upper bound:\t");
		 scanf ("%d", &upBound);

		 maxLoc = maxNode (head, upBound);
		 if (maxLoc == -1)
		 {
		    printf ("Enter the valid upper bound.\n");	    
		 }
		 else
		 {
		    printf ("The max element is store at index %d.\n", maxLoc);
		 }
	       }
	       break;
	case 13:
	       printf("enter two indexes:\t");
	       scanf("%d %d",&id1,&id2);
	       loc=midNodes(head,id1,id2);
	       printf("mid element of linkedlist:%d\n",loc);
	       break;
       default:
	       printf ("Invalid Request...\n");
	       break;
     }
  }

  return 0;

}
