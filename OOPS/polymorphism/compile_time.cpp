#include<bits/stdc++.h>
using namespace std;

class methodOverloading
{
   public:
        void func(int x)
        {
            cout << "Hi I am integer : " << x << endl;
        }

        void func(double x)
        {
            cout << "Hi I am double : " << x << endl;
        }

};


class Complex
{
    private:
        int real,imag;
    
    public:
        Complex(int r=0, int i=0){real=r; imag=i;}
        
        Complex operator + (Complex const &obj)
        {
            Complex res;
            res.real = real +obj.real;
            res.imag = imag + obj.imag;
            return res;
        }

        void print()
        {
            cout << "The complex number is :"<< real << " + i" << imag << endl;
        }
};

int main()
{
    methodOverloading a;
    a.func(5);
    a.func(9.132);

    // opeartor overloading "+"
    Complex c1(4,2) ,c2(8,7);
    Complex c3 = c1+c2;
    c3.print();

    return 0;
}