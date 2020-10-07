#include <iostream>
#include <string>

using namespace std;

const int liczbaMiesiecy = 12;

int main()
{
    const string miesiace[liczbaMiesiecy] =
    {
        "styczen",
        "luty",
        "marzec",
        "kwiecien",
        "maj",
        "czerwiec",
        "lipiec",
        "sierpien",
        "wrzesien",
        "pazdziernik",
        "listopad",
        "grudzien"
    };

    int iloscSprzedanychKsiazek[liczbaMiesiecy];
    int suma = 0;

    for (int i = 0; i<liczbaMiesiecy; ++i)
    {
        cout << "Podaj sprzedaz za miesiac " << miesiace[i] << " : ";
        cin >> iloscSprzedanychKsiazek[i];
        suma += iloscSprzedanychKsiazek[i];
    }

    cout << "Roczna sprzedaz wyniosla " << suma << " ksiazek" << endl;

    return 0;
}
