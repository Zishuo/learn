#include <iostream>
#include <fstream>

int main (int argc, char * argv[])
{
    if(argc < 2)
    {
        std::cerr << "checkBinary {in file path}" << std::endl;

    }
    std::ifstream in(argv[1],std::ios::binary);
    if(!in.is_open())
    {
        std::cerr<< "can not open file " << argv[1] << std::endl;
    }
    unsigned long long  buffer = 0;
    size_t counter = 0;
    while(in.read((char *)&buffer,sizeof(buffer)))
    {
        ++counter;
        if(argc > 2)
        {
            std::cout << buffer << std::endl;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}








