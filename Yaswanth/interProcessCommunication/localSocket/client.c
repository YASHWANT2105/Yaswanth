#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <fcntl.h>
#define MAX_SIZE 1000

int main ()
{
   int sock_fd = 0;
   int ret = 0;
   sock_fd = socket (PF_LOCAL, SOCK_STREAM, 0);

   char msg[MAX_SIZE];

   printf ("Enter the message:\n");
   gets (msg);

   struct sockaddr_un addr;
   addr.sun_family = AF_LOCAL;
   strcpy (addr.sun_path, "./socket_file");

   int size;
   size = sizeof (addr);

   ret = connect (sock_fd, (struct sockaddr *)&addr, size);

   if (ret < 0)
   {
      fprintf (stderr, "connect failed.\n");
      perror ("connect");
      close (sock_fd);
      return -1;
   }
   
   int msgLen;
   msgLen = strlen (msg);
   write (sock_fd, msg, msgLen);
   close(sock_fd);
   return 0;
}
