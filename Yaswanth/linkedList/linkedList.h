#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  //info part
  int a;

  //address of next node
  struct node * next;
};

enum flag
{
  DO_NOT_DELETE = 0,
  DELETE
};

extern struct node * insertNode (struct node * head, int loc, struct node * newNode);
extern int calculateNumNode(struct node * head);
extern struct node * deleteAllNodes(struct node * head);
extern void traverseLinkedList(struct node * head);
extern struct node * deleteNode (struct node * head, int loc, int freeFlag);
extern int linearSearchLL(struct node * head, int key);
extern struct node * swapNode (struct node * head, int id1, int id2);
extern int maxNode (struct node * head, int upperBound);
extern struct node * selectionSort (struct node * head);
extern struct node * bubbleSort (struct node * head);
extern int midNodes(struct node * head,int a,int b);
extern int binarysearch(struct node * head, int key);
