#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <fcntl.h>

void readClient (int fd)
{
   char * msg = NULL;
   int count = 0;
   char ch;
   int ret = 0;
   while (1)
   {
      msg = realloc (msg, sizeof (char) * (count + 1));
      ret = read (fd, &ch, 1);
      if (ret > 0)
      {
        msg[count] = ch;
	count++;
      } 
      else 
      {
         break;
      }
   }

   msg[count] = '\0';

   printf ("%s", msg);
   printf ("\n");
   return;
}

int main()
{
   //create the socket
   int ret = 0;
   int sock_fd = 0;
   sock_fd = socket (PF_LOCAL, SOCK_STREAM, 0);

   if (sock_fd < 0)
   {
      perror ("socket");
   }

   //create address structure object for local socket
   struct sockaddr_un addr;
   addr.sun_family = AF_LOCAL;
   strcpy (addr.sun_path, "./socket_file");
   int sizeAddr;
   sizeAddr = sizeof (addr);

   ret = bind (sock_fd, (struct sockaddr *)&addr, sizeAddr);
   if (ret < 0)
   {
      fprintf (stderr, "Bind failed\n");
      perror ("bind");
      return -1;
   }

   listen (sock_fd, 5);

   int j = 0;
   while (j < 1)
   {
      printf ("Server waiting\n");
      int client_fd;
      struct sockaddr_un client_addr;
      socklen_t client_size;

      client_fd = accept (sock_fd, (struct sockaddr *) &client_addr, &client_size);

      if (client_fd < 0)
      {
         fprintf (stderr, "Accept failed\n");
	 perror ("accept");
      }

      readClient (client_fd);
      j++;
   }

   close (sock_fd);
   return 0;
}
