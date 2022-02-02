#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  1000
#define MAX_FILE_SIZE  100000

int main()
{
   int i;
   FILE * fp = NULL;
   char * filename = NULL;
   char * message = NULL;

   filename = (char *) malloc (sizeof (char) * MAX_SIZE);
   message = (char *) malloc (sizeof (char) * MAX_FILE_SIZE);

   printf ("Please enter the filename (Max size: %d):\t", MAX_SIZE);
   gets (filename);

   printf ("Enter the message (Max Size: %d):\t", MAX_FILE_SIZE);
   gets (message);


   fp = fopen (filename, "a+");

   i = 0;
   while (*(message + i) != '\0')
   {
      i++;
   }

   //fwrite ((void *) message, i, 1, fp);
   fputs (message, fp);

   char ch;
   ch = '\n';

   fputc (ch, fp);

   fprintf (fp, "This is file handling program.\n");

   fflush (fp);
   fclose (fp);
   free(filename);
   free (message);
}
