#include <iostream>

using namespace std;

struct pudlo
{
    char producent[40];
    float wysokosc;
    float szerokosc;
    float dlugosc;
    float objetosc;
};

void wyswietlPudlo(pudlo box);
void obliczObjetoscPudlaValue(pudlo box);
void obliczObjetoscPudlaPointer(pudlo * box);


int main()
{
    pudlo karton = {"Hohland", 10, 20, 5};

    cout << "Oto twoj karton bez objetosci" << endl;
    wyswietlPudlo(karton);
    cout << "\nPrzekazuje karton do funkcji obliczajacej objetosc przez wartosc " << endl;
    obliczObjetoscPudlaValue(karton);
    wyswietlPudlo(karton);

    cout << "\nNiestety objetosc sie nie zapamietala !!! :( \n"
        <<  "Karton trzeba przekazac przez wskaznik (podac adres struktury)" << endl
        << "Przekazuje karton do funkcji obliczajacej objetosc przez adres " << endl;
    obliczObjetoscPudlaPointer(&karton);
    wyswietlPudlo(karton);
    cout << "\nKarton wreszcie ma objetosc :)" << endl;


    cout << "\nKoniec programu" << endl;
    return 0;
}


void wyswietlPudlo(const pudlo box)
{
    cout << "Producent: " << box.producent << endl
        << "wysokosc: " << box.wysokosc << endl
        << "szerokosc: " << box.szerokosc << endl
        << "dlugosc: " << box.dlugosc << endl
        << "objetosc: " << box.objetosc << endl;
}

void obliczObjetoscPudlaValue(pudlo box)  // przekazanie struktury przez wartosc. Nie zmienia wartosci oryginalu
{
    box.objetosc = box.wysokosc * box.szerokosc * box.dlugosc;
    cout << "Objetosc kartonu w funkcji przekazanej przez wartosc: " << box.objetosc << endl;
}


void obliczObjetoscPudlaPointer(pudlo * box)  // przekazanie adresu struktury (czyli za pomoca wskaznika). Zmienia wartosc oryginalu
{
    box->objetosc = box->wysokosc * box->szerokosc * box->dlugosc;
}
