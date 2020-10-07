//arrobj.cpp -- funkcje z obiektami typu array (C++11)
#include <iostream>
#include <array>
#include <string>

// dane sta³e
const int Seasons = 4;
const char * Snames[Seasons] = {"Wiosna", "Lato", "Jesieñ", "Zima"};   // tablica wskaznikow lanuchow znakowych

// funkcja modyfikuj¹ca tablicê
void fill(double expenses[]);

// funkcja przetwarzaj¹ca tablicê
void show(double expenses[]);

int main()
{
    double expenses[Seasons];
    fill(expenses);
    show(expenses);
    return 0;
}

void fill(double expenses[])
{
    using namespace std;
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
        cin >> expenses[i];
    }
}
void show(double expenses[])
{
    using namespace std;
    double total = 0.0;
    cout << "\nWYDATKI\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": " << expenses[i] << " z³" << endl;
        total += expenses[i];
    }
    cout << "£¹cznie wydatki roczne: " << total << " z³ " << endl;
}
