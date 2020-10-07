#include "complex0.h"

// KONSRUKTORY
complex::complex()
{
    a = 0.0;
    b = 0.0;
}

complex::complex(double a, double b)
{
    this->a = a;
    this->b = b;
}

// METODY
complex complex::operator+(const complex & c)const
{
    complex sum;
    sum.a = this->a + c.a;
    sum.b = this->b + c.b;
    return sum;
}

complex complex::operator-(const complex & c)const
{
    complex temp;
    temp.a = this->a - c.a;
    temp.b = this->b - c.b;
    return temp;
}

complex complex::operator~()const
{
    complex temp;
    temp.a = this->a;
    temp.b = -(this->b);
    return temp;
}

complex complex::operator*(const complex & c)const
{
    complex temp;
    temp.a = this->a * c.a - this->b * c.b;
    temp.b = this->a * c.b + this->b * c.a;
    return temp;
}

// FRIEND
complex operator*(double d, const complex & c)
{
    complex temp;
    temp.a = d * c.a;
    temp.b = d * c.b;
    return temp;
}

ostream & operator<<(ostream & os, const complex & c)
{
    os << "(" << c.a << "," << c.b << "i)";

}

istream & operator>>(istream & is, complex & c)
{
    cout << "Skladowa rzeczywista: ";
    if(is >> c.a)
    {
        cout << "Skladowa urojona: ";
        is >> c.b;
    }
    c.b = 0;
    return is;
}
