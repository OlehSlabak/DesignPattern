#include <iostream>
#include <chrono>
using namespace std;
int main()
{

    auto start =  std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now() + std::chrono::seconds(6);

    while(std::chrono::steady_clock::now() >= end)
    {
        cout << "___ " << endl;
    }

    while(std::chrono::steady_clock::now() <= end)
    {
        cout << "+++ " << endl;
    }

    auto end2= std::chrono::steady_clock::now();
    auto diff =  start - end2;
    cout << "DF" << diff.count();
}