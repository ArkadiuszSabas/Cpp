#include <iostream>

using namespace std;

double obliczSrednia(double a, double b);

int main()
{
    double a,b;
    double sredniaHarmoniczna = 0;

    while(true)
    {
        cout << "Podaj dwie liczby. Liczba 0 konczy program." << endl;
        cin >> a;
        if ( 0 == a ) break;
        cin >> b;
        if ( 0 == b ) break;

        sredniaHarmoniczna = obliczSrednia(a,b);
        cout << "Srednia harmoniczna: " << sredniaHarmoniczna << endl;
    }

    cout << "Koniec programu" << endl;
    return 0;
}

double obliczSrednia(double a, double b)
{
    double sredniaHarmoniczna = 0;
    return sredniaHarmoniczna = (2.0*a*b)/(a+b);
}
