#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int i;
   char * a;

   int n = 5;

//   printf ("Enter the number of character in the string:\t");
//   scanf ("%d", &n);


   a = (char *) malloc (sizeof(char) * (n+1));

   /*for (i = 0; i < n; i++)
   {
      scanf ("%c", (a+i));
   }
   *(a + i) = '\0';*/
   //printf ("Enter the string you want to print:");
   //scanf ("%s", a); // it can only take the user input upto a white space character
   //scanf ("%[abcd]", a);

   //scanf ("%3s", a);
   /*for (i = 0; i < n; i++)
   {

     *(a+i) = getchar();
   }
   *(a+i) = 'a';

   a[35] = 'd';*/

   //gets (a);

   printf ("This is the input string\n");
   printf ("%s", a);
   printf ("\n");

   //puts (a);
   /*for (i = 0; i < n; i++)
   {
      printf ("%c\n", a[i]);
      //printf ("%d\n", a[i]);
   }*/

   free (a);
   return 0;
}
