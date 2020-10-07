#include <iostream>

using namespace std;

const int liczbaWynikow = 3;

void wprowadzWyniki(double wynikiGolfowe[], int liczbaWynikow);
void wyswietlWyniki(double wynikiGolfowe[], int liczbaWynikow);
void wyswietlSredniaWynikow(double wynikiGolfowe[], int liczbaWynikow);

int main()
{
    cout << "Podaj swoje wyniki golfowe" << endl
        << "Program zakonczy sie po podaniu " << liczbaWynikow << " wynikow "
        << "lub po podaniu wartosci ujemnej" << endl;

    double wynikiGolfowe[liczbaWynikow];

    wprowadzWyniki(wynikiGolfowe, liczbaWynikow);
    wyswietlWyniki(wynikiGolfowe, liczbaWynikow);
    wyswietlSredniaWynikow(wynikiGolfowe, liczbaWynikow);

    cout << "\nKoniec programu" << endl;
    return 0;
}


void wprowadzWyniki(double wynikiGolfowe[], int liczbaWynikow)
{
    int i = 0;
    double temp;
    cout << "Podaj wartosc nr 1: ";
    cin >> temp;

    while(i < liczbaWynikow && temp >=0)
    {
        wynikiGolfowe[i] = temp;
        ++i;

        if( i < liczbaWynikow) // zabezpieczenie zeby nie pobralo o jednej liczby za duzo
        {
            cout << "Podaj wartosc nr " << i+1 << ": ";
            cin >> temp;
        }
    }
}

void wyswietlWyniki(double wynikiGolfowe[], int liczbaWynikow)
{
    int i = 0;
    cout << "Twoje wyniki: ";
    while(i < liczbaWynikow && wynikiGolfowe[i] >=0)
    {
        cout << wynikiGolfowe[i] << " ";
        ++i;
    }
    cout << endl;
}

void wyswietlSredniaWynikow(double wynikiGolfowe[], int liczbaWynikow)
{
    double suma = 0;
    double srednia = 0;
    int i = 0;
    while(i < liczbaWynikow && wynikiGolfowe[i] >=0)
    {
        suma += wynikiGolfowe[i];
        ++i;
    }

    cout << "Suma wynosi: " << suma
        << "\na srednia wynosi: " << suma/i << endl;
}
