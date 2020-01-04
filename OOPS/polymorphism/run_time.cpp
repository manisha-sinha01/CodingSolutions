/* In run-time polymorphism we have virtual functions */

#include<bits/stdc++.h>
using namespace std;

class Base
{
    public :
        virtual void print()
        {
            cout << "This is base print function" << endl;
        }

        void show()
        {
            cout << "This is base show" << endl;
        }
};

class Derived : public Base
{
    public :
        virtual void print()
        {
            cout << "This is derived print function" << endl;
        }

        void show()
        {
            cout << "This is derived show" << endl;
        }
};

int main()
{
    Base *b;
    Derived d;
    b = &d;
    // virtual function ;run time polymorphism exceuted
    b->print();
    //normal function : no run-time polymorphism
    b->show();
    return 0;
}