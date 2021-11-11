#include <iostream>

#include <string>
#include <ostream>
#include <vector>
using namespace std;

class CodeBuilder
{
public:
  CodeBuilder(const string& class_name) : className(class_name)
  {

  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
      elements.emplace_back(make_pair(name,type));
      return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
     os << "class " << obj.className << endl;
      os << "{" << endl;

      for (auto& elem : obj.elements)
      {
          os << "  " << elem.second << " " << elem.first << ";" << endl;
      }

      os << "};" << endl;
      return os;
  }

private:
    string className;
    vector<pair<string, string>> elements;
};

int main() {
    auto cb = CodeBuilder{"Person"}.add_field("name","string").add_field("age", "int");
    cout << cb << endl;
    return 0;
}
