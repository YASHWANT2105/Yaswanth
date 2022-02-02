#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

int find_str_len(char *);
int cmpStr (char *, char *);
void copy_str (char *, char *);
int concatanate_str (char * str1, char * str2);
void lower_str(char * str);

int main ()
{
   char * a = NULL;
   char * b = NULL;
   char * c = NULL;

   a = (char *) malloc (sizeof (char) * MAX_SIZE);
   b = (char *) malloc (sizeof (char) * MAX_SIZE);
   c = (char *) malloc (sizeof (char) * MAX_SIZE);

   //scanf ("%[^\n]", a);
   //scanf ("%[^\n]", b);
   //
   gets(a);
   gets(b);

   printf ("%s", a);
   printf ("\n");

   printf ("%s", b);
   printf ("\n");

   int res;
   res = cmpStr (a, b);

   if (res == 1)
   {
      printf ("Both strings are same.\n");
   }
   else
   {
      printf ("Strings are different.\n");
   }

   //copy string
   copy_str (b, c);
   printf ("After copying the string: C = \n");
   printf ("%s", c);
   printf ("\n");

   int ret;
   ret = concatanate_str (a, b);

   if (ret == 1)
   {
      printf ("String has been concatanated.\n");
      printf ("%s", a);
      printf ("\n");
   }
   else
   {
      printf ("String has not been concatanated.\n");
   }

   lower_str (a);

   printf ("After running lower_str resultant string is :\n");
   printf ("%s", a);
   printf ("\n");

   free (a);
   free (b);
   free (c);
   return 0;
}

int find_str_len(char * str)
{
   int i;
   i = 0;

   while (*(str+i) != '\0')
   {
      i++;
   }

   return i;
}


int cmpStr (char * str1, char * str2)
{
   int m, n, i;
   m = find_str_len(str1);
   n = find_str_len(str2);

   if (m != n)
   {
     return 0;
   }

   i = 0;

   for (i = 0; i < m; i++)
   {
      if (str1[i] != str2[i])
      {
        return 0;
      }
   }

   return 1;
}

void copy_str (char * src, char * dest)
{
   int i;
   i = 0;

   while (*(src + i) != '\0')
   {
      *(dest + i) = *(src + i);
      i++;
   }

   *(dest + i) = '\0';
}

int concatanate_str (char * str1, char * str2)
{
   int n, m, i, j;

   m = find_str_len (str1);
   n = find_str_len (str2);

   if (m == 0 || n == 0)
   {
      return 0;
   }

   i = m;
   j = 0;


   while (*(str2 + j) != '\0')
   {
      *(str1 + i) = *(str2 + j);
      i++;
      j++;
   }

   *(str1 + i) = '\0';
   return 1;
}

void lower_str(char * str)
{
   int i;

   i = 0;

   while (*(str + i) != '\0')
   {
      if (*(str + i) >= 65 && *(str + i) <= 90)
      {
         *(str + i) += 32;
      }
      i++;
   }
}
