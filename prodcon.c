#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

void *produceNext();
void *consumeNext();
int x=1;

int produced,consumed;
pthread_mutex_t l;

int main()
{

    pthread_mutex_init(&l,NULL);
    pthread_t p,c;
    pthread_create(&p,NULL,produceNext(),NULL);
    pthread_create(&c,NULL,consumeNext(),NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);


}
    void *produceNext()
    {
        for (int i = 0; i <5; i++) {


        pthread_mutex_lock(&l);
        x++;
        produced=x;
        printf("%d",produced);
        pthread_mutex_unlock(&l);
        }


    }
    void *consumeNext()
{
    for (int i = 0; i < 5; i++) {

        pthread_mutex_lock(&l);
        consumed=x;
        printf("%d",consumed);
        x--;
        pthread_mutex_unlock(&l);
    }


    }




