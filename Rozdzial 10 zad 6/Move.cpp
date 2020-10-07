#include <iostream>
#include "Move.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    cout << "x = " << x << ", y = " << y << endl;
}

Move Move::add(const Move & m) const
{
    double x = this->x + m.x;
    double y = this->y + m.y;

    Move temp(x, y);
    return temp;
}

void Move::setParameters(double a, double b)
{
    x = a;
    y = b;
}
