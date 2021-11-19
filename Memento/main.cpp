#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Memento
{
    int balance;
public:
    Memento(int balance) : balance(balance) {}
    friend class BankAccount;
    friend class BankAccount2;
};

class BankAccount
{
    int balance{0};
public:
    BankAccount(int balance) : balance(balance) {}
    Memento deposit(int amount)
    {
        balance += amount;
        return Memento{balance};
    }

    void restor(const Memento& m)
    {
        balance = m.balance;
    }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &account) {
        os << "balance: " << account.balance;
        return os;
    }
};

class BankAccount2
{
    int balance{0};
    vector<shared_ptr<Memento>> changes;
    int current; //
public:
    BankAccount2(int balance) : balance(balance) {
        changes.emplace_back(make_shared<Memento>(balance));
        current = 0;
    }

    shared_ptr<Memento> deposit(int amount)
    {
        balance += amount;
        auto m = make_shared<Memento>(balance);
        changes.push_back(m);
        ++current;
        return m;
    }

    void restor(const shared_ptr<Memento> &m)
    {
        if (m)
        {
            balance = m->balance;
            changes.push_back(m);
            current = changes.size() - 1;
        }
    }

    shared_ptr<Memento> undo() {
        if (current > 0)
        {
            --current;
            auto m = changes[current];
            balance = m->balance;
            return m;
        }

        return {};
    }

    shared_ptr<Memento> redo()
    {
        if (current + 1 < changes.size())
        {
            ++current;
            auto m = changes[current];
            balance = m->balance;
            return m;
        }
        return {};
    }

    friend ostream &operator<<(ostream &os, const BankAccount2 &account2) {
        os << "balance: " << account2.balance;
        return os;
    }
};

int main() {

    BankAccount2 ba2{100};
    ba2.deposit(50); // 150
    ba2.deposit(25); // 175

    cout << ba2 << endl;

    ba2.undo();
    cout << " Undo 1 :" << ba2 << endl;
    ba2.undo();
    cout << " Undo 2 :" << ba2 << endl;
    ba2.redo();
    cout << " Redo  :" << ba2 << endl;

    BankAccount ba{100};
    auto m1 = ba.deposit(50); // 150
    auto m2 = ba.deposit(25); // 175

    cout << ba << "\n";

    ba.restor(m1);
    cout << "back to m1: " << ba << "\n";
    ba.restor(m2);
    cout << "back to m2: " << ba << "\n";

    return 0;
}
