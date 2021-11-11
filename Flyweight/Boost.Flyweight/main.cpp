#include <iostream>
#include <string>
#include <vector>
using namespace std;


class FormatText
{
    string plain_text;
    bool *caps;
public:
    FormatText(const string &plainText) : plain_text(plainText) {
        caps = new bool[plain_text.length()];
        memset(caps, 0, plain_text.length());
    }

    virtual ~FormatText() {
    delete caps;
    }

    void capitalize(int start, int end)
    {
        for (int i = start; i <= end; i++)
            caps[i] = true;
    }

    friend ostream &operator<<(ostream &os, const FormatText &text) {
        string s;
        for (int i=0; i < text.plain_text.length(); i++)
        {
            char c = text.plain_text[i];
            s += (text.caps[i] ? toupper(c) : c);
        }
        os << s;
        return os;
    }
};

class BetterFormatText
{
public:
    struct TextRange
    {
        int start, end;
        bool capitalize;

        bool covers(int position) const
        {
            return position >= start && position <= end;
        }
    };
    TextRange& get_range(int start, int end)
    {
        formatting.emplace_back(TextRange{start, end});
        return *formatting.rbegin();
    }

    BetterFormatText(const string &plainText) : plain_text(plainText) {}

    friend ostream &operator<<(ostream &os, const BetterFormatText &text) {
        string s;

        for (int i=0; i < text.plain_text.length(); i++)
        {
           auto c = text.plain_text[i];
           for (const auto& rng : text.formatting)
           {
               if (rng.convers(i) && rng.capitalize)
                   c = toupper(c);
               s+=c;
           }
        }
        os << s;
        return os;
    }

private:
    string plain_text;
  vector<TextRange> formatting;

};

int main() {

    FormatText ft{"This is a breve new world"};
    ft.capitalize(10, 15);
    cout << ft << endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
