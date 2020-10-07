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

    int iloscLat = 3;
    int iloscSprzedanychKsiazek[iloscLat][liczbaMiesiecy];
    int sumaZaWszsytkieLata = 0;
    int sumaZaJedenRok[iloscLat] = {0};

    for (int j = 0; j <iloscLat; j++)
    {
        cout << "Okres rozliczeniowy za rok nr " << j+1 << endl;
        for (int i = 0; i<liczbaMiesiecy; ++i)
        {
            cout << "Podaj sprzedaz za miesiac " << miesiace[i] << " : ";
            cin >> iloscSprzedanychKsiazek[j][i];
            sumaZaJedenRok[j] += iloscSprzedanychKsiazek[j][i];
        }
    sumaZaWszsytkieLata += sumaZaJedenRok[j];
    }

    for (int j = 0; j <iloscLat; j++)
    {
    cout << "Roczna sprzedaz ksiazek za rok nr " << j+1 << " wyniosla " << sumaZaJedenRok[j] << " ksiazek" << endl;
    }

    cout << "Laczna ilosc sprzedancyh ksiazek wyniosla " << sumaZaWszsytkieLata << " ksiazek" << endl;

    return 0;
}
