#include "pthread_queue.hpp"
#include <cstdio>
#include <cstdlib>
BlockingQueue<int> q;

void * consumer(void *)
{
    while(true)
    {
        int i = q.pop();
//        std::cout << "poped " << i << std::endl;
    }
}

void * producer(void *)
{
    static int i = 0;
    while(true)
    {
        q.push(i);
//        std::cout << "pushed " << i << std::endl;
        ++i;
    }
}

int NUM_CSM = 1;
int NUM_PDC = 1;
int main(int argc, char * argv[])
{

    if(argc < 2)
    {
        cerr << "Usage : {consumer_number} {producer_number}" << endl;
    }
    NUM_CSM = std::atoi(argv[1]);
    NUM_PDC = std::atoi(argv[2]);
    pthread_t csmID[NUM_CSM];
    pthread_t pdcID[NUM_PDC];

    for(int i = 0; i < NUM_CSM; ++i)
    {
        pthread_create(csmID + i,NULL,consumer,NULL);
    }
    for(int i = 0; i < NUM_PDC; ++i)
    {
        pthread_create(pdcID + i,NULL,producer,NULL);
    }

    getchar();
    for(int i = 0; i < NUM_CSM; ++i)
    {
        pthread_cancel(csmID[i]);
    }
    for(int i = 0; i < NUM_PDC; ++i)
    {
        pthread_cancel(pdcID[i]);
    }
}









