#include <iostream>
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;

    Circle(float radius) : radius(radius) {}

    Circle() {}

    void resize(float factor)
    {
        radius *= factor;
    }

    string str() const override {
        ostringstream oss;
        oss << "A circle of radius" << radius;
        return oss.str();
    }
};

struct Square : Shape
{
    float side;

    Square() {}

    Square(float side) : side(side) {}

    string str() const override {
        ostringstream oss;
        oss << "A square with side: " << side;
        return oss.str();
    }
};

struct ColorShape : Shape
{
    Shape& shape;
    string color;

    ColorShape(Shape &shape, const string &color) : shape(shape), color(color) {}

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has the color: " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& shape;
    unsigned int transparency;

    TransparentShape(Shape &shape, unsigned int transparency) : shape(shape), transparency(transparency) {}

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
        return oss.str();
    }

};

int main() {
    Square square{5};
    ColorShape red_square{square, "red"};

    cout << square.str() << endl;
    cout << red_square.str() << endl;
    TransparentShape my_square{red_square, 51};
    cout << my_square.str() << endl;
    return 0;
}
