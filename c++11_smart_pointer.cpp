#include <iostream>
#include <memory> // shared_ptr/unique_ptr
#include <boost/smart_ptr.hpp> // shared_ptr socped_ptr 

class baseClass {};
class derivedClass : public baseClass {};


int main(int argc, char * argv[]) {

    //C++11 deprecated auto
    std::auto_ptr<baseClass> auto_base(new baseClass);

    //C++11
    std::unique_ptr<baseClass> unique_base(new baseClass);
    std::shared_ptr<baseClass> shared_base(new baseClass);
    std::weak_ptr<baseClass> weak_base(shared_base);

}

