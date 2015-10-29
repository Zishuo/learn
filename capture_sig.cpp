#include <cstdio>
#include <signal.h>
static void sig_int(int);

void sig_int(int signo)
{
    printf( "interrupted\n");
}
int main()
{
    signal(SIGINT,sig_int);

    while(getchar())
    {
    }
}

