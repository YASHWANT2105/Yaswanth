#include <stdio.h>
#include <stdlib.h>

struct student
{
  int RollNo;
  char name[100];
};

void printStructure(struct student * a, int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
      printf ("Student (%d):\n", i);
      printf ("Roll No. = %d.\n", (a+i)->RollNo);
      printf ("Name = %s\n", (a+i)->name);
   }
}

int main ()
{
  struct student * s1;
  int i;
  s1 = NULL;
  int nStudents;

  printf ("Enter the number of students:\t");
  scanf ("%d", &nStudents);
  s1 = (struct student *)malloc (sizeof (struct student) * nStudents);

  for (i = 0; i < nStudents; i++)
  {
     printf ("Enter the student (%d) details:\n", i);
     printf ("Name:\t");
     //fgets ((s1+i)->name, 100, stdin);
     scanf ("%s", (s1+i)->name);
     printf ("Roll no.\t");
     scanf ("%d", &((s1+i)->RollNo));
  }

  printStructure (s1, nStudents);

  free (s1);
  return 0; 
}
