#include <pthread.h>
#include <cstdio>
//when create a new thread, we should either detached it or join it.
//Otherwise the memory is leaked because system won't release thread
//resource like stack.


int main()
{
    const int thread_num = 50000;
    pthread_t id[thread_num] = {0};
    for(int i = 0; i < thread_num; ++i)
    {
        pthread_create(&id[i],
                       NULL,
                       [](void * data)
        {
            return (void*)0;
        }
        ,NULL);
        //pthread_detach(id[i]);
    }
    for(int i = 0; i < thread_num; ++i)
    {
        void * status;
        pthread_join(id[i],&status);
    }
    getchar();
}



