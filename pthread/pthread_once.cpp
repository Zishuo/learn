#include <iostream>
#include <pthread.h>
static pthread_once_t once_control = PTHREAD_ONCE_INIT;
void initialized_once()
{

    std::cout <<"initializing..."<< std::endl;

}

void * execute(void *data)
{

    pthread_once(&once_control,initialized_once);

}


int main(int argc, char * argv[])
{
    pthread_t id;
    for(int i = 0; i < 100; ++i)
    {
	pthread_create(&id,NULL,execute,NULL);
    	pthread_detach(id);
    }
    return 0;
}

