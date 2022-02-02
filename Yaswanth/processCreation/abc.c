#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main ()
{
   int i, j;

   i = getpid ();
   printf ("The PID of the current process is %d\n", i);

   i = fork ();
   if (i == 0) //Child
   {
      printf ("This is child process.\n");
      for (j = 0; j < 5; j++)
      {
         sleep (1);
         printf ("Hello World!!\n");
      }

      execl ("./newProgram", NULL);
   }
   else if (i > 0) //Parent
   {  int status;
      printf ("This is parent process.\n");
      wait (&status);

      printf ("The status of child process is %d\n", status);
   }
   else
   {
      printf ("Error: Process could not be created.\n");
   }
   return 0;
}
