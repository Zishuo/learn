//zishuo
//Apr. 10th 2014
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <random>
#include <boost/progress.hpp>
const int B_SIZE = 1024*1024;
unsigned long long buffer[B_SIZE];
int main(int argc, char * argv[])
{
    //gen number
    //out file = cout
    //binary
    if(argc < 2)
    {
        std::cerr <<" intgen {amount} [{out file}]=cout" << std::endl;
        return 1;
    }
    bool is_cout = true;
    std::ofstream out_file(argv[2],std::ios::binary | std::ios::out | std::ios::trunc);
    if(argc > 2)
    {
        if(!out_file.is_open())
        {
            std::cerr << " out file can not be open." << std::endl;
            return 2;
        }
        else
        {
            is_cout = false;
        }
    }

    std::srand(std::time(0)); // use current time as seed for random generator

    int i = atoi(argv[1]);

    boost::progress_timer t(std::cerr);

    std::random_device seed;
    std::mt19937_64 rander(seed());
    if(is_cout == true)
    {
        while(i--)
        {
            std::cout << rander() << std::endl;
        }
    }
    else
    {

        int pos = 0;
        while(i--)
        {
            buffer[pos] = rander();
            if(pos == B_SIZE - 1)
            {
                out_file.write((char *)buffer,sizeof(unsigned long long)*B_SIZE);
                pos = 0;
            }
            else
            {
                pos++;
            }
        }
        if(pos != 0)
        {
            out_file.write((char *)buffer,sizeof(unsigned long long)*(pos));
        }
    }
    return 0;
}







