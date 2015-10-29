#include <iostream>
using namespace std;
struct foo
{
    foo() {};
    foo(const foo & lvalue)
    {
        cout << "foo copy." <<endl;
    };

    int a;
    double b;
    char c[16];
};

struct bar
{
    bar() {};
    bar(const bar & lvalue)
    {
        a = lvalue.a;
        b = lvalue.b;
        cout << "bar copy" << endl;
    }
    bar(bar && rvalue)
    {
        c = rvalue.c;
        rvalue.c = nullptr;
        cout << "bar move" << endl;
    }

    bar& operator=(bar && rvalue)
    {
        a = rvalue.a;
        b = rvalue.b;
        return *this;
    }
    int a;
    double b;
    char *c;
};

foo fun_foo()
{

    foo f;
    return f;
}

bar fun_bar()
{

    bar b;
    return b;
}

int main()
{
    foo f = fun_foo();
    bar b = fun_bar();
    //bar b2(std::move(b));
    //bar b3 = b2;
    //cout << "b2 = std::move(b3);" << endl;
    //b2 = std::move(b3);
    //b2 = b3;

    cout << "you'll see nothing but this line which means the compiler has the return value optimization." << endl;
}





