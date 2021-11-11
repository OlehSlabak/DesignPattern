#include <iostream>

template<typename T> struct Property
{
    T value;
    Property(T value)
    {
        *this = value;
    }
    operator T()
    {
        return value;
    }
    T operator=(T new_value)
    {
        return  value = new_value;
    }
};

struct Creature
{
    Property<int> strenght{10};
    Property<int> agility{10};

};


int main() {
    Creature c;
    c.strenght = 11;
    int x = c.agility;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
