#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <ostream>
using namespace std;
struct  HtmlBuilder;

struct HtmlElement
{
    friend class HtmlBuilder;
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;
    HtmlElement() {}

    HtmlElement(const string &name, const string &text) : name(name), text(text) {}
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size*indent, ' ');

        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size*(indent + 1), ' ') << text << endl;

        for (const auto &e : elements)
            oss << e.str(indent + 1);
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
   /* static HtmlBuilder build(string root_name)
    {
        return {root_name};
    }*/
};

struct  HtmlBuilder
{
    friend class HtmlElement;
    HtmlElement root;

    HtmlBuilder( string root_name)
    {
        root.name = root_name;
    }
    HtmlBuilder& add_child(string child_name, string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return  *this;
    }

    string  str() const { return  root.str();}
};

int main() {

    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello").add_child("li", "world");

    cout << builder.str() << endl;

    return 0;
}
