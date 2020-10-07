#include <iostream>

using namespace std;

const int tabSize = 4;

int fill_array(double tab[], int tabSize);
void show_array(const double tab[], int tabSize);
void reverse_array(double tab[], int tabSize);

int main()
{
    double tab[tabSize];
    int wielkoscTablicy = 0;
    wielkoscTablicy = fill_array(tab, tabSize);
    cout << "Tablica zawiera " << wielkoscTablicy << " liczb\n";
    show_array(tab, wielkoscTablicy);
    reverse_array(tab, wielkoscTablicy);
    show_array(tab, wielkoscTablicy);

    cout << "\nKoniec programu" << endl;
    return 0;
}

int fill_array(double tab[], int tabSize)
{
    double liczba;

    int i = 0;
    while(cin >> liczba && i < tabSize)
    {
        tab[i] = liczba;
        ++i;

        if(i == tabSize) break;
    }
    return i;
}

void show_array(const double tab[], int tabSize)
{
    cout << "Twoje liczby: ";
    int i = 0;
    while(i < tabSize)
    {
        cout << tab[i] << " ";
        ++i;
    }
}

void reverse_array(double tab[], int tabSize)
{
    cout << "\nNastepuje odwrocenie tablicy \n";
    double temp;
    int i = 0;
    while(i < tabSize/2)
    {
        temp = tab[i];
        tab[i] = tab[tabSize-1-i];
        tab[tabSize-1-i] = temp;
        ++i;
    }
}
