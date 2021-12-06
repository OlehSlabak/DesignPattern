#include <iostream>
#include <variant>
using namespace std;

struct AddresPrinter
{
    void operator()(const string & house_name) const
    {
        cout << " A house called " << house_name << "\n";
    }
    void operator()(const int house_number) const
    {
        cout << " A house number  " << house_number << "\n";
    }
};



int main() {
    variant<string, int> house;
    house = "Montefiore castle";
  //  house = 123;
  //  AddresPrinter ap;


    std::visit([](auto &arg)
                 {
                    using T = decay_t<decltype(arg)>;
                    if constexpr (is_same_v<T, string>)
                        cout << " A house called " << arg << "\n";
                    else
                        cout << " A house number  " << arg << "\n";
                 }

               , house);


    return 0;
}
