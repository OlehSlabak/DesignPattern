#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Token
{
    enum Type {integer, plus, minus, lparen, rparen} type;
    string text;

    Token(Type type, const string &text) : type(type), text(text) {}

    friend ostream &operator<<(ostream &os, const Token &token) {
        os << "'" << token.text << "'";
        return os;
    }
};

vector<Token> lex(const string& input)
{
    vector<Token> result;
    for (int i = 0; i < input.size(); ++i) {
        switch (input[i]) {
            case '+':
                result.push_back(Token{Token::plus, "+"});
                break;
            case '-':
                result.push_back(Token{Token::minus, "-"});
                break;
            case '(':
                result.push_back(Token{Token::lparen, "("});
                break;
            case ')':
                result.push_back(Token{Token::rparen, ")"});
                break;
            default:
                ostringstream buffer;
                buffer << input[i];
                for (int j = i+1; j < input.size(); j++) {
                    if (isdigit(input[j]))
                    {
                        buffer << input[j];
                        ++i;
                    }
                    else
                    {
                        result.push_back(Token{Token::integer, buffer.str()});
                        break;
                    }
                }
        }
    }
    return result;
}

struct Element
{
    virtual int eval() const = 0;
};

struct Integer : Element
{
    int value;
    Integer(int value) : value(value) {}

    int eval() const override {
        return value;
    }
};

struct BinaryOperation : Element
{
    enum Type {additional, subtraction} type;
    shared_ptr<Element> lhs, rhs;

    int eval() const override {
        auto left = lhs->eval();
        auto right = rhs->eval();
        if (type == additional)
            return left + right;
        else
            return left - right;
    }
};

unique_ptr<Element> parse(const vector<Token>& tokens)
{
    auto result = make_unique<BinaryOperation>();
    bool have_lhs{false};

    for (size_t i = 0; i < tokens.size(); i++)
    {
        auto token = tokens[i];
        switch (token.type)
        {
            case Token::integer:
            {
                int value = stoi(token.text);
                auto integer = make_shared<Integer>(value);
                if (!have_lhs) {
                    result->lhs = integer;
                    have_lhs = true;
                } else result->rhs = integer;
            }
                 break;
            case Token::plus:
                result->type = BinaryOperation::additional;
                break;
            case Token::minus :
                result->type = BinaryOperation::subtraction;
                break;
            case Token::lparen :
            {
                int j = 1;
                for (; j < tokens.size(); ++j)
                    if (tokens[j].type == Token::rparen)
                        break;

                vector<Token> subexpression(&tokens[i+1], &tokens[j]);
                auto element = parse(subexpression);
                if (!have_lhs)
                {
                    result->lhs = move(element);
                    have_lhs = true;
                }
                else
                    result->rhs = move(element);
                i = j;
            }
            break;
        }
    }
    return result;
}

int main() {
    string input{"(13-4)-(12+1)"};

    auto tokens = lex(input);
    for (auto &t : tokens)
        cout << t << " ";
    cout << endl;

    try {
        auto parsed = parse(tokens);
        cout << input << " = " << parsed->eval() << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
