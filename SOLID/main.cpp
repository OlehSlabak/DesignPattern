
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

/* Every class should have only one responsibility */
namespace SingleResponsibility
{
    struct Journal
    {
        string title;
        vector<string> entires;

        Journal(const string &title) : title(title) {}

        void add_entry(const string &entry)
        {
            static int count = 1;
            entires.push_back(lexical_cast<string>(count++) + ": " + entry);
        }

    };

    struct PersistenceManager
    {
        void save(const Journal &j, const string &filename)
        {
            ofstream ofs(filename);
            for (auto &e : j.entires)
                ofs << e << endl;
        }
    };

    void run_function()
    {
        SingleResponsibility::Journal journal{"Oleh"};
        journal.add_entry("Hello ");
        journal.add_entry("world");

        PersistenceManager pm;
        pm.save(journal, "diary.txt");
    }
}
/*
 * Software entities should be open for extension,
 * but closed for
*/
namespace OpenClosed
{
   enum class Color {red, green, blue};
   enum class Size {small, medium, large};
   struct Product
   {
       string name;
       Color color;
       Size size;
   };

   struct ProductFilter
   {
       vector<Product*> by_color(vector<Product*> items, Color color)
       {
           vector<Product*> result;
           for (auto &i : items)
               if (i->color == color)
                   result.push_back(i);
           return result;
       }
   };
   template<typename T> struct Specification;

   template <typename T> struct AndSpecification : Specification<T>
    {
        Specification<T> &first;
        Specification<T> &second;

        AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}

        bool is_satisfied(T *item) override {
            return first.is_satisfied(item) && second.is_satisfied(item);
        }
    };

   template<typename T> struct Specification
   {
       virtual bool  is_satisfied(T *item) = 0;
       AndSpecification<T> operator&&(Specification<T>&& other)
       {
           return AndSpecification<T>(*this, other);
       }
   };

    template<typename T> struct Filter
    {
        virtual vector<T*>  filter(vector<T*> item, Specification<T> &spec) = 0;
    };
    struct BetterFilter: Filter<Product>
    {
        vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
        {
            vector<Product*> results;
            for (auto &item : items)
                if (spec.is_satisfied(item))
                    results.push_back(item);

            return results;
        }
    };

    struct ColorSpecification : Specification<Product>
    {
        Color color;
        ColorSpecification(Color color) : color(color) {}
        bool is_satisfied(Product *item) override {
            return item->color == color;
        }
    };

    struct SizeSpecification : Specification<Product>
    {
        Size size;
        SizeSpecification(Size size) : size(size) {}
        bool is_satisfied(Product *item) override {
            return item->size == size;
        }
    };

   void run_function()
   {
       Product apple{"Apple", Color::green, Size::small};
       Product tree{"Tree", Color::green, Size::large};
       Product house{"House", Color::blue, Size::large};

       vector<Product*> items {&apple, &tree, &house};
      /* ProductFilter pf;
       auto green_things = pf.by_color(items, Color::green);
       for ( auto &item : green_things)
           cout << item->name << endl;*/
       BetterFilter bf;
       ColorSpecification green(Color::green);
       for (auto  &item : bf.filter(items, green))
           cout << item->name << endl;

       ColorSpecification blue(Color::blue);
       SizeSpecification large(Size::large);
       AndSpecification<Product> blue_and_large(blue, large);
       for (auto &item: bf.filter(items, blue_and_large))
           cout << item->name << endl;

       auto specF = ColorSpecification(Color::green) &&
                    SizeSpecification(Size::large);

       for (auto &item: bf.filter(items, specF))
           cout << item->name << endl;
   }
}
/*
 * Functions that use pointers or
 * references to base classes must be able to use objects
 * of derived classes without knowing it
*/
namespace Liskov
{
    class Rectangle
    {
    protected:
        int width, height;
    public:
        Rectangle(int width, int height) : width(width), height(height) {}

        virtual int getWidth() const {
            return width;
        }

        virtual void setWidth(int width) {
            Rectangle::width = width;
        }

       virtual int getHeight() const {
            return height;
        }

        virtual void setHeight(int height) {
            Rectangle::height = height;
        }
        int area() const { return width * height; }

    };

    void process (Rectangle &r)
    {
        int w = r.getWidth();
        r.setHeight(10);

        cout << "expected area = " << (w * 10)  << ", got " << r.area() << endl;
    }

    class Square : public Rectangle
    {
    public:
        Square(int size) : Rectangle(size, size) {}

        void setWidth(int width) override {
            this->width = this->height = width;
        }

        void setHeight(int height) override {
            this->width = this->height = height;
        }
    };

    void run_function()
    {
        Rectangle r{3,4};
        process(r);
    }
}

namespace InterfaceSegregation
{
        struct Document;
         struct IPrinter
         {
             virtual void print(Document &doc) = 0;
         };

         struct IScanner
         {
             virtual void scan(Document &doc) = 0;
         };
         struct IFax
         {
             virtual void fax(Document &doc) = 0;
         };

         struct Printer : IPrinter
         {
             void print(Document &doc) override {
                 
             }
         };
         struct Scanner : IScanner
         {
             void scan(Document &doc) override {

             }
         };

        struct Machine : IPrinter, IScanner
        {
            IPrinter &printer;
            IScanner &scanner;

            Machine(IPrinter &print, IScanner &scanner) : printer(print), scanner(scanner) {}

            void print(Document &doc) override {
                    printer.print(doc);
            }

            void scan(Document &doc) override {
                     scanner.scan(doc);
            }
        };

}

namespace DependencyInversion
{
    enum class Relationship
    {
        parent,
        child,
        sibling
    };

    struct Person
    {
        string name;
    };

    struct RelationshipBrowser
    {
        virtual vector<Person> find_all_children_of(const string& name) = 0;
    };

    struct Relationships  : RelationshipBrowser
    {
        vector<tuple<Person, Relationship, Person>> relations;
        void  add_parent_and_child(const Person& parent, const Person& child)
        {
            relations.push_back({parent, Relationship::parent, child});
            relations.push_back({child, Relationship::child, parent});
        }

        vector<Person> find_all_children_of(const string &name) override {
            vector<Person> results;
            for (auto &&[first, rel, second] : relations)
            {
                 if (first.name == name && rel == Relationship::parent)
                     results.push_back(second);
            }
            return results;
        }
    };    /*lov-level*/
    struct Research       /*high-level*/
    {
        Research(RelationshipBrowser &browser)
        {
             for (auto &child : browser.find_all_children_of("John"))
                 cout << "John has a child called " << child.name << endl;
        }
//          Research(Relationships &relation)
//          {
//              auto &relations = relation.relations;
//              for (auto &&[first, rel, second] : relations)
//              {
//                  if (first.name == "John" && rel == Relationship::parent)
//                      cout << "John has a child called " << second.name << endl;
//              }
//          }
    };
     void run_function()
     {
       Person parent{"John"};
       Person child1{"Chris"}, child2{"Matt"};

       Relationships relationships;
       relationships.add_parent_and_child(parent, child1);
       relationships.add_parent_and_child(parent, child2);

       Research _(relationships);
     }
}
int main()
{
  //  SingleResponsibility::run_function();
   // OpenClosed::run_function();
  // Liskov::run_function();
  DependencyInversion::run_function();
    return 0;
}