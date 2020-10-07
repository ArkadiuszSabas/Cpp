#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    const int tabSize = 20;

    cout <<"Podaj swoje imie: " << endl;
    char imie[tabSize];
    cin.getline(imie, tabSize); // spowoduje wczytanie maksymalnie 20 znakow (czyli tyle ile ma wielkosc tablicy)
    imie[tabSize-1] = '\0';     // doda na sam koniec tablicy znakow znak NULL na wypadek gdyby uzytkownik podal 20 lub wiecej znakow

    cout << "Podaj swoje nazwisko: " << endl;
    char nazwisko[tabSize];
     cin.getline(nazwisko, tabSize);
    imie[tabSize-1] = '\0';

    char personalia[tabSize*2] {0}; // stworzenie tablicy zankow zawierajacej same nulle (pusta tablica)
    strcat(personalia, imie);
    strcat(personalia, ", ");
    strcat(personalia, nazwisko);

    cout << "Oto twoje personalia: " << personalia << endl;

    return 0;
}
