#include <iostream>

using namespace std;

const int poczatkowaKwota = 100;

int main()
{
    double pieniadzeDafine = poczatkowaKwota;
    double pieniadzeCleo = poczatkowaKwota;
    int lata = 0;

    while (pieniadzeDafine >= pieniadzeCleo)
    {
        ++lata;
        pieniadzeDafine += 0.1*poczatkowaKwota;
        pieniadzeCleo = pieniadzeCleo + (0.05 * pieniadzeCleo);

        cout <<"Rok nr: " << lata << endl;
        cout << "Dafine ma: " << pieniadzeDafine << " zlotych\n";
        cout << "Cleo ma: " << pieniadzeCleo << " zlotych\n\n";
    }

    cout << "Dafine ma: " << pieniadzeDafine << " zlotych\n";
    cout << "Cleo ma: " << pieniadzeCleo << " zlotych\n";
    cout << "Cleo bedzie miala wiecej pieniedzy po " << lata << " latach" << endl;


    return 0;
}
