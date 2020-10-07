// mytime3.h -- klasa Time z funkcjami zaprzyjaünionymi
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

using std::ostream;

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);

    // zaprzyjaznione przeciazone operactory
        friend Time operator+(const Time & t, const Time & w);
        friend Time operator-(const Time & t, const Time & w);
        friend Time operator*(const Time & t, double n);
        friend Time operator*(double m, const Time & t);

        friend ostream & operator<<(ostream & os, const Time & t);
};
#endif

