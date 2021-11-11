#include <iostream>
#include <functional>

using namespace std;
struct Logger
{
    function<void()> func;
    string name;

    Logger(const function<void()> &func, const string &name) : func(func), name(name) {}
    void operator() () const
    {

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
