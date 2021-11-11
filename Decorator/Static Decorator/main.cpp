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

   explicit Circle(const float radius) : radius(radius) {}

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

// mixin inheritance
// perfect forwarding

template<typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;

template <IsAShape T>
struct ColorShape2 : T
{
    string color;

    ColorShape2(const string &color):color(color) {}

    ColorShape2() {}

    template<typename...Args>
    ColorShape2(const string &color, Args ...args) : T(std::forward<Args>(args)...), color{color} {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

int main() {
    ColorShape2<Circle> green_circle{"green", 5};

   /* Square square{5};
    ColorShape red_square{square, "red"};

    cout << square.str() << endl;
    cout << red_square.str() << endl;
    TransparentShape my_square{red_square, 51};
    cout << my_square.str() << endl;*/
    return 0;
}
