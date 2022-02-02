#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 100
#define KEY 120

int main ()
{
   // In this program you don't need to allocate any shared memory, since memory has already been allocated by the first program, you just need to get the segment id of that segment using the command "ipcs -m"
   // Now you can use that segment id to attach that shared memory segment into this virtual address space
   // See the comments about usage of "shmat()" system call
   int seg_id;

   //printf ("Enter the segment id you want to access:\t");
   //scanf ("%d", &seg_id);
   
   // Here don't mention IPC_CREAT beacuse OS will try to create the memory
   // This function is working fine.
   seg_id = shmget (KEY, MAX_SIZE, IPC_EXCL | S_IRUSR | S_IWUSR);

   printf ("Segment Id %d\n", seg_id);
   char * a;

   a = (char *) shmat (seg_id, NULL, 0);

   printf ("%s", a);

   printf ("\n");
   shmdt (a);

   // here we are going to delete the shared memory
   // shmctl function is used for many operations, one operation is to delete shared memory segment other operations are getting the shared memory status etc.
   // first argument is segment id of the SHM segment
   // second argument id command that need to be performed (IPC_RMID means deleting the Segment)
   // This argument is if you want to get the status of the SHM segment, you have provide the address of the status structure used for SHM status please check the "man shmctl" for status structure.
   // Here we are going to delete the SHM segment so just provide NULL here.
   shmctl (seg_id, IPC_RMID, NULL);
   return 0;
}
