#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void thread_func (void * arg)
{
  // Thread operations
  int * a;
  a = (int *)arg;

  printf ("Value of a is %d.\n", *a);

  while (1)
  {
     sleep (1);
     printf ("This is created thread.\n");
  }
}

void normal_func ()
{
  while (1)
  {
     sleep (1);
     printf ("This is creator thread.\n");
  }
}

int main ()
{
   int pid;
   pid = getpid();
   printf ("PID of the process %d\n", pid);
   pthread_t tid = 0;
   
   int b = 5;
   int ret = 0;
   ret = pthread_create (&tid, NULL, (void *) &thread_func, (void *)&b);
   printf ("Thread id is %lu.\n", tid);
   if (ret != 0)
   {
     printf ("Thread could not be created.\n");
     perror("pthread_create");
   }

   normal_func ();
   return 0;
}
