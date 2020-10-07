#ifndef COMPLEX0_H_INCLUDED
#define COMPLEX0_H_INCLUDED

#include <iostream>
using namespace std;

class complex
{
    private:
        double a;
        double b;

    public:
        complex();    // konstruktor domyslny
        complex(double a, double b);   // konstruktor konkretny

        complex operator+(const complex & c)const;
        complex operator-(const complex & c)const;
        complex operator~()const;
        complex operator*(const complex & c)const;

        friend complex operator*(double d, const complex & c);
        friend ostream & operator<<(ostream & os, const complex & c);
        friend istream & operator>>(istream & is, complex & c);

};

#endif // COMPLEX0_H_INCLUDED
