#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 1000


int main ()
{
   char * filename = NULL;
   int fd;
   char ch;
   char * read_data = NULL;
   int read_count = 0;
   int ret = 0;
   filename = (char *) malloc (sizeof(char) * MAX_SIZE);

   printf ("Enter the file name with path:\t");
   gets (filename);

   fd = open (filename, O_CREAT | O_RDWR);

   printf ("fd = %d\n", fd);

   printf ("filename: %s\n", filename);

   lseek (fd, -4, SEEK_END);

   while (1)
   {
       read_data = realloc (read_data, sizeof(char) * (read_count + 1));

       ret = read (fd, &ch, 1);
       if (ret == 1)
       {
          *(read_data + read_count) = ch;
	  read_count++;
       }
       else
       {
          break;
       }
   }

   *(read_data + read_count) = '\0';

   printf ("%d character read from the file from %s.\n", read_count, filename);

   printf ("Message in the file:\t %s\n", read_data);

   close (fd);
   free (read_data);
   free (filename);
   return 0;
}
