#define _USE_MATH_DEFINES
#define _USE_AUTO_PTR_ETC 1

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#include <fstream>

using namespace std;
#include <boost/lexical_cast.hpp>
using namespace boost;

class SingletonDatabese
{
    SingletonDatabese() {

        cout << "Init database\n";
        ifstream ifs("C:\\DesignPattern\\Singleton\\Singleton\\capitals.txt");
        string  s, s2;
        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;
public:
    SingletonDatabese(SingletonDatabese const&) = delete;
    void operator=(SingletonDatabese const&) = delete;
    static SingletonDatabese& get()
    {
        static SingletonDatabese db;
        return db;
    }
    int get_population(const string& name)
    {
        return capitals[name];
    }

};

struct SingletonRecordFinder
{
    int total_population(vector<string> names)
    {
        int result{0};
        for (auto& name : names)
            result += SingletonDatabese::get().get_population(name);
        return result;
    }
};

int main() {
    string city = "Tokyo";
    cout << city << " has population " <<
    SingletonDatabese::get().get_population(city) << endl;

    return 0;
}
