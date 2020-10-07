#include <iostream>

using namespace std;

int main()
{

    cout << "Podaj liczbe: ";
    int liczba;
    cin >> liczba;

    int suma = 0;
    while (liczba != 0)
    {
        suma += liczba;
        cout << "Aktualna wartosc wszsytkich podanych liczb: " << suma << endl;
        cout << "Podaj nowa liczbe: ";
        cin >> liczba;
    }

    cout << "wartosc wszsytkich podanych liczb: " << suma << endl;

    return 0;
}
