#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/progress.hpp>
const int B_SIZE = 1024 * 1024 * 100;
int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::cerr << "sort {file path}" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1],std::ios::binary);
    if(!in.is_open())
    {
        std::cerr << "file can not be opened" << std::endl;
        return 2;
    }
    std::vector<unsigned long long> buffer;
    unsigned long long word;
    unsigned short file_counter = 0;
    while(in.read((char*)&word,sizeof(unsigned long long)))
    {
        if(buffer.size() ==  B_SIZE)
        {
            {

                boost::progress_timer timer_sort;
                std::sort(buffer.begin(), buffer.end());
            }
            {
                boost::progress_timer timer_out;
                std::string out_name(argv[1]);
                out_name.append(".sorted");
                out_name.append(std::to_string(file_counter));
                std::ofstream out(out_name,std::ios::binary | std::ios::trunc);

                for(unsigned long long i : buffer)
                {
                    out.write((char *)&i, sizeof(unsigned long long));
                }
                buffer.clear();
            }
        }
        buffer.push_back(word);
    }

    if(buffer.size() !=  0)
    {
        {

            boost::progress_timer timer_sort;
            std::sort(buffer.begin(), buffer.end());
            std::cout << "sorted " << buffer.size() << std::endl;
        }
        {
            boost::progress_timer timer_out;
            std::string out_name(argv[1]);
            out_name.append(".sorted");
            out_name.append(std::to_string(file_counter));
            std::ofstream out(out_name,std::ios::binary | std::ios::trunc);


            for(unsigned long long i : buffer)
            {
                out.write((char *)&i, sizeof(unsigned long long));
            }
            buffer.clear();
        }
    }
    return 0;
}

