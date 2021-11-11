
#include <iostream>
#include <memory>
#include <cmath>
#include <string>
using namespace  std;

class Point
{
   // friend class PointFactory; // Open close principle  fail

    Point(float x, float y) : x(x), y(y) {}
    float x,y;
    struct PointFactory
    {
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        }
        static Point NewPolar(float r, float theta)
        {
            return { r*cos(theta), r*sin(theta)};
        }
    };
public:
    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
    static PointFactory pointFactory;
};



int main() {
    auto p = Point::pointFactory.NewPolar(5, M_PI_4);
    cout << p << endl;
    return 0;
}


