#ifndef GOLF_H_INCLUDED
#define GOLF_H_INCLUDED

#include <iostream>

using namespace std;

class Golf
{
    private:
        static const int Len = 40;
        char fullname[Len];
        int handicap;

    public:
        Golf(const char * name, int hc = 0);  // konstruktor z handicapem domyslnie ustawianmy na 0
       // void setgolf();         // brak implementacji tego. Uwazam to za niepotrzebne
        void changeHandicap(int hc); // ustawia handicap
        void showgolf(void) const;  // pokazuje golf
};

#endif // GOLF_H_INCLUDED
