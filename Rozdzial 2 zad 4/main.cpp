#include <iostream>

using namespace std;

const int dzien = 24; // godzin
const int godzina = 60; // minut
const int minuta = 60; // sekund

void przeliczSekundy (long long int);

int main()
{
    cout << "Podaj liczbe sekund: " << endl;
    long long int czasWSekundach;
    cin >> czasWSekundach;
    przeliczSekundy(czasWSekundach);

    return 0;
}

void przeliczSekundy (long long int czasWSekundach)
{
    int iloscDni = czasWSekundach /(dzien*godzina*minuta);
    int temp = czasWSekundach % (dzien*godzina*minuta);
    int iloscGodzin = temp /(godzina*minuta);
    temp = temp % (godzina*minuta);
    int iloscMinut = temp / minuta;
    int iloscSekund = temp % minuta;

    cout << czasWSekundach << " = " << iloscDni << " dni, " << iloscGodzin << " godzin, "
        << iloscMinut << " minut, " << iloscSekund << " sekund.\n";
}
