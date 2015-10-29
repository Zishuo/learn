#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <boost/timer.hpp>
#include <boost/progress.hpp>

class atomicInt {
  public:
    atomicInt(unsigned int _Int=0):plus_number(_Int) {
       // std::atomic_init(&I,_Int);
    }

    void inc() {
        for (auto i = 0; i != plus_number; ++i) {
            ++I;
        }
    }

    void print_value(std::ostream &out)const {
        out << I <<std::endl;
    }
  private:
    std::atomic_uint I;
    const unsigned int plus_number;
};



class mutexInt {
  private:
    unsigned int I;
    const unsigned int plus_number;
    std::mutex m; //+mutex
    boost::progress_display p;
  public:
    mutexInt(unsigned int _Int=0,unsigned int thread_number=0):I(0),plus_number(_Int),p(plus_number*thread_number) {}
    void incMutex() {
        for (auto i = 0; i != plus_number; ++i) {
            std::lock_guard<std::mutex> g(m); //+ lock & unlock
            ++I;
            ++p;
        }

    }

    void print_value(std::ostream &out)const {
        out << I <<std::endl;
    }
};



int main(int argc, char * argv[]) {
    unsigned thread_number = atoi(argv[1]);
    unsigned plus_number = atoi(argv[2]);

    //using C++ 11 new feature atomic<T> type
    atomicInt t(plus_number);
    std::vector<std::shared_ptr<std::thread>> thread_handle;
    boost::timer timer_1;
    //fork threads
    for (auto i = 0; i != thread_number; ++i) {
        thread_handle.push_back(std::make_shared<std::thread>(&atomicInt::inc,&t));
    }

    //waiting all threads exit.
    for(auto x : thread_handle) {
        x->join();
    }
    std::cout << timer_1.elapsed() << std::endl;
    t.print_value(std::cout);

    //using C++ 11 threads mutex
    mutexInt a_t(plus_number,thread_number);
    thread_handle.clear();
    timer_1.restart();
    for (auto i = 0; i != thread_number; ++i) {
        thread_handle.push_back(std::make_shared<std::thread>(&mutexInt::incMutex,&a_t));
    }

    for(auto x : thread_handle) {
        x->join();
    }

    std::cout << timer_1.elapsed() << std::endl;
    a_t.print_value(std::cout);





    system("PAUSE");

    return 0;
}


