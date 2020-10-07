#include <iostream>

using namespace std;

int main()
{

    cout <<"Podaj swoje imie: " << endl;
    string imie;
    getline(cin, imie);

    cout << "Podaj swoje nazwisko: " << endl;
    string nazwisko;
    getline(cin, nazwisko);

    string personalia; // stworzenie tablicy zankow zawierajacej same nulle (pusta tablica)
    personalia = imie + ", " + nazwisko;
    cout << "Oto twoje personalia: " << personalia << endl;

    return 0;
}
