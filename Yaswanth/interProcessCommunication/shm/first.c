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
   int seg_id = 0;


   // shmget allocate the shared memory segment and returns the segment id
   // first argument is the key | it will selected by user (any random value is fine | For new memory segment use IPC_PRIVATE)
   // Second argument is how much size of memory you want to allocate
   // Third argument is combination of multiple stuffs. You can provide here the way segment needs to be created like IPC_CREAT | IPC_EXCL means check if a segment with the given key is already available if yes then return -1. If the memory is not available with the given key allocate the memory segment and return the segment id
   // Here we have received the segment id in seg_id variable.
   // In third argument itself, you can provide the permissions also, e.g, this permission I have provide means, Read for the OWNER and Write for the OWNER
   // After creating this segment you can check its status by running the command ipcs -m

   seg_id = shmget (KEY, MAX_SIZE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

   printf ("Segment Id %d \n", seg_id);

   char * a;
   // After the memory allocate you have to attach this memory segment in your virtual address space
   // For this you have to use shmat system call
   // In shmat system call, provide first argument as segment id of the allocated memory
   // As second argument, please provide the virtual address where you want to map the shared memory segment. If you are providing some virtual address in here, you have to be very careful because the shared memory segment is Page aligned but the virtual address space of the process is byte aligned.Here some conversions are required. Where you want to map the Shared memory segment, you have conver the alignment of that address from byte aligment to nearest page aligment (Pass SHM_RND to the function shmat as third argument for this purpose)
   // If you don't know the available virtual address  in your virtual address space you just provide NULL as second argument, OS will search available virtual address and will map the shared memory segment for you. In this scenario, please provide 0 as third argument since you don't need to worry about the page aligment conversions also. e.g., below statement.
   // shmat function will return the first address of the virtual address space where OS has mapped the shared memory region
   a = (char *) shmat (seg_id, NULL, 0);

   // writing something at the shared memory
   strcpy (a, "Hello World!!");
   //After use of that segment detach it from you virtual address space.
   //Pass the first adress which was provided by shmat.
   shmdt (a);
   return 0;
}
