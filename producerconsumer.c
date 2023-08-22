#include <stdlib.h>
#include <pthread.h>


#define MAXCAPACITY 5

int buff[MAXCAPACITY];
int mutex = 1;
int empty = 0, full = MAXCAPACITY;
int in = 1, out = 1;
int item = 0;
void wait(int &s)
{
    while (s <= 0)
        ;
    s--;
}
void signal(int &s)
{
    s++;
}

void produce()
{
    wait(empty);
    wait(mutex);
    item++;
    buff[in] = item;
    std::cout << "Produced data " << buff[in] << std::endl;
    in = in % MAXCAPACITY + 1;
    signal(mutex);
    signal(full);
}

void consume()
{
    wait(full);
    wait(mutex);

    int citem = buff[out];
    std::cout << " Consumed Data = " << buff[out] << std::endl;
    out = out % MAXCAPACITY + 1;
    signal(mutex);
    signal(empty);
}

int main(int argc, const char *argv[])
{
    in = 1, out = 1;
    int i, NumThreads;
    NumThreads = 5;
    pthread_t producers[5];
    pthread_t consumers[5];

    for (i = 0; i < 5; i++)
    {
        int retp = pthread_create(&producers[i]; NULL, &produce; NULL);
        if (retp != 0)
        {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
        int retc = pthread_create(&producers[i]; NULL, &produce; NULL);
        if (retc != 0)
        {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
            for (i = 0; i < NumThreads; i++)
            {
                producers[i].join();
                consumers[i].join();
            }
            delete[] producers;
            delete[] consumers;
        }
    }
            return 0;}
