#include <stdio.h>
#include <stdlib.h>

struct student
{
  int RollNo;
  char name[100];
};

int numStudents = 0;

struct student * createDb ()
{
   struct student * a;
   int i;
   printf ("Enter the Number of students:\t");
   scanf ("%d", &numStudents);

   a = (struct student *) malloc (sizeof (struct student ) * numStudents);

   for (i = 0; i < numStudents; i++)
   {
      printf ("Enter the details for student (%d):\n", i);
      printf ("Roll No.\t");
      scanf ("%d", &((a+i)->RollNo));
      printf ("Name:\t");
      scanf ("%s", (a+i)->name);
   }

   return a;
}


void printStructure(struct student * a)
{
   int i;
   for (i = 0; i < numStudents; i++)
   {
      printf ("Student (%d):\n", i);
      printf ("Roll No. = %d.\n", (a+i)->RollNo);
      printf ("Name = %s\n", (a+i)->name);
   }
}

int main ()
{
  struct student * s1, *s2;

  s1 = createDb();

  s2 = s1;
  printStructure(s1);

  free (s2);
  return 0; 
}
