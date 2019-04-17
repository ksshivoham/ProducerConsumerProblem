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
struct shmem_structure *shptr = get_shared_memory_structure();
while(1) 
{

     int produced = produceNext();
     int produced = produceNext(); 
     shptr->field1=produced;
     shptr->field2 = 1;
     printf("p");
}
struct shmem_structure *shptr = get_shared_memory_structure();
while(1) 
{ 
     int consumed;
     consumeNext(consumed);
     while(shptr->field2 == 0);
     consumed=shptr->field1;
     consumeNext(consumed);
     shptr->field2 = 0;
     printf("c");
    
}
return 0;

 }