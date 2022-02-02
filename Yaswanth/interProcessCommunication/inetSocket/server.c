#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1000

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
   char ipaddr[MAX_SIZE];
   printf ("Enter the IP address:\t");
   gets (ipaddr);
   int ret = 0;
   int sock_fd = 0;
   sock_fd = socket (PF_INET, SOCK_STREAM, 0);

   if (sock_fd < 0)
   {
      perror ("socket");
   }

   //create address structure object for inet socket
   //
   struct sockaddr_in addr;
   memset (&addr, 0, sizeof(struct sockaddr_in));
   addr.sin_family = AF_INET;
   addr.sin_port = htons(9784);
   addr.sin_addr.s_addr = inet_addr (ipaddr);

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
      struct sockaddr_in client_addr;
      memset (&client_addr, 0, sizeof(struct sockaddr_in));
      socklen_t client_size = 0;

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
