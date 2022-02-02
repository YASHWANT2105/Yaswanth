#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main ()
{
   int i, j;
   FILE * fp = NULL;

   i = getpid ();
   printf ("The PID of the current process is %d\n", i);

   fp = popen ("./newProgram", "r");
   i = fork ();
   if (i == 0) //Child
   {
      sleep (1);
      char ch;
      char * buf = NULL;
      int sizeBuf = 0;
      printf ("This is child process.\n");
      if (fp == NULL)
      {
         printf ("File pointer is NULL.\n");
	 return -1;
      }
      while (1)
      {
         buf = (char *) realloc (buf, sizeBuf + 1);
	 if (0 == feof(fp))
	 {
	   fread (&ch, 1, 1, fp);
	   buf [sizeBuf] = ch;
	   sizeBuf++;
	 }
	 else
	 {
	    break;
	 }
      }
      buf[sizeBuf] = '\0';

      printf (" Buffer is\n");
      printf ("%s", buf);
      pclose (fp);
   }
   else if (i > 0) //Parent
   {  
      int status;
      printf ("This is parent process.\n");
      wait (&status);
      wait (&status);
  
      printf ("The status of child process is %d\n", status);
   }
   else
   {
      printf ("Error: Process could not be created.\n");
   }
   return 0;
}
