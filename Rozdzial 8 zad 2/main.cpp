#include <iostream>

using namespace std;

struct batonik
{
    char * marka;
    double waga;
    int liczbaKalorii;
};

void setBatonik(batonik & baton, char * marka = "Millenium Munch", double waga = 2.85, int liczbaKalorii = 350);
void showBatonik(const batonik baton);

int main()
{
    batonik mars;
    setBatonik(mars, "mars", 11, 111);

    batonik lion;
    setBatonik(lion); // przypisuje wartosci defaultowe


    batonik snickers = {"Snickers", 99, 999};

    showBatonik(mars);
    showBatonik(lion);
    showBatonik(snickers);


    cout << endl << "Hello world!" << endl;
    return 0;
}

void setBatonik(batonik & baton, char * marka, double waga, int liczbaKalorii)
{
    baton.marka = marka;
    baton.waga = waga;
    baton.liczbaKalorii = liczbaKalorii;
}

void showBatonik(const batonik baton)
{
    cout << baton.marka << endl;
    cout << baton.waga << endl;
    cout << baton.liczbaKalorii << endl << endl;
}
