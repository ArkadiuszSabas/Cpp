//arrobj.cpp -- funkcje z obiektami typu array (C++11)
#include <iostream>
#include <array>
#include <string>

// dane sta�e
const int Seasons = 4;
const char * Snames[Seasons] = {"Wiosna", "Lato", "Jesie�", "Zima"};   // tablica wskaznikow lanuchow znakowych

struct Bilans
{
    double expenses[Seasons];
};

// funkcja ktora modyfikuje ale nie oryginal lecz kopie bo jest przekazywana struktura przez wartosc
void fillPrzezValue(Bilans rok);

// funkcja modyfikuj�ca tablic�
void fill(Bilans * rok);

// funkcja przetwarzaj�ca tablic�
void show(const Bilans rok);

int main()
{
    Bilans rok;
    fillPrzezValue(rok);
    show(rok);   // pokaze bledne dane bo przekazywanie struktury przz wartosc nie zmienia oryginalnych parametrow
    fill(&rok);
    show(rok);
    return 0;
}

void fillPrzezValue(Bilans rok)
{
    using namespace std;
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
        cin >> rok.expenses[i];
    }
}

void fill(Bilans * rok)
{
    using namespace std;
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
        cin >> rok->expenses[i];
    }
}

void show(Bilans rok)
{
    using namespace std;
    double total = 0.0;
    cout << "\nWYDATKI\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": " << rok.expenses[i] << " z�" << endl;
        total += rok.expenses[i];
    }
    cout << "��cznie wydatki roczne: " << total << " z� " << endl;
}
