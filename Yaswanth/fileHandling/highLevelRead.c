#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_FILE_SIZE 100000

int main ()
{
   int end_of_file;
   FILE * fp = NULL;
   char * read_data = NULL;
   int read_count = 0;
   char ch;

   char * scan_file= NULL;
   scan_file = (char *) malloc (sizeof(char) * MAX_FILE_SIZE);

   char * filename = NULL;

   filename = (char *) malloc (sizeof(char) * MAX_SIZE);

   printf ("Enter the file name with path:\t");
   fgets (filename, 1000, stdin);

   printf ("Filename: %s\n", filename);

   fp = fopen (filename, "a+");

   if (fp == NULL)
   {
      fprintf (stderr, "Could not open the file %s.\n", filename);
   }

   read_count = 0;

   /*fseek (fp, 4, SEEK_SET); */

   while (1)
   {
      ch = '\0';
      read_data = (char *) realloc (read_data, (sizeof (char) * (read_count + 1)));

      end_of_file = feof (fp);
      //printf ("%d\n", end_of_file);
      if (end_of_file == 0)
      {
         //fgets (&ch, 1, fp);
	 //fread (&ch, 1, 1, fp);
	 ch = fgetc (fp);
         printf ("%d\t", ch);
	 read_data [read_count] = ch;
	 read_count++;
      }
      else
      {
         break;
      }
   }
   read_data [read_count] = '\0';

   printf ("Message fetched from the file is: %s\n", read_data);

   //fscanf (fp, "%[^\n]", scan_file);
 
   //fgets (scan_file, MAX_FILE_SIZE, fp);
  

   //printf ("Message fetched from the file is: %s\n", scan_file);


   free (scan_file);
   free (read_data);
   free (filename);
   fflush (fp);
   fclose (fp);
   return 0;
}
