#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct shmem_structure
 {
     int field1;
     int field2;

 };


 int main()
 {
     struct shmem_structure *shptr;
     int get_shared_memory_structure(struct shmem_structure *shptr);
     int produceNext();
     int consumeNext();
     int consumed;
while(1)
{

     int produced =  produceNext();
     while(shptr->field2 == 0);
     consumed=shptr->field1;
     consumeNext(consumed);
     shptr->field2 = 0;

}
while(1)
{
     int consumed;
     int produced = produceNext();
     shptr->field1=produced;
     shptr->field2 = 1;
     while(shptr->field2 == 1);
     consumeNext(consumed);

}
return 0;

 }
