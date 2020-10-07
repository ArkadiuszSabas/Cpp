#include <iostream>

using namespace std;

const int tabSize = 6;

double * fill_array(double * tabBegin, double * tabEnd);
void show_array(const double * tabBegin, const double * tabEnd);
void reverse_array(double * tabBegin, double * tabEnd);

int main()
{
    double tab[tabSize];
    double * koniecTablicy;
    koniecTablicy = fill_array(tab, tab + tabSize); // dwa wskazniki wskazujace poczatek i koniec tablicy. Nie trzeba & bo nazwa tablicy to wskaznik
    cout << "Tablica zawiera " << koniecTablicy - tab << " liczb\n"; // po prostu sie odejmuje poczatek od konca
    show_array(tab, koniecTablicy);
    reverse_array(tab, koniecTablicy);
    show_array(tab, koniecTablicy);

    cout << "\nKoniec programu" << endl;
    return 0;
}

double * fill_array(double * tabBegin, double * tabEnd) // mimo ze operujemy na wskazniku to ORYGINALNY ADRES TABLICY NIE ZMIENIA SIE !!!!
{
    double liczba;
    double * pt;

    while(cin >> liczba)   // petla przerwie sie gdy zostanie wpisana niepoprawna liczba
    {
        *tabBegin = liczba;
        tabBegin++;
        pt = tabBegin;

        if(tabBegin == tabEnd) break;   // lub gdy wypelni sie cala tablica
    }
    return pt;
}

void show_array(const double * tabBegin, const double * tabEnd)
{
    cout << "Twoje liczby: ";

//    for(const double * pt = tabBegin; pt != tabEnd; pt++)
//    {
//        cout << *pt << " ";
//    }

    while(tabBegin != tabEnd)   // mozna jednym z tych dwoch sposobow. Ten jest lepszy bo nie trzeba deklarowac dodatkowego wskaznika *pt
    {
        cout << *tabBegin << " ";
        tabBegin++;
    }
    cout << endl;


}

void reverse_array(double * tabBegin, double * tabEnd)
{
    cout << "\nNastepuje odwrocenie tablicy \n";
    double temp;
    while(tabBegin < tabEnd)
    {
      temp = *tabBegin;
      *tabBegin = *(tabEnd-1);
      *(tabEnd-1) = temp;
      --tabEnd;
      ++tabBegin;
    }
}
