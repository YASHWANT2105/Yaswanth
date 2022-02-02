??=include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 1000
#define MAX_FILE_SIZE 100000


int main ()
{
   char * filename = NULL;
   int fd, i;
   char * message = NULL;
   filename = (char *) malloc (sizeof(char) * MAX_SIZE);
   message =  (char *) malloc (sizeof(char) * MAX_FILE_SIZE);


   printf ("Enter the file name with path(Max Size: %d):\t", MAX_SIZE);
   gets (filename);

   printf ("Enter the message you want to write in \
		   the file (Max Message Size: %d): \t", MAX_FILE_SIZE);
   gets (message);

   fd = open (filename, \
		   O_CREAT | O_RDWR);

   printf ("fd = %d\n", fd);

   printf ("filename: %s\n", filename);

/*   while (1)
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
   } */
   i = 0;
   while (*(message + i) != '\0')
   {
      i++;
   }

   write (fd, message, i);

   close (fd);
   free (filename);
   free (message);
   return 0;
}
